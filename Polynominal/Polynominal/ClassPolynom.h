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
	TList<TMonom> *pFirst;
	static unsigned int power;
	void CreatePolinom(char *str);
public:
	CPolynom(char *str, static unsigned int pow);
	CPolynom(string str, static unsigned int pow);
	CPolynom();
	~CPolynom();
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const);
	string ToString(const CPolynom polynom);
	double Calculate(const CPolynom polynom);
};