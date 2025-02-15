#pragma once

#define CALCTEXT_SAVE_PATH      L"C:\\calculator\\"     
#define CALCTEXT_FILE_PATH      CALCTEXT_SAVE_PATH L"calcText.txt"

class CCalculatorData
{
public:
	BOOL SaveCalcText(CString calcText);
	BOOL LoadCalcText(CString& calcText);
};