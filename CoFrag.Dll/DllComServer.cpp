/*	FragExt - Shell extension for providing file fragmentation
 *	information.
 *
 * Copyright (C) 2004-2005 Jeremy Boschen. All rights reserved.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software. 
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software in
 * a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not
 * be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */

/*	DllComServer.cpp
 *	   Implementation of COM DLL exports.
 *
 *	Copyright (C) 2004-2009 Jeremy Boschen
 *
 *	Version History
 *		0.0.001 - 07/13/2004 - Created
 */

#include "Stdafx.h"

/**
 *	DllCanUnloadNow
 *    Standard COM export function.
 */
STDAPI DllCanUnloadNow( )
{
   return ( _AtlModule.DllCanUnloadNow() );
}

/**
 *	DllGetClassObject
 *    Standard COM export function.
 */
STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID* ppv )
{
   return ( _AtlModule.DllGetClassObject(rclsid, riid, ppv) );
}
