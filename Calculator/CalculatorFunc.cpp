#include "pch.h"  
#include "CalculatorFunc.h" 

BOOL CCalculatorFunc::isValidFormula(CString calcText)
{
	int calcTextLength = 0;
	CString checkedChar = _T("");
	calcTextLength = calcText.GetLength();

	for (int i = 0; i < calcTextLength; i++)
	{
		checkedChar = calcText.Mid(i, 1);
		if ((checkedChar == "+") ||
			(checkedChar == "-") ||
			(checkedChar == "*") ||
			(checkedChar == "/"))
		{
			return TRUE;
		}
	}
	return FALSE;
}

void CCalculatorFunc::Calculate(CString* calcText)
{
	if ((calcText == NULL) ||
		(*calcText == "") ||
		(isValidFormula(*calcText) == FALSE))
	{
		return;
	}

	int calcTextLength = 0;

	double leftNum = 0;
	CString leftNumTxt = _T("");
	BOOL isLeftNumFinishing = FALSE;

	CString opretorTxt = _T("");
	BOOL isOpretorFinishing = FALSE;

	CString rightNumTxt = _T("");
	double rightNum = 0;
	BOOL isRightNumFinishing = FALSE;

	CString nextOpretorTxt = _T("");

	double tmpAnswerNum = 0;
	double answerNum = 0;

	calcTextLength = calcText->GetLength();
	for (int i = 0; i < calcTextLength; i++)
	{
		CString checkedChar = calcText->Mid(i, 1);
		if ((isLeftNumFinishing != TRUE) && (isOpretorFinishing != TRUE)) 
		{
			if ((checkedChar != "+") &&
				(checkedChar != "-") &&
				(checkedChar != "*") &&
				(checkedChar != "/"))
			{
				leftNumTxt += calcText->Mid(i, 1);
			}
			else
			{
				isLeftNumFinishing = TRUE;
				opretorTxt = calcText->Mid(i, 1);
				isOpretorFinishing = TRUE;
			}
		}
		else
		{
			if ((checkedChar != "+") &&
				(checkedChar != "-") &&
				(checkedChar != "*") &&
				(checkedChar != "/"))
			{
				rightNumTxt += calcText->Mid(i, 1);
				if (i == calcTextLength - 1) 
				{
					isRightNumFinishing = TRUE;
				}
			}
			else
			{
				isRightNumFinishing = TRUE;
				nextOpretorTxt = calcText->Mid(i, 1);
			}
		}

		if (isRightNumFinishing == TRUE) 
		{
			leftNum = _ttof(leftNumTxt);
			rightNum = _ttof(rightNumTxt);

			if (opretorTxt == "+")
			{
				tmpAnswerNum = leftNum + rightNum;
			}
			else if (opretorTxt == "-")
			{
				tmpAnswerNum = leftNum - rightNum;
			}
			else if (opretorTxt == "*")
			{
				tmpAnswerNum = leftNum * rightNum;
			}
			else if (opretorTxt == "/")
			{
				if (rightNum == 0)
				{
					calcText->Format(_T("Error"));
					return;
				}
				tmpAnswerNum = leftNum / rightNum;
			}

			if (i == calcTextLength - 1)
			{
				answerNum = tmpAnswerNum;
			}
			else 
			{
				leftNum = tmpAnswerNum;
				leftNumTxt.Format(_T("%f"), leftNum);
				opretorTxt = nextOpretorTxt;
				isRightNumFinishing = FALSE;
				rightNumTxt = _T("");
			}
		}
	}

	calcText->Format(_T("%f"), answerNum);
}