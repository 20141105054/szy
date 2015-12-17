
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_idc, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_calculate, &CcalculatorDlg::OnBnClickedcalculate)
	ON_BN_CLICKED(IDC_Clear, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_jian, &CcalculatorDlg::OnBnClickedjian)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_cheng, &CcalculatorDlg::OnBnClickedcheng)
	ON_BN_CLICKED(IDC_chu, &CcalculatorDlg::OnBnClickedchu)
	ON_BN_CLICKED(IDC_mo, &CcalculatorDlg::OnBnClickedmo)
	ON_BN_CLICKED(IDC_pingfang, &CcalculatorDlg::OnBnClickedpingfang)
	ON_BN_CLICKED(IDC_genhao, &CcalculatorDlg::OnBnClickedgenhao)
//	ON_BN_CLICKED(IDC_jian2, &CcalculatorDlg::OnBnClickedjian2)
	ON_BN_CLICKED(IDC_fuhao, &CcalculatorDlg::OnBnClickedfuhao)
	ON_BN_CLICKED(IDC_chexiao, &CcalculatorDlg::OnBnClickedchexiao)
	ON_BN_CLICKED(IDC_m1, &CcalculatorDlg::OnBnClickedm1)
	ON_BN_CLICKED(IDC_m2, &CcalculatorDlg::OnBnClickedm2)
	ON_BN_CLICKED(IDC_m3, &CcalculatorDlg::OnBnClickedm3)
	ON_BN_CLICKED(IDC_about, &CcalculatorDlg::OnBnClickedabout)
	ON_BN_CLICKED(IDC_xfen1, &CcalculatorDlg::OnBnClickedxfen1)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);



}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	   m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedcalculate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE(L"flag=%d\n",flag);
	UpdateData(true);
	/*while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);*/
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
	}
	if(flag==4)
	{
		temp=temp/_ttof(m_str);
	}
	if(flag==5)
	{
		temp=temp/100;

	}

	m_str.Format(L"%lf",temp);
	if(temp/_ttof(m_str))
		printf("error");
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_str="";
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedjian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedcheng()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedchu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedmo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=5;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	//UpdateData(false);
}


void CcalculatorDlg::OnBnClickedpingfang()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=6;
	UpdateData(true);
	TRACE(L"flag=%d\n",flag);
	temp=_ttof(m_str);
	m_str="";
	temp=temp*temp;
	check(m_str);
	/*m_str.Format(L"%lf",temp);
	if(temp/_ttof(m_str))
		printf("error");
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);*/
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedgenhao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=7;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	temp=sqrt(temp);
	check(m_str);
	/*m_str.Format(L"%lf",temp);
	if(temp/_ttof(m_str))
		printf("error");
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);*/
	UpdateData(false);
}




void CcalculatorDlg::OnBnClickedfuhao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=8;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	temp=0-temp;
	check(m_str);
	/*m_str.Format(L"%lf",temp);
	if(temp/_ttof(m_str))
		printf("error");
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);*/
	UpdateData(false);

}
void CcalculatorDlg::check(CString &ts)
{
	m_str.Format(L"%lf",temp);//m_str.Format(��ʽ����ַ���������б�)
	if(temp/_ttof(m_str))
		printf("error");
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);


}



void CcalculatorDlg::OnBnClickedchexiao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!m_str.IsEmpty())
	{
		m_str=m_str.Left(m_str.GetLength()-1);
	}
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedm1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=9;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	temp1=temp;
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedm2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=10;
	//UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	temp2=0-temp;
	/*temp=temp1+temp2;
	UpdateData(false);*/


}


void CcalculatorDlg::OnBnClickedm3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=11;
	UpdateData(true);
	temp=temp1+temp2;
	check(m_str);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedabout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg dlg;
	dlg.DoModal();
}


void CcalculatorDlg::OnBnClickedxfen1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=12;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	temp=1/temp;
	check(m_str);
	UpdateData(false);
}
