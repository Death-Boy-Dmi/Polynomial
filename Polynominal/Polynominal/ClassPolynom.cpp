#include "ClassPolynom.h"
#include <cmath>

// перевод в массив объявленных переменных
void CPolynom::ToArrVar(string strVar)	
{
	string sV = strVar;
	numVar = 0;
	char space = ' ';

	while (sV[0] == space) 
	{
		sV.erase(0, 1);
	}
	while (sV[sV.size()-1] == space)
	{
		sV.erase(sV.size()-1, 1);
	}
	while (sV.find("  ") != string::npos)
	{
		sV.erase(sV.find("  "), 1);
	}
	sV += " ";
	for (size_t i = 0; i < sV.size(); i++)
		if (sV[i] == ' ')
			numVar++;	
	arrVar = new string[numVar]; // создание массива переменных
	for (size_t i = 0; i < numVar; i++)
	{
		arrVar[i] = "";
	}
	for (size_t i = 0; i < numVar; i++)
	{
		size_t pos = sV.find(" ");
		string strTemp = sV;
		arrVar[i] += strTemp.erase(pos, strTemp.size() - pos);
		sV.erase(0, pos + 1);
	}
}

// перевод в массив строчных мономов
void CPolynom::ToArrStrMon(string strPol)
{
	{
		string val = "-+^abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
		for (size_t i = 0; i < strPol.size(); i++)
		{

			if (val.find(strPol[i]) == string::npos)
			{
				throw "An invalid character was found";
			}
		}
		string str = " " + strPol + " ";
		string arop = "-+";
		string var = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		if (strPol[0] == '^')
			throw "First character is operations";
		if (strPol[strPol.length() - 1] == '-' || strPol[strPol.length() - 1] == '+' || strPol[strPol.length() - 1] == '^')
			throw "Last character is operations";
	}

	string sP = strPol;

	numMonom = 0;
	if (sP[0] != '+' && sP[0] != '-')
	{
		sP = "+" + sP;
	}
	for (size_t i = 0; i < sP.size(); i++)
	{
		if (sP[i] == '+' || sP[i] == '-')
		{
			numMonom++;
		}
	}
	
	arrStrMon = new string[numMonom];
	sP += " ";
	for (unsigned int i = 0; i < numMonom; i++)
	{
		size_t pos;
		for (size_t j = 1; j < sP.size(); j++)
		{
			if (sP[j] == '+' || sP[j] == '-' || sP[j] == ' ')
			{
				pos = j;
				break;
			}
		}
		string strTemp = sP;
		strTemp = strTemp.erase(pos, strTemp.size() - pos - 1);
		arrStrMon[i] = strTemp;
		sP = sP.erase(0, pos);
	}			
	
}

CPolynom::CPolynom()
{
	CreateHead();
}

CPolynom CPolynom::operator+(const CPolynom & polynom)
{
	CPolynom result;
	result.CreateHead();
	CPolynom polF = *this;
	CPolynom polS(polynom);
	TLink *pF = polF.pHead;
	TLink *pS = polS.pHead;
	TLink *pR = new TLink;
	TLink *tmp = new TLink;
	pR->pNext = tmp;
	while (pF != polF.pHead)
		while (pS != polS.pHead)
		{
			if (pF->monom.degree > pS->monom.degree)
			{
				pR->pNext = pF;
				pF = pF->pNext;
			}
			if (pF->monom.degree < pS->monom.degree)
			{
				pR->pNext = pS;
				pS = pF->pNext;
			}
			if (pF->monom.degree == pS->monom.degree)
			{
				pR->pNext->monom.coef = pF->monom.coef + pS->monom.coef;
				pR->pNext->monom.degree = pS->monom.degree;
				pS = pF->pNext;
				pF = pF->pNext;
			}
			pR = pR->pNext;
			pR->pNext = tmp;
		}
	result.pHead->pNext = pR;
	pR->pNext = result.pHead;

	return result;
}

CPolynom CPolynom::operator*(double const c)
{
	TLink *pR = new TLink;
	pR = pHead->pNext;
	while (pR != pHead)
	{
		pR->monom.coef *= c;
		pR = pR->pNext;
	}
	return *this;
}

