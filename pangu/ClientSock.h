#if !defined(AFX_CLIENTSOCK_H__383A34AA_F1B6_4997_8CF7_9671997242F5__INCLUDED_)
#define AFX_CLIENTSOCK_H__383A34AA_F1B6_4997_8CF7_9671997242F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSock command target
class CMyDlg;
class CClientSock : public CSocket
{
// Attributes
public:

// Operations
public:
	int index;
	CMyDlg *m_dlg;
	CClientSock();
	virtual ~CClientSock();

// Overrides
public:
	void SetBaseDlg(CMyDlg *dlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSock)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCK_H__383A34AA_F1B6_4997_8CF7_9671997242F5__INCLUDED_)
