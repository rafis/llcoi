/******************************************************************************
 * vertexindexdata_bind.cpp - bindings for Ogre::VertexData and Ogre::IndexData
 ******************************************************************************
 * This file is part of
 *     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 *                          
 * Low Level C Ogre Interface (llcoi)
 *
 * See http://code.google.com/p/llcoi/ for more information.
 *
 * Copyright (c) 2011, Llcoi Team
 * 
 * License: MIT
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#include "vertexindexdata_bind.h"
#include <OgreVertexIndexData.h>

//TODO: VertexData(HardwareBufferManagerBase* mgr = 0);
//TODO: VertexData(VertexDeclaration* dcl, VertexBufferBinding* bind);
//~VertexData();
void destroy_vertexdata(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    delete vdata;
}

//(see OgreHardwareVertexBuffer.h): VertexDeclaration* vertexDeclaration;
//(see OgreHardwareVertexBuffer.h) VertexBufferBinding* vertexBufferBinding;
//size_t vertexStart;
size_t vertexdata_vertex_start(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle); 
    return vdata->vertexStart;
}

//size_t vertexCount;
size_t vertexdata_vertex_count(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    return vdata->vertexCount;
}

//typedef vector<HardwareAnimationData>::type HardwareAnimationDataList;
//HardwareAnimationDataList hwAnimationDataList;
//size_t hwAnimDataItemsUsed;
size_t vertexdata_hw_anim_data_items_used(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    return vdata->hwAnimDataItemsUsed;
}

//VertexData* clone(bool copyData = true, HardwareBufferManagerBase* mgr = 0) const;
//FIXME: return to this once HardwareBufferManagerBase is wrapped.
VertexDataHandle vertexdata_clone(const VertexDataHandle handle, int copy_data)
{
    const Ogre::VertexData* vdata = static_cast<const Ogre::VertexData*>(handle);
    Ogre::VertexData* cloned = vdata->clone(copy_data);
    return static_cast<VertexDataHandle>(cloned);
}

//void prepareForShadowVolume(void);
void vertexdata_prepare_for_shadow_volume(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    vdata->prepareForShadowVolume();
}

//HardwareVertexBufferSharedPtr hardwareShadowVolWBuffer;
//TODO: void reorganiseBuffers(VertexDeclaration* newDeclaration, const BufferUsageList& bufferUsage, HardwareBufferManagerBase* mgr = 0);
//TODO: void reorganiseBuffers(VertexDeclaration* newDeclaration, HardwareBufferManagerBase* mgr = 0);
//void closeGapsInBindings(void);
void vertexdata_close_gaps_in_bindings(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    vdata->closeGapsInBindings();
}

//void removeUnusedBuffers(void);
void vertexdata_remove_unused_buffers(VertexDataHandle handle)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    vdata->removeUnusedBuffers();
}

//TODO:void convertPackedColour(VertexElementType srcType, VertexElementType destType);
//ushort allocateHardwareAnimationElements(ushort count, bool animateNormals);
unsigned short vertexdata_allocate_hardware_animation_elements(VertexDataHandle handle, unsigned short count, int animate_normals)
{
    Ogre::VertexData* vdata = static_cast<Ogre::VertexData*>(handle);
    return vdata->allocateHardwareAnimationElements(count, animate_normals);
}

