/*     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 * https://bitbucket.org/galaktor/llcoi 
 * copyright (c) 2011, llcoi Team
 * MIT license applies - see file "LICENSE" for details.
*/
#pragma once

#include "ogre_interface.h"

DLL ResourceGroupManagerHandle resourcegroupmanager_singleton();
//DLL ResourceGroupManagerHandle create_resourcegroupmanager();
//DLL void destroy_resourcegroupmanager(ResourceGroupManagerHandle handle);
DLL void resourcegroupmanager_setup_resources(const char* resources_cfg);
DLL void resourcegroupmanager_add_resource_location(ResourceGroupManagerHandle handle, const char* location, const char* type, const char* group);
DLL const char* resourcegroupmanager_DEFAULT_RESOURCE_GROUP_NAME();
DLL const char* resourcegroupmanager_INTERNAL_RESOURCE_GROUP_NAME();
DLL const char* resourcegroupmanager_AUTODETECT_RESOURCE_GROUP_NAME();
DLL size_t resourcegroupmanager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS();
DLL void resourcegroupmanager_initialise_all_resourcegroups(ResourceGroupManagerHandle handle);
