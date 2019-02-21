
// AnimaciaMovingObjectPoligonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnimaciaMovingObjectPoligon.h"
#include "AnimaciaMovingObjectPoligonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnimaciaMovingObjectPoligonDlg dialog



CAnimaciaMovingObjectPoligonDlg::CAnimaciaMovingObjectPoligonDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ANIMACIAMOVINGOBJECTPOLIGON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimaciaMovingObjectPoligonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAnimaciaMovingObjectPoligonDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CAnimaciaMovingObjectPoligonDlg message handlers

BOOL CAnimaciaMovingObjectPoligonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnimaciaMovingObjectPoligonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CClientDC dc(this);
		GetClientRect(&rc);

		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Times New Roman Cyr");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO

		int XA[360], YA[360];
		double xf, yf, f;

		int D = 350;
		int n = 60;
		f = 0;
		k = 0;

		dc.MoveTo(cx, cy + D / 2);

		while (k < n)
		{
			xf = D / 2 * cos(f);
			yf = D / 2 * sin(f);
			XA[k] = xf + cx;
			YA[k] = yf + cy;
			k++;
			f += (2 * PI / n);
		}


		dc.FillSolidRect(&rc, RGB(0, 0, 0));
		for (k = 0; k < n; k++)
		{
			cf = RGB(255, 221, 41);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);
			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			SelectObject(dc, brush);

			dc.MoveTo(XA[k], YA[k]);
			dc.Ellipse(XA[k], YA[k], XA[k] + 20, YA[k] + 20);

			dc.LineTo(cx, cy);
			Sleep(50);

			cf = RGB(0, 0, 0);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);

			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			SelectObject(dc, brush);

			dc.MoveTo(XA[k], YA[k]);
			dc.Ellipse(XA[k], YA[k], XA[k] + 20, YA[k] + 20);
			dc.LineTo(cx, cy);

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
			DeleteObject(brush);
		}
		Sleep(150);

		//-------------------------------------------------------------

		dc.FillSolidRect(&rc, RGB(173, 255, 47));
		for (k = 0; k < 400; k++)
		{
			hNew = CreateFont(10 + rand() % 136, 0, 0, 0, FW_BOLD, 0, 0, 0,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				L"Comic Sans MS");
			hold = (HFONT)SelectObject(dc, hNew);
			int ppp = 10 + rand() % 89;

			ms.Format(L"%i", ppp);

			SetTextColor(dc, RGB(rand() % 255, rand() % 255, rand() % 255));
			x1 = rc.left + rand() % rc.right - 10;
			y1 = rc.top + rand() % rc.bottom - 10;
			dc.TextOutW(x1, y1, ms, ms.GetLength());

			Sleep(15);
			hold = (HFONT)SelectObject(dc, hbk);
		}


		int myx, KW, a = 0, b = 0, c = 0, d = 0;


		myx = RH / 6;

		KW = cx / 8;


		dc.FillSolidRect(&rc, RGB(0, 0, 0));

		a = cx - KW / ;
		b = KW;
		c = cx + KW / 1.5;
		d = 2 * KW;

		dc.Rectangle(a, b, c, d);

		for (a = cx - KW / 2; a < cx + myx * 2.5 - 2 * KW; a++)
		{
			cf = RGB(173, 255, 47);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);

			Sleep(10);
			cf = RGB(255, 255, 255);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);

			b++;
			c++;
			d++;
		}
		for (a = cx + myx * 2.5 - 2 * KW; a > cx - KW / 2; a--)
		{
			cf = RGB(173, 255, 47);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);

			Sleep(10);
			cf = RGB(255, 255, 255);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);
			b++;
			c--;
			d++;
		}
		for (a = cx - KW / 2; a > cx - myx * 2.5 + KW; a--)
		{
			cf = RGB(23, 142, 121);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);


			Sleep(10);
			cf = RGB(0,0,0);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);
			b--;
			c--;
			d--;

		}
		for (b = b; b > KW; b--)
		{
			cf = RGB(23, 142, 121);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);

			Sleep(10);
			cf = RGB(0,0,0);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			dc.Rectangle(a, b, c, d);
			a++;
			c++;
			d--;
		}
		
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnimaciaMovingObjectPoligonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

