/* FragExt - Shell extension for providing file fragmentation
 * information.
 *
 * Copyright (C) 2004-2009 Jeremy Boschen. All rights reserved.
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

/* Common.h
 *    Shared routines and data declarations
 *
 * Copyright (C) 2004-2009 Jeremy Boschen
 *
 * Version History
 *    0.0.001 - 06/13/2005 - Created
 */

#pragma once

#include <FragEng.h>

/**********************************************************************

   CFragReport

 **********************************************************************/
#define FILESIGNATURE_CP1200      "\xFF\xFE"
#define FILESIGNATURE_CP1200_SIZE 2

class CFragReport
{
public:
   enum
   {
      WriteModeFile,
      WriteModeClipboard
   };

   CFragReport( ) throw();
   
#ifdef _DEBUG
   ~CFragReport( ) throw()
   {
      ATLASSERT(INVALID_HANDLE_VALUE == _hFile);
   }
#endif

   HRESULT OpenReport( int eMode, HWND hWnd ) throw();
   void CloseReport( ) throw();

   HRESULT AppendFile( LPCWSTR FileName, HANDLE hFragCtx ) throw();
   HRESULT CopyToClipboard( HWND hWnd ) throw();
   
private:
   HRESULT _WriteReportHeadInfo( LPCWSTR FileName, HANDLE hFragCtx ) throw();
   HRESULT _WriteReportFragInfo( HANDLE hFragCtx ) throw();
   
   HRESULT _WriteToReportFile( LPCWSTR pwszBuf, size_t cchWrite, LPDWORD pdwWritten ) throw();
   HRESULT __cdecl _WriteToReportFilef( LPCWSTR pwszFormat, ... ) throw();
   
   HANDLE _hFile;
};
