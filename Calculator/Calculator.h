
// Calculator.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル
#include "CalculatorFunc.h"
#include "CalculatorData.h"


// CCalculatorApp:
// このクラスの実装については、Calculator.cpp を参照してください
//

class CCalculatorApp : public CWinApp
{
private:
	CCalculatorFunc* m_funcClsIns;
	CCalculatorData* m_dataClsIns;

public:
	CCalculatorApp();
	CString CalcText(CString);
	BOOL SaveCalcText(CString);
	BOOL LoadCalcText(CString*);

// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorApp theApp;
