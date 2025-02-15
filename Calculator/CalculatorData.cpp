#include "pch.h"
#include "CalculatorData.h"
#pragma once

BOOL CCalculatorData::SaveCalcText(CString calcText)
{
	BOOL result = FALSE;
	BOOL ret = CreateDirectoryW(CALCTEXT_SAVE_PATH, NULL);

    if (ret == TRUE || GetLastError() == ERROR_ALREADY_EXISTS)
    {
        CFile file;
        if (file.Open(CALCTEXT_FILE_PATH, CFile::modeCreate | CFile::modeWrite))
        {
            file.Write((LPCTSTR)calcText, calcText.GetLength() * sizeof(TCHAR));
            file.Close();
            result = TRUE;
        }
        else
        {
			result = FALSE;
        }
    }
    else
    {
		result = FALSE;
    }

    return result;
}

BOOL CCalculatorData::LoadCalcText(CString& calcText)
{
    CFile file;
    if (file.Open(CALCTEXT_FILE_PATH, CFile::modeRead))
    {
        ULONGLONG fileSize = file.GetLength();
        TCHAR* buffer = calcText.GetBufferSetLength((int)(fileSize / sizeof(TCHAR)));
        file.Read(buffer, (UINT)fileSize);
        calcText.ReleaseBuffer();
        file.Close();
        return TRUE;
    }
    return FALSE;
}