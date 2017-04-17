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
	

public:
	static double* arrArg;
	static unsigned int Power;
	static unsigned int numVar;		// количество переменных
	static string* arrVar;		// массив объявленных переменных

	CPolynom(string strPol, string strVar);
	CPolynom();
	
	double* GetArrArg() { return arrArg; }
	void ToArrVar(string strVar);		// перевод в массив объявленных переменных
	void StreamSetVar();
	void SetVar(double* arr);

	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(); 
	double Calculate();
};