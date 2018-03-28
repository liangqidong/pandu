#if !defined(AFX_ACCEPTSOCK_H__477FE121_64BE_4FF9_84C4_8463B755B524__INCLUDED_)
#define AFX_ACCEPTSOCK_H__477FE121_64BE_4FF9_84C4_8463B755B524__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcceptSock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAcceptSock command target
class CMyDlg;

class CAcceptSock : public CSocket
{
// Attributes
public:
	CMyDlg *m_dlg;
// Operations
public:
	CAcceptSock();
	CAcceptSock(CMyDlg *dlg);
	virtual ~CAcceptSock();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcceptSock)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CAcceptSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCEPTSOCK_H__477FE121_64BE_4FF9_84C4_8463B755B524__INCLUDED_)
