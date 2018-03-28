; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "≈Ãπ≈.h"

ClassCount=6
Class1=CMyApp
Class2=CMyDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Class3=CClientSock
Class4=CAcceptSock
Resource2=IDD_DIALOG_HELP
Class5=CHelpDlg
Resource3=IDD_MY_DIALOG
Class6=CFtpUpdate
Resource4=IDD_DIALOG_FTP

[CLS:CMyApp]
Type=0
HeaderFile=≈Ãπ≈.h
ImplementationFile=≈Ãπ≈.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=≈Ãπ≈Dlg.h
ImplementationFile=≈Ãπ≈Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CHECK_TCP



[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=52
Control1=IDC_EDIT_UPPORT,edit,1350631552
Control2=IDC_BUTTON_BEGINLIS,button,1342242816
Control3=IDC_EDIT_DOMAIN,edit,1350631552
Control4=IDC_BUTTON_MAKESERVER,button,1342242816
Control5=IDC_EDIT_TGTIP,edit,1350631552
Control6=IDC_EDIT_TGTPORT,edit,1350631552
Control7=IDC_BUTTON_FLOOD,button,1342242816
Control8=IDC_BUTTON_STOP,button,1342242816
Control9=IDC_EDIT_DOWNLOAD,edit,1350631552
Control10=IDC_BUTTON_DOWNLOAD,button,1342242816
Control11=IDC_BUTTON_UPDATEDATA,button,1342242816
Control12=IDC_LIST1,SysListView32,1350631681
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_BUTTON_REMOVE,button,1342242816
Control21=IDC_SHOW,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT_SVCNAME,edit,1350631552
Control24=IDC_EDIT_SVCDISP,edit,1350631552
Control25=IDC_EDIT_SVCDESC,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_BUTTON_HELP,button,1342242816
Control29=IDC_STATIC,static,1342308352
Control30=IDC_EDIT_TIMEOUT,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_CHECK_SYN,button,1342242819
Control33=IDC_CHECK_UDP,button,1342242819
Control34=IDC_CHECK_ICMP,button,1342242819
Control35=IDC_BUTTON_REFLASH,button,1342242816
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_UPHOST,static,1342308352
Control39=IDC_CHECK_ALLSEL,button,1342242819
Control40=IDC_BUTTON_TEST,button,1342242816
Control41=IDCANCEL,button,1073807360
Control42=IDC_CHECK_TCPBREAK,button,1342242819
Control43=IDC_CHECK_W2000,button,1342242819
Control44=IDC_CHECK_SP2,button,1342242819
Control45=IDC_STATIC,static,1342308352
Control46=IDC_STATIC,static,1342308352
Control47=IDC_EDIT_FINDIP,edit,1350631552
Control48=IDC_BUTTON_FINDIP,button,1342242816
Control49=IDC_CHECK_GET,button,1342242819
Control50=IDC_EDIT_GETOBJ,edit,1350631552
Control51=IDC_CHECK_COVER,button,1342242819
Control52=IDC_CHECK_TCP,button,1342242819

[CLS:CClientSock]
Type=0
HeaderFile=ClientSock.h
ImplementationFile=ClientSock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CAcceptSock]
Type=0
HeaderFile=AcceptSock.h
ImplementationFile=AcceptSock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[DLG:IDD_DIALOG_HELP]
Type=1
Class=CHelpDlg
ControlCount=1
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHelpDlg

[DLG:IDD_DIALOG_FTP]
Type=1
Class=CFtpUpdate
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_FTPSERVER,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_USER,edit,1350631552
Control10=IDC_EDIT_PWD,edit,1350631552
Control11=IDC_EDIT_IPFILE,edit,1350631552
Control12=IDC_EDIT_FTPPORT,edit,1350631552
Control13=IDC_EDIT_IP,edit,1350631552

[CLS:CFtpUpdate]
Type=0
HeaderFile=FtpUpdate.h
ImplementationFile=FtpUpdate.cpp
BaseClass=CDialog
Filter=D
LastObject=CFtpUpdate
VirtualFilter=dWC

