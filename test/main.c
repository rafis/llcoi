#include <llcoi.h>

#undef LLCOI_TEST_USE_OPENINPUT

#if defined(LLCOI_TEST_USE_OPENINPUT)
//#   include <openinput.h>
#endif

#if defined(LLCOI_TEST_USE_ALLEGRO)
#   include <allegro.h>
#endif

#include <math.h>
#include <stdio.h>

#if defined( WIN32 ) || defined( _WINDOWS )
#   define WIN32_LEAN_AND_MEAN
#   include "windows.h"
#else
#if defined(LLCOI_TEST_USE_OPENINPUT)
//#include <X11/Xlib.h>
#endif
#endif

CameraHandle myCamera;
KeyboardInputHandle keyboard;
MouseInputHandle mouse;
float tiny_timer=0;

void window_event_listener_test(RenderWindowHandle window_handle)
{
	log_message("I was called when the window closed!");
}

int frame_listener_test(float evt_time,float frame_time,int event_type)
{
    tiny_timer+=frame_time;
    camera_set_position(myCamera,cosf(tiny_timer)*100,50,sinf(tiny_timer)*100);
    camera_lookat(myCamera,0,0,0);
    return 1;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR strCmdLine, INT nCmdShow)
#else
int main(int argc, char *argv[])
#endif
{
    /* C90 requires all vars to be declared at top of function */

    EntityHandle entity;
    SceneNodeHandle node;
    LightHandle light;
    //RenderSystemHandle rendersystem;
    RenderWindowHandle renderwindow;
    ViewportHandle viewport;

#if defined(LLCOI_TEST_USE_OPENINPUT)
    // Openinput
    oi_event evt;
    char openinput_window_params[100];
    unsigned int windowHnd = 0;

#if defined(PLATFORM_LINUX)
    Display *disp;
    Window win;
    unsigned int scrn;
#endif
#endif //LLCOI_TEST_USE_OPENINPUT
    
    int keep_going = 1;

    RootHandle root = create_root("plugins.cfg", "ogre.cfg", "ogre.log");

    if (!(restore_config(root) || show_config_dialog(root)))
    {
        return 1;
    }

    resourcegroupmanager_setup_resources("resources.cfg");

    renderwindow = root_initialise(root, 1, "Ogre Renderwindow");

    set_default_num_mipmaps(5);

    resourcegroupmanager_initialise_all_resourcegroups(resourcegroupmanager_singleton());

    SceneManagerHandle scene_manager = create_scene_manager(root, "OctreeSceneManager", "The SceneManager");

    myCamera = scenemanager_create_camera(scene_manager, "mycam");

    camera_set_position(myCamera, 0, 0, 80);

    camera_lookat(myCamera, 0, 0, -300);

    camera_set_near_clip_distance(myCamera, 5);

    viewport = render_window_add_viewport(renderwindow, myCamera, 0, 0, 0, 1, 1);

    viewport_set_background_colour(viewport, 0, 0, 0, 1);

    camera_set_aspect_ratio(myCamera, 800, 600);

    entity = scenemanager_create_entity(scene_manager, "OgreHead", "ogrehead.mesh", 0);

    node = create_child_of_root_scenenode(scene_manager, "headNode");

    scenenode_attach_entity(node, entity);

    scenemanager_set_ambient_light_rgba(scene_manager, 0.5f, 0.5f, 0.5f, 1.0f);

    light = scenemanager_create_light(scene_manager, "mainLight");

    light_set_position(light, 20, 80, 50);

    add_frame_listener(root, frame_listener_test, EVENT_FRAME_RENDERING_QUEUED|EVENT_FRAME_STARTED);

	add_window_listener(renderwindow, window_event_listener_test);

    InputManagerHandle input_system = create_input_system(render_window_get_hwnd(renderwindow));
    keyboard = create_keyboard_object(input_system, 0);
    mouse = create_mouse_object(input_system, 0);
    
    while(keep_going)
    {
        keyboard_capture(keyboard);
        mouse_capture(mouse);

        if(keyboard_is_key_down(keyboard, KC_ESCAPE))
            keep_going = 0;
        
        // Pump window messages for nice behaviour
        pump_messages();
        // Render a frame
        render_one_frame(root);

        if (render_window_closed(renderwindow))
        {
            keep_going = 0;
        }
        
    }
    
#if defined(LLCOI_TEST_USE_OPENINPUT)
    windowHnd = render_window_get_hwnd(renderwindow);

#if defined(PLATFORM_LINUX)
    disp = XOpenDisplay( NULL );
    scrn = DefaultScreen(disp);
    sprintf(openinput_window_params, "c:%u s:%u w:%u", (unsigned int)disp, (unsigned int)scrn, windowHnd);
#else
    sprintf(openinput_window_params, "c:%u s:%u w:%u", 0, 0, windowHnd);
#endif
    
    oi_init(openinput_window_params, 0);
    
    log_message("***************************");
    log_message("*** All Systems online! ***");
    log_message("***************************");
    
    //render_loop();
    while (keep_going)
    {
        // ask oi to wait for events
        oi_events_poll(&evt);
        switch(evt.type)
        {
            case OI_QUIT:
                // Quit
                keep_going = 0;
                break;

            case OI_KEYDOWN:
                // Keyboard button down
                //WTF?? Better way to check this, please..
                if(evt.key.keysym.sym == OIK_ESC)
                    keep_going = 0;
                break;

            default:
                break;
        }
        // Pump window messages for nice behaviour
        pump_messages();
        // Render a frame
        render_one_frame();

        if (render_window_closed())
        {
            keep_going = 0;
        }
    }

    oi_close();
#endif //LLCOI_TEST_USE_OPENINPUT
    
	remove_window_listener(renderwindow);

    destroy_keyboard_object(input_system, keyboard);
    destroy_mouse_object(input_system, mouse);
    destroy_input_system(input_system);
    release_engine(root);

    return 0;
}