CPolynom::CPolynom(string strPol, string strVar, unsigned int power)
{
	CreateHead();
	mainPower = power;
	// перевод строки с переменными в массив переменных
	ToArrVar(strVar);
	// перевод строки полинома в массив строк мономов
	ToArrStrMon(strPol);

	string sP = strPol;
	
	// добавление ^0 & ^1 к переменным 
	for (size_t i = 0; i<numMonom; i++)
		for (size_t j = 0; j < numVar; j++)
		{
			if (arrStrMon[i].find(arrVar[j]) == string::npos)
			{
				if (j == 0)
				{
					size_t k = 0;
					string digits = "0123456789.+-";
					while (digits.find(arrStrMon[i][k]) != string::npos)
					{
						k++;
					}
					string var = arrVar[j] + "^0";
					arrStrMon[i].insert(k, var);
				}
				else
				{
					size_t k = arrStrMon[i].find(arrVar[j - 1]) + arrVar[j - 1].length() + 1;
					string digits = "0123456789.+-";
					while (digits.find(arrStrMon[i][k]) != string::npos)
					{
						k++;
					}
					string var = arrVar[j] + "^0";
					arrStrMon[i].insert(k, var);
				}
			}
			if (arrStrMon[i][arrStrMon[i].find(arrVar[j]) + 1] != '^')
			{
				size_t pos = arrStrMon[i].find(arrVar[j]) + 1;
				arrStrMon[i].insert(pos, "^1");
			}
		}

	// заполнение коэффициентов
	arrMonom = new TMonom[numMonom];
	for (size_t i = 0; i < numMonom; i++)
	{
		string strTemp = arrStrMon[i];
		size_t pos = strTemp.find(arrVar[0]);
		strTemp = strTemp.erase(pos, arrStrMon[i].size() - pos);
		if (strTemp == "+")
			arrMonom[i].coef = 1;
		else
			if (strTemp == "-")
				arrMonom[i].coef = -1;
			else
				arrMonom[i].coef = atof(strTemp.c_str());
	}

	// заполнение степеней
	for (size_t i = 0; i < numMonom; i++)
	{
		string monomWithOutVar = arrStrMon[i];
		monomWithOutVar = arrStrMon[i].erase(0, arrStrMon[i].find(arrVar[0]));
		for (size_t j = 0; j < numVar; j++)
		{
			size_t posVar = monomWithOutVar.find(arrVar[j]);
			size_t lengthVarStr = arrVar[j].length();
			monomWithOutVar = monomWithOutVar.erase(posVar, lengthVarStr);
		}
 		unsigned int *arrPow = new unsigned int[numVar];
		arrMonom[i].degree = 0;
		for (size_t j = 0; j < numVar; j++)
		{
			string tmp = monomWithOutVar.erase(0,1);
			size_t pos;
			if (monomWithOutVar.find("^") == string::npos)
			{
				arrMonom[i].degree += atoi(tmp.c_str());
			}
			else
			{
				pos = monomWithOutVar.find("^");
				tmp = tmp.erase(pos, tmp.size() + 1 - pos);
				arrPow[j] = atoi(tmp.c_str());
				monomWithOutVar.erase(0, pos);
				arrMonom[i].degree += arrPow[j] * pow(power, numVar - 1 - j);
			}
		}
	}

	// bublesort
	for (size_t i = 0; i < numMonom; i++)
		for (size_t j = numMonom - 1; j > i; j--)
			if (arrMonom[j - 1].degree > arrMonom[j].degree)
				swap(arrMonom[j - 1].degree, arrMonom[j].degree);

	TLink *p = new TLink;
	TLink *tmp = new TLink;
	for (size_t i = 0; i < numMonom; i++)
	{
		if (i != 0)
			p = p->pNext;
		p->monom = arrMonom[i];
		p->pNext = tmp;
	}
	p->pNext = pHead;
	pHead->pNext = p;
}

CPolynom::~CPolynom()
{
	TLink *p = new TLink;
	p = pHead->pNext;
	TLink *tmp = new TLink;
	while (p != pHead)
	{
		tmp = p->pNext;
		delete p;
		p = tmp;
	}
	delete p;
	delete[] arrStrMon;
	delete arrMonom;
	delete[] arrVar;
}

string CPolynom::ToString()
{
	string result = "";
	TLink *p = new TLink;
	p = pHead->pNext;
	while (p != pHead)
	{
		string strCoef = to_string(p->monom.coef);
		if (p->monom.coef > 0)
			strCoef = "+" + strCoef;
		if (p->monom.coef == 0)
		{
			continue;
			p = p->pNext;
		}
		result += strCoef + "*";
		unsigned int deg = p->monom.degree;
		for (size_t j = 0; j < numVar; j++)
		{
			result += arrVar[j] + "^" + to_string(deg / pow(mainPower, numVar - 1 - j));
			deg = deg % (int)pow(mainPower, numVar - 1 - j);
		}
		p = p->pNext;
	}

	return result;
}

double CPolynom::Calculate()
{
	unsigned int power = mainPower;
	double result = 0;
	double * arrArg = new double[numVar];
	for (size_t i = 0; i < numVar; i++)
	{
		cout << arrVar[i] << " = ";
		cin >> arrArg[i];
		cout << endl;
	}
	TLink *p = new TLink;
	p = pHead->pNext;
	while (p != pHead)
	{
		int tmp = p->monom.degree;
		double tempMonom = 1;
		for (size_t j = 0; j < numVar; j++)
		{
			int tmpDelPow = pow(power, numVar - 1 - j);
			int tmpPower = (int)( tmp / tmpDelPow );
			tempMonom *= pow(arrArg[j], tmpPower);
			tmp = tmp % (int)(pow(power, numVar - 1 - j));
		}
		result += p->monom.coef*tempMonom;
		p = p->pNext;
	}
	return result;
}