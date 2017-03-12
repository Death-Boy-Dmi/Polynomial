#pragma once

#include <iostream>
#include <string>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};
struct TLink
{
	TMonom monom;
	TLink *pNext;
};
class CPolynom
{
	TLink *pHead;
	unsigned int mainPower;
	void CreateHead()
	{
		pHead = new TLink;
		pHead->monom.coef = 0;
		pHead->monom.degree = -1;
		pHead->pNext = pHead;
	}
	string* arrStrMon;	// ������ ����������� ����������
	size_t numMonom;	// ���������� �������
	TMonom* arrMonom;	// ������ �������
	string* arrVar;		// ������ ����������� ����������
	size_t numVar;		// ���������� ����������
public:
	void ToArrVar(string strVar);		// ������� � ������ ����������� ����������
	void ToArrStrMon(string strPol);	// ������� � ������ �������� �������

	CPolynom(string strPol, string strVar, unsigned int pow);
	~CPolynom();
	CPolynom();
	
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(); 
	double Calculate();
};