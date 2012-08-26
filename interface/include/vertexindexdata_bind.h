/******************************************************************************
 * vertexindexdata_bind.h -bindings for Ogre::VertexData and Ogre::IndexData
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

#pragma once
#ifndef VERTEXINDEXDATA_BIND_H
#define VERTEXINDEXDATA_BIND_H

#include "ogre_interface.h"
#define VertexDataHandle void*
#define IndexDataHandle void*

//TODO: VertexData(HardwareBufferManagerBase* mgr = 0);
//TODO: VertexData(VertexDeclaration* dcl, VertexBufferBinding* bind);
//~VertexData();
DLL void destroy_vertexdata(VertexDataHandle handle);
//(see OgreHardwareVertexBuffer.h): VertexDeclaration* vertexDeclaration;
//(see OgreHardwareVertexBuffer.h) VertexBufferBinding* vertexBufferBinding;
//size_t vertexStart;
DLL size_t vertexdata_vertex_start(VertexDataHandle handle); // getter
//size_t vertexCount;
DLL size_t vertexdata_vertex_count(VertexDataHandle handle); // getter
//typedef vector<HardwareAnimationData>::type HardwareAnimationDataList;
//HardwareAnimationDataList hwAnimationDataList;
//size_t hwAnimDataItemsUsed;
DLL size_t vertexdata_hw_anim_data_items_used(VertexDataHandle handle);
//VertexData* clone(bool copyData = true, HardwareBufferManagerBase* mgr = 0) const;
DLL VertexDataHandle vertexdata_clone(const VertexDataHandle handle, int copy_data);
//void prepareForShadowVolume(void);
DLL void vertexdata_prepare_for_shadow_volume(VertexDataHandle handle);
//HardwareVertexBufferSharedPtr hardwareShadowVolWBuffer;
//TODO: void reorganiseBuffers(VertexDeclaration* newDeclaration, const BufferUsageList& bufferUsage, HardwareBufferManagerBase* mgr = 0);
//TODO: void reorganiseBuffers(VertexDeclaration* newDeclaration, HardwareBufferManagerBase* mgr = 0);
//void closeGapsInBindings(void);
DLL void vertexdata_close_gaps_in_bindings(VertexDataHandle handle);
//void removeUnusedBuffers(void);
DLL void vertexdata_remove_unused_buffers(VertexDataHandle handle);
//TODO:void convertPackedColour(VertexElementType srcType, VertexElementType destType);
//ushort allocateHardwareAnimationElements(ushort count, bool animateNormals);
DLL unsigned short vertexdata_allocate_hardware_animation_elements(VertexDataHandle handle, unsigned short count, int animate_normals);


#endif
