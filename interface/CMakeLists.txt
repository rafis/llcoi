cmake_minimum_required(VERSION 2.8)

# project name
project(llcoi)

#################
#### COMPILE ####
#################
set(LLCOI_HEADER_FILES
  ./include/axisalignedbox_bind.h
  ./include/binding_utils.h
  ./include/bone_bind.h
  ./include/camera_bind.h
  ./include/colourvalue_bind.h
  ./include/configfile_bind.h
  ./include/entity_bind.h
  ./include/framelistener_bind.h
  ./include/fwd.h
  ./include/inputmanager_bind.h
  ./include/keyboard_bind.h
  ./include/light_bind.h
  ./include/llcoi.h
  ./include/log_bind.h
  ./include/logmanager_bind.h
  ./include/main.h
  ./include/manualobject_bind.h
  ./include/material_bind.h
  ./include/materialmanager_bind.h
  ./include/meshmanager_bind.h
  ./include/mouse_bind.h
  ./include/movableobject_bind.h
  ./include/node_bind.h
  ./include/ogre_interface.h
  ./include/ois_interface.h
  ./include/overlay_bind.h
  ./include/overlaycontainer_bind.h
  ./include/overlayelement_bind.h
  ./include/overlayelementfactory_bind.h
  ./include/overlaymanager_bind.h
  ./include/paneloverlayelement_bind.h
  ./include/pass_bind.h
  ./include/plane_bind.h
  ./include/planeboundedvolume_bind.h
  ./include/ray_bind.h
  ./include/renderoperation_bind.h
  ./include/rendersystem_bind.h
  ./include/renderwindow_bind.h
  ./include/resource_bind.h
  ./include/resourcegroupmanager_bind.h
  ./include/resourcemanager_bind.h
  ./include/root_bind.h
  ./include/scenemanager_bind.h
  ./include/scenenode_bind.h
  ./include/scenequery_bind.h
  ./include/skeleton_bind.h
  ./include/skeletoninstance_bind.h
  ./include/sphere_bind.h
  ./include/tagpoint_bind.h
  ./include/technique_bind.h
  ./include/textareaoverlayelement_bind.h
  ./include/texturemanager_bind.h
  ./include/timer_bind.h
  ./include/vector3_bind.h
  ./include/vertexindexdata_bind.h
  ./include/viewport_bind.h
  ./include/windoweventlistener_bind.h
)

set(LLCOI_SOURCE_FILES
  ./source/axisalignedbox_bind.cpp
  ./source/binding_utils.cpp
  ./source/bone_bind.cpp
  ./source/camera_bind.cpp
  ./source/colourvalue_bind.cpp
  ./source/configfile_bind.cpp
  ./source/entity_bind.cpp
  ./source/framelistener_bind.cpp
  ./source/inputmanager_bind.cpp
  ./source/keyboard_bind.cpp
  ./source/light_bind.cpp
  ./source/log_bind.cpp
  ./source/logmanager_bind.cpp
  ./source/main.cpp
  ./source/manualobject_bind.cpp
  ./source/material_bind.cpp
  ./source/materialmanager_bind.cpp
  ./source/meshmanager_bind.cpp
  ./source/mouse_bind.cpp
  ./source/movableobject_bind.cpp
  ./source/node_bind.cpp
  ./source/overlay_bind.cpp
  ./source/overlaycontainer_bind.cpp
  ./source/overlayelement_bind.cpp
  ./source/overlayelementfactory_bind.cpp
  ./source/overlaymanager_bind.cpp
  ./source/paneloverlayelement_bind.cpp
  ./source/pass_bind.cpp
  ./source/plane_bind.cpp
  ./source/planeboundedvolume_bind.cpp
  ./source/ray_bind.cpp
  ./source/renderoperation_bind.cpp
  ./source/rendersystem_bind.cpp
  ./source/renderwindow_bind.cpp
  ./source/resource_bind.cpp
  ./source/resourcegroupmanager_bind.cpp
  ./source/resourcemanager_bind.cpp
  ./source/root_bind.cpp
  ./source/scenemanager_bind.cpp
  ./source/scenenode_bind.cpp
  ./source/scenequery_bind.cpp
  ./source/skeleton_bind.cpp
  ./source/skeletoninstance_bind.cpp
  ./source/sphere_bind.cpp
  ./source/tagpoint_bind.cpp
  ./source/technique_bind.cpp
  ./source/textareaoverlayelement_bind.cpp
  ./source/texturemanager_bind.cpp
  ./source/timer_bind.cpp
  ./source/vector3_bind.cpp
  ./source/vertexindexdata_bind.cpp
  ./source/viewport_bind.cpp
  ./source/windoweventlistener_bind.cpp
  )


include_directories(${OGRE_INCLUDE_DIRS} ${OIS_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/interface/include")
add_definitions(-Dllcoi_EXPORTS)
add_library(llcoi SHARED ${LLCOI_HEADER_FILES} ${LLCOI_SOURCE_FILES})

set_target_properties(llcoi PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(llcoi PROPERTIES OUTPUT_NAME "llcoi" VERSION 0.1 SOVERSION 0.1)

target_link_libraries(llcoi ${OGRE_LIBRARIES} ${OGRE_Overlay_LIBRARIES} ${OIS_LIBRARIES})

install(TARGETS llcoi
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
FILE (GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/interface/include/*.h")
install ( FILES ${files} DESTINATION include/llcoi)
