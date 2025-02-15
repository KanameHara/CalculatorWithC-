
// CalculatorDlg.h : ヘッダー ファイル
//

#pragma once
#include "Calculator.h"

// ダイアログ上のボタン種別
#define BUTTON_TYPE_0			0
#define BUTTON_TYPE_1			1
#define BUTTON_TYPE_2			2
#define BUTTON_TYPE_3			3
#define BUTTON_TYPE_4			4
#define BUTTON_TYPE_5			5
#define BUTTON_TYPE_6			6
#define BUTTON_TYPE_7			7
#define BUTTON_TYPE_8			8
#define BUTTON_TYPE_9			9
#define BUTTON_TYPE_EQUAL		10
#define BUTTON_TYPE_PLUS		11
#define BUTTON_TYPE_MINUS		12
#define BUTTON_TYPE_MULTIPLY	13
#define BUTTON_TYPE_DIVISION	14
#define BUTTON_TYPE_CLEAR		15
#define BUTTON_TYPE_DECIMAL		16

// CCalculatorDlg ダイアログ
class CCalculatorDlg : public CDialogEx
{
// コンストラクション
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void SetCalcText(CString);
	void GetCalcText(CString&);
	void AddCalcText(int);
	BOOL CheckCalcText(int, CString&);
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();
	afx_msg void On1ButtonClicked();
	afx_msg void On2ButtonClicked();
	afx_msg void On3ButtonClicked();
	afx_msg void On4ButtonClicked();
	afx_msg void On5ButtonClicked();
	afx_msg void On6ButtonClicked();
	afx_msg void On7ButtonClicked();
	afx_msg void On8ButtonClicked();
	afx_msg void On9ButtonClicked();
	afx_msg void On0ButtonClicked();
	afx_msg void OnEqualButtonClicked();
	afx_msg void OnPlusButtonClicked();
	afx_msg void OnMinusButtonClicked();
	afx_msg void OnMultiplyButtonClicked();
	afx_msg void OnDivisonButtonClicked();
	afx_msg void OnClearButtonClicked();
	afx_msg void OnDecimalButtonClicked();
private:
	CEdit m_calcText;
protected:
	CFont m_calcTextFont;
};
