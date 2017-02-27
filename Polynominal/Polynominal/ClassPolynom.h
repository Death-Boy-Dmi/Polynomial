#pragma once

#include "TList.h"
#include <iostream>
#include <string>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};

class CPolynom
{
	TCircularList<TMonom> *pHead;
	static unsigned int power;

	string* arrStrMon;	// ������ ����������� ����������
	size_t numMonom;	// ���������� �������
	TMonom* arrMonom;	// ������ �������
	string* arrVar;		// ������ ����������� ����������
	size_t numVar;		// ���������� ����������
public:
	void ToArrVar(string strVar);		// ������� � ������ ����������� ����������
	void ToArrStrMon(string strPol);	// ������� � ������ �������� �������

	CPolynom(char *str, static unsigned int pow);
	CPolynom(string strPol, string strVar, static unsigned int pow);
	~CPolynom();
	CPolynom();
	
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(const CPolynom polynom); 
	double Calculate(const CPolynom polynom);
};