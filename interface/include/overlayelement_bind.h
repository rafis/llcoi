/******************************************************************************
 * overlayelement_bind.h -  bindings for Ogre::OverlayElement
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
#ifndef OVERLAYELEMENT_BIND_H
#define OVERLAYELEMENT_BIND_H

#include "ogre_interface.h"
#define OverlayElementHandle void*

//overlayelement_
//~OverlayElement
DLL void destroy_overlayelement(OverlayElementHandle handle);
//void initialise(void)
DLL void overlayelement_initialise(OverlayElementHandle handle);
//const String& getName(void) const;
DLL const char* overlayelement_get_name(OverlayElementHandle handle);
//void show(void);
DLL void overlayelement_show(OverlayElementHandle handle);
//void hide(void);
DLL void overlayelement_hide(OverlayElementHandle handle);
//bool isVisible(void) const;
DLL int overlayelement_is_visible(OverlayElementHandle handle);
//bool isEnabled() const;
DLL int overlayelement_is_enabled(OverlayElementHandle handle);
//void setEnabled(bool b);
DLL void overlayelement_set_enabled(OverlayElementHandle handle, int b);
//void setDimensions(Real width, Real height);
DLL void overlayelement_set_dimensions(OverlayElementHandle handle, coiReal width, coiReal height);
//void setPosition(Real left, Real top);
DLL void overlayelement_set_position(OverlayElementHandle handle, coiReal left, coiReal top);
//void setWidth(Real width);
DLL void overlayelement_set_width(OverlayElementHandle handle, coiReal width);
//Real getWidth(void) const;
DLL coiReal overlayelement_get_width(OverlayElementHandle handle);
//void setHeight(Real height);
DLL void overlayelement_set_height(OverlayElementHandle handle, coiReal height);
//Real getHeight(void) const;
DLL coiReal overlayelement_get_height(OverlayElementHandle handle);
//void setLeft(Real left);
DLL void overlayelement_set_left(OverlayElementHandle handle, coiReal left);
//Real getLeft(void) const;
DLL coiReal overlayelement_get_left(OverlayElementHandle handle);
//void setTop(Real Top);
DLL void overlayelement_set_top(OverlayElementHandle handle, coiReal top);
//Real getTop(void) const;
DLL coiReal overlayelement_get_top(OverlayElementHandle handle);
//Real _getLeft(void) const;
DLL coiReal overlayelement__get_left(OverlayElementHandle handle);
//Real _getTop(void) const;
DLL coiReal overlayelement__get_top(OverlayElementHandle handle);
//Real _getWidth(void) const;
DLL coiReal overlayelement__get_width(OverlayElementHandle handle);
//Real _getHeight(void) const;
DLL coiReal overlayelement__get_height(OverlayElementHandle handle);
//void _setLeft(Real left);
DLL void overlayelement__set_left(OverlayElementHandle handle, coiReal left);
//void _setTop(Real top);
DLL void overlayelement__set_top(OverlayElementHandle handle, coiReal top);
//void _setWidth(Real width);
DLL void overlayelement__set_width(OverlayElementHandle handle, coiReal width);
//void _setHeight(Real height);
DLL void overlayelement__set_height(OverlayElementHandle handle, coiReal height);
//void _setPosition(Real left, Real top);
DLL void overlayelement__set_position(OverlayElementHandle handle, coiReal left, coiReal top);
//void _setDimensions(Real width, Real height);
DLL void overlayelement__set_dimensions(OverlayElementHandle handle, coiReal width, coiReal height);
//const String& getMaterialName(void) const;
DLL const char* overlayelement_get_material_name(OverlayElementHandle handle);
//void setMaterialName(const String& matName);
DLL void overlayelement_set_material_name(OverlayElementHandle handle, const char* name);
//TODO: const MaterialPtr& getMaterial(void) const;
//void getWorldTransforms(Matrix4* xform) const;
DLL void overlayelement_get_world_transforms(OverlayElementHandle handle, coiMatrix4* xform);
//void _positionsOutOfDate(void);
DLL void overlayelement__positions_out_of_date(OverlayElementHandle handle);
//void _update(void);
DLL void overlayelement__update(OverlayElementHandle handle);
//void _updateFromParent(void);
DLL void overlayelement__update_from_parent(OverlayElementHandle handle);
//TODO: void _notifyParent(OverlayContainer* parent, Overlay* overlay);
//DLL void overlayelement__notify_parent(OverlayElementHandle handle, OverlayContainerHandle parent_handle, OverlayHandle overlay_handle);
//Real _getDerivedLeft(void);
DLL coiReal overlayelement__get_derived_left(OverlayElementHandle handle);
//Real _getDerivedTop(void);
DLL coiReal overlayelement__get_derived_top(OverlayElementHandle handle);
//Real _getRelativeWidth(void);
DLL coiReal overlayelement__get_relative_width(OverlayElementHandle handle);
//Real _getRelativeHeight(void);
DLL coiReal overlayelement__get_relative_height(OverlayElementHandle handle);
//TODO: void _getClippingRegion(Rectangle &clippingRegion);
//ushort _notifyZOrder(ushort newZOrder);
DLL unsigned short overlayelement__notify_zorder(OverlayElementHandle handle, unsigned short new_zorder);
//void _notifyWorldTransforms(const Matrix4& xform);
DLL void overlayelement__notify_world_transforms(OverlayElementHandle handle, const coiMatrix4* xform);
//void _notifyViewport();
DLL void overlayelement__notify_viewport(OverlayElementHandle handle);

#endif
