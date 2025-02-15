
// CalculatorDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg ダイアログ



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_calcText);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::On1ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::On2ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::On3ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::On4ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::On5ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::On6ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::On7ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::On8ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::On9ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::On0ButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnEqualButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnPlusButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnMinusButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnMultiplyButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnDivisonButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnClearButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnDecimalButtonClicked)
END_MESSAGE_MAP()


// CCalculatorDlg メッセージ ハンドラー

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_calcTextFont.CreatePointFont(180, _T("Segoe UI"));
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->SetFont(&m_calcTextFont);
	CString initText= L"";
	BOOL ret = theApp.LoadCalcText(&initText);
	if (ret == FALSE)
	{
		initText = L"0";
	}
	SetCalcText(initText);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::SetCalcText(CString text)
{
	m_calcText.SetWindowText(text);
}

void CCalculatorDlg::GetCalcText(CString& text)
{
	m_calcText.GetWindowText(text);
}

BOOL CCalculatorDlg::CheckCalcText(int buttonType, CString& tmpCalcText)
{
	if ((buttonType < BUTTON_TYPE_0) && (buttonType > BUTTON_TYPE_DECIMAL))
	{
		return FALSE;
	}

	// 表示値がErrorの場合は初期値の0に戻す
	if (tmpCalcText == "Error")
	{
		tmpCalcText = "0";
	}

	// 表示値が0で数値が入力されたら0は削除する
	if (tmpCalcText == "0")
	{
		if ((buttonType >= BUTTON_TYPE_0) && (buttonType <= BUTTON_TYPE_9))
		{
			tmpCalcText = "";
		}
	}

	// 値が入力可能かチェック
	int txtLength = tmpCalcText.GetLength();
	CString lastChar;
	lastChar = tmpCalcText.Mid(txtLength - 1, 1);

	// 演算子を入力してよいかチェック
	if ((txtLength > 0) &&
		(buttonType >= BUTTON_TYPE_PLUS) && (buttonType <= BUTTON_TYPE_DIVISION))
	{
		if ((lastChar == "+") ||
			(lastChar == "-") ||
			(lastChar == "*") ||
			(lastChar == "/"))
		{
			tmpCalcText.Delete(txtLength - 1);
		}
		else if (lastChar == ".")
		{
			tmpCalcText.Delete(txtLength - 1);
		}
	}

	// 0を連続入力してよいかチェック
	if ((buttonType == BUTTON_TYPE_0) &&
		(lastChar == "0"))
	{
		CString CheckedChar;
		for (int i = 0; i < txtLength; i++)
		{
			CheckedChar = tmpCalcText.Mid(txtLength - i, 1);
			if (CheckedChar == ".")
			{
				break;
			}
			else if ((CheckedChar == "+") ||
					 (CheckedChar == "-") ||
					 (CheckedChar == "*") ||
					 (CheckedChar == "/"))
			{
				return FALSE;
			}
		}
	}

	// 小数点を入力してよいかチェック
	if (buttonType == BUTTON_TYPE_DECIMAL)
	{
		if ((lastChar == "+") ||
			(lastChar == "-") ||
			(lastChar == "*") ||
			(lastChar == "/"))
		{
			return FALSE;
		}

		CString CheckedChar;
		for (int i = 0; i < txtLength; i++)
		{
			CheckedChar = tmpCalcText.Mid(txtLength - i, 1);
			if ((CheckedChar == "+") ||
				(CheckedChar == "-") ||
				(CheckedChar == "*") ||
				(CheckedChar == "/"))
			{
				if (i == 0)
				{
					return FALSE;
				}
				break;
			}
			else if (CheckedChar == ".")
			{
				return FALSE;
			}
		}
	}

	return TRUE;
}

void CCalculatorDlg::AddCalcText(int buttonType)
{
	if ((buttonType < BUTTON_TYPE_0) && (buttonType > BUTTON_TYPE_DECIMAL))
	{
		return;
	}

	CString tmpCalcText;
	GetCalcText(tmpCalcText);

	BOOL checkResult = FALSE;
	checkResult = CheckCalcText(buttonType, tmpCalcText);
	if (checkResult == FALSE) 
	{
		return;
	}

	switch (buttonType)
	{
	case BUTTON_TYPE_1:
		tmpCalcText += "1";
		break;
	case BUTTON_TYPE_2:
		tmpCalcText += "2";
		break;
	case BUTTON_TYPE_3:
		tmpCalcText += "3";
		break;
	case BUTTON_TYPE_4:
		tmpCalcText += "4";
		break;
	case BUTTON_TYPE_5:
		tmpCalcText += "5";
		break;
	case BUTTON_TYPE_6:
		tmpCalcText += "6";
		break;
	case BUTTON_TYPE_7:
		tmpCalcText += "7";
		break;
	case BUTTON_TYPE_8:
		tmpCalcText += "8";
		break;
	case BUTTON_TYPE_9:
		tmpCalcText += "9";
		break;
	case BUTTON_TYPE_0:
		tmpCalcText += "0";
		break;
	case BUTTON_TYPE_EQUAL:
		// イコール押下時には計算結果を表示するためここでは何も処理しないこと
		break;
	case BUTTON_TYPE_PLUS:
		tmpCalcText += "+";
		break;
	case BUTTON_TYPE_MINUS:
		tmpCalcText += "-";
		break;
	case BUTTON_TYPE_MULTIPLY:
		tmpCalcText += "*";
		break;
	case BUTTON_TYPE_DIVISION:
		tmpCalcText += "/";
		break;
	case BUTTON_TYPE_CLEAR:
		tmpCalcText = "0";
		break;
	case BUTTON_TYPE_DECIMAL:
		tmpCalcText += ".";
		break;
	}

	SetCalcText(tmpCalcText);
}

BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// エンターキーが押されたかを確認
	//if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	//{
	//	// イコールボタン押下時の処理を実行
	//	OnEqualButtonClicked();
	//	return TRUE;  // 既に処理したので、デフォルトの処理は行わない
	//}

	// キーが押されたかどうか
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_NUMPAD0:
			On0ButtonClicked();
			return TRUE;

		case VK_NUMPAD1:
			On1ButtonClicked();
			return TRUE;

		case VK_NUMPAD2:
			On2ButtonClicked();
			return TRUE;

		case VK_NUMPAD3:
			On3ButtonClicked();
			return TRUE;

		case VK_NUMPAD4:
			On4ButtonClicked();
			return TRUE;

		case VK_NUMPAD5:
			On5ButtonClicked();
			return TRUE;

		case VK_NUMPAD6:
			On6ButtonClicked();
			return TRUE;

		case VK_NUMPAD7:
			On7ButtonClicked();
			return TRUE;

		case VK_NUMPAD8:
			On8ButtonClicked();
			return TRUE;

		case VK_NUMPAD9:
			On9ButtonClicked();
			return TRUE;

		case VK_ADD:
			OnPlusButtonClicked();
			return TRUE;

		case VK_SUBTRACT:
			OnMinusButtonClicked();
			return TRUE;

		case VK_MULTIPLY:
			OnMultiplyButtonClicked();
			return TRUE;

		case VK_DIVIDE:
			OnDivisonButtonClicked();
			return TRUE;

		case VK_DECIMAL:
			OnDecimalButtonClicked();
			return TRUE;

		case VK_RETURN:
			OnEqualButtonClicked();
			return TRUE;

		default:
			break;
		}
	}

	// それ以外のメッセージは親クラスに渡す
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CCalculatorDlg::OnClose()
{
	CString displyText = _T("");
	GetCalcText(displyText);
	if (displyText != "0")
	{
		BOOL result = FALSE;
		result = theApp.SaveCalcText(displyText);

		if (result == FALSE)
		{
			AfxMessageBox(_T("計算履歴の保存に失敗しました。"));
		}
	}
	// 親クラスの OnClose を呼び出してウィンドウを閉じる
	CDialogEx::OnClose();
}

void CCalculatorDlg::On1ButtonClicked( )
{
	AddCalcText(BUTTON_TYPE_1);
}


void CCalculatorDlg::On2ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_2);
}


void CCalculatorDlg::On3ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_3);
}


void CCalculatorDlg::On4ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_4);
}


void CCalculatorDlg::On5ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_5);
}

void CCalculatorDlg::On6ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_6);
}


void CCalculatorDlg::On7ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_7);
}


void CCalculatorDlg::On8ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_8);
}


void CCalculatorDlg::On9ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_9);
}


void CCalculatorDlg::On0ButtonClicked()
{
	AddCalcText(BUTTON_TYPE_0);
}


void CCalculatorDlg::OnEqualButtonClicked()
{
	CString txtPram = L"";
	GetCalcText(txtPram);
	CString lastChar = txtPram.Mid(txtPram.GetLength() - 1, 1);
	if ((lastChar == "+") ||
		(lastChar == "-") ||
		(lastChar == "*") ||
		(lastChar == "/"))
	{
		txtPram.Delete(txtPram.GetLength() - 1);
	}

	CString AnswerTxt = L"";
	AnswerTxt = theApp.CalcText(txtPram);

	if (AnswerTxt == "Error")
	{
		AfxMessageBox(_T("0で割ることはできません。"));
	}
	else
	{
		int txtLength = 0;
		txtLength = AnswerTxt.GetLength();
		CString CheckedChar;
		for (int i = 0; i < txtLength; i++)
		{
			CheckedChar = AnswerTxt.Mid(txtLength - i, 1);
			if ((CheckedChar == "") ||
				(CheckedChar == "0") ||
				(CheckedChar == "."))
			{
				AnswerTxt.Delete(txtLength - i);
				if (i == txtLength - 1)
				{
					CString FirstChar;
					FirstChar = AnswerTxt.Mid(txtLength, 1);
					if ((FirstChar == "0") || (FirstChar == "-"))
					{
						AnswerTxt = "0";
					}
				}
			}
			else
			{
				break;
			}
		}
	}

	SetCalcText(AnswerTxt);
}


void CCalculatorDlg::OnPlusButtonClicked()
{
	AddCalcText(BUTTON_TYPE_PLUS);
}


void CCalculatorDlg::OnMinusButtonClicked()
{
	AddCalcText(BUTTON_TYPE_MINUS);
}


void CCalculatorDlg::OnMultiplyButtonClicked()
{
	AddCalcText(BUTTON_TYPE_MULTIPLY);
}


void CCalculatorDlg::OnDivisonButtonClicked()
{
	AddCalcText(BUTTON_TYPE_DIVISION);
}


void CCalculatorDlg::OnClearButtonClicked()
{
	AddCalcText(BUTTON_TYPE_CLEAR);
}


void CCalculatorDlg::OnDecimalButtonClicked()
{
	AddCalcText(BUTTON_TYPE_DECIMAL);
}
