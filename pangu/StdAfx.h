// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__25B67E70_268A_4DCD_8FC8_E711973061AA__INCLUDED_)
#define AFX_STDAFX_H__25B67E70_268A_4DCD_8FC8_E711973061AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <winsock2.h>
#include <ws2tcpip.h> 
#pragma comment(lib,"ws2_32.lib")
#include <afxsock.h>		// MFC socket extensions
#include "HoverEdit.h"
#include "WinXPButtonSt.h"
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__25B67E70_268A_4DCD_8FC8_E711973061AA__INCLUDED_)
