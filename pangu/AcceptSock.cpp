// AcceptSock.cpp : implementation file
//

#include "stdafx.h"
#include "ÅÌ¹Å.h"
#include "AcceptSock.h"
#include "ÅÌ¹ÅDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcceptSock

CAcceptSock::CAcceptSock()
{
}

CAcceptSock::~CAcceptSock()
{
}
CAcceptSock::CAcceptSock(CMyDlg *dlg)
{
	m_dlg = dlg;
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CAcceptSock, CSocket)
	//{{AFX_MSG_MAP(CAcceptSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CAcceptSock member functions

void CAcceptSock::OnAccept(int nErrorCode) 
{
	if (!m_dlg)
		return;
	m_dlg->AcceptPending(this);
	CSocket::OnAccept(nErrorCode);
}
