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
	TLink()
	{
		monom.coef = 0;
		monom.degree = -1;
	}
};
class CPolynom
{
	TLink *pHead;
	void CreateHead()
	{
		pHead = new TLink;
		pHead->monom.coef = 0;
		pHead->monom.degree = -1;
	}
	string* arrStrMon;	// ������ ����������� ����������
	size_t numMonom;	// ���������� �������
	TMonom* arrMonom;	// ������ �������
	string* arrVar;		// ������ ����������� ����������
	size_t numVar;		// ���������� ����������
public:
	static unsigned int Power;
	void ToArrVar(string strVar);		// ������� � ������ ����������� ����������
	void ToArrStrMon(string strPol);	// ������� � ������ �������� �������

	CPolynom(string strPol, string strVar);
	~CPolynom();
	CPolynom();
	
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(); 
	double Calculate();
};