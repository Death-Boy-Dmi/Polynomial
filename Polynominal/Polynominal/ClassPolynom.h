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
	string* arrStrMon;	// массив объявленных мономов
	size_t numMonom;	// количество мономов
	TMonom* arrMonom;	// массив мономов
	double* arrArg;

	void ToArrStrMon(string strPol);	// перевод в массив строчных мономов
public:
	static unsigned int Power;
	static unsigned int numVar;		// количество переменных
	static string* arrVar;		// массив объявленных переменных

	CPolynom(string strPol, string strVar);
//	~CPolynom();
	CPolynom();
	
	size_t GetNumVar() { return numVar; }
	size_t GetNumMonom() { return numMonom; }

	void ToArrVar(string strVar);		// перевод в массив объявленных переменных
	void StreamSetVar();
	void SetVar(double* arr);

	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(); 
	double Calculate();
};