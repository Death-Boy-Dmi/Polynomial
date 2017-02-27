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

	string* arrStrMon;	// массив объявленных переменных
	size_t numMonom;	// количество мономов
	TMonom* arrMonom;	// массив мономов
	string* arrVar;		// массив объявленных переменных
	size_t numVar;		// количество переменных
public:
	void ToArrVar(string strVar);		// перевод в массив объявленных переменных
	void ToArrStrMon(string strPol);	// перевод в массив строчных мономов

	CPolynom(char *str, static unsigned int pow);
	CPolynom(string strPol, string strVar, static unsigned int pow);
	~CPolynom();
	CPolynom();
	
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(const CPolynom polynom); 
	double Calculate(const CPolynom polynom);
};