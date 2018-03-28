// ClientSock.cpp : implementation file
//

#include "stdafx.h"
#include "ÅÌ¹Å.h"
#include "ClientSock.h"
#include "ÅÌ¹ÅDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSock

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSock, CSocket)
	//{{AFX_MSG_MAP(CClientSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSock member functions

void CClientSock::SetBaseDlg(CMyDlg *dlg)
{
	m_dlg = dlg;
}

void CClientSock::OnClose(int nErrorCode) 
{	
	CSocket::OnClose(nErrorCode);
	if (!m_dlg)
		return;
	m_dlg->DeleteHost(index);
}

void CClientSock::OnReceive(int nErrorCode) 
{	
	CSocket::OnReceive(nErrorCode);
	if (!m_dlg)
		return;

	char buf[4096];
	memset(buf,0,4096);
	int m_nLength;
	m_nLength=Receive(buf,4096,0);

	if (strncmp(buf,"VERSONEX:",9) == 0)
	{
		CString str;
		UINT port;
		GetPeerName(str,port);

		char cpu[128],mem[10],ver[10];
		memset(cpu,0,128);
		memset(mem,0,10);
		memset(ver,0,10);

		CString strLine = buf;

		strLine.Delete(0,strLine.Find(":")+1);
		strcpy(ver,strLine.Left(strLine.Find("|")));

		strLine.Delete(0,strLine.Find("|")+1);
		strcpy(mem,strLine.Left(strLine.Find("|")));

		strLine.Delete(0,strLine.Find("|")+1);
		strcpy(cpu,strLine);

		m_dlg->AddHost(index,atoi(ver),str.GetBuffer(0),mem,cpu);

		return;
	}
	if (strcmp(buf,"OK") == 0)
	{
		m_dlg->CommandOK(index);
	}
}
