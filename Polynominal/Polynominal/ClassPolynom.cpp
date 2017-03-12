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
		for (size_t i = 0; i < str.length(); i++)
			if (arop.find(str[i]) >= 0 && arop.find(str[i]) <= str.length())
			{
				if ((var.find(str[i - 1]) >= 0 && var.find(str[i - 1]) <= var.length())
					&& (var.find(str[i + 1]) >= 0 && var.find(str[i - 1]) <= var.length())
					|| (str[i + 1] == '(' && str[i - 1] == ')'))
					continue;
				else
					throw "the number of variables does not correspond to the numbers of operations";
			}
		if (strPol[0] == '^')
			throw "First character is operations";
		if (strPol[strPol.length() - 1] == '-' || strPol[strPol.length() - 1] == '+' || strPol[strPol.length() - 1] == '^')
			throw "Last character is operations";
	}

	string sP = strPol;
	numMonom = 0;
	for (size_t i = 0; i < sP.size(); i++)
	{
		if (sP[i] == '+' || sP[i] == '-')
		{
			numMonom++;
		}
	}
	numMonom++;
	
	arrStrMon = new string[numMonom];
	sP += " ";
	for (unsigned int i = 0; i < numMonom; i++)
	{
		unsigned int pos = sP.find(" ");
		if (sP.find(" ") != string::npos)
			pos = sP.find(" ");
		if (sP.find("+") != string::npos)
			pos = sP.find("+");
		if (sP.find("-") != string::npos)
			pos = sP.find("-");
		string strTemp = sP;
		strTemp = strTemp.erase(pos, strTemp.size() - pos);
		arrStrMon[i] = strTemp;
		sP = sP.erase(0, pos);
	}
}

CPolynom::CPolynom()
{
	CreateHead();
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

	// заполнение коэффициентов
	arrMonom = new TMonom[numMonom];
	for (size_t i = 0; i < numMonom; i++)
	{
		size_t pos = sP.find(arrStrMon[i]);
		string strTemp = arrStrMon[i];
		strTemp = strTemp.erase(pos, arrStrMon[i].size() - pos);
		if (strTemp.size() == NULL)
			arrMonom[i].coef = 1;
		else
			arrMonom[i].coef = atof(strTemp.c_str());
	}

	// добавление ^0 & ^1 к переменным в мономах
	for (size_t i = 0; i < numMonom; i++)
	{
		for (size_t j = 0; j < numVar; j++)
		{
			size_t posVar;
			if (posVar = arrStrMon[i].find(arrVar[j]) == string::npos)
			{
				size_t jj = j;
				size_t posNextVar;
				while (posNextVar = arrStrMon[i].find(arrVar[jj]) == string::npos && jj < numVar)
				{
					jj++;
				}
				if (jj == numVar)
				{
					arrStrMon[i] += arrVar[j] + "^0";
				}
				string strTemp = arrStrMon[i];
				arrStrMon[i] = arrStrMon[i].erase(posNextVar, (arrStrMon[i].size() - posNextVar));
				arrStrMon[i] += arrVar[i] + "^0" + strTemp.erase(0, posNextVar + 1);
			}
			else
			{
				if (arrStrMon[i][posVar + 1] != '^')
				{
					string strTemp = arrStrMon[i];
					arrStrMon[i] = arrStrMon[i].erase(posVar, (arrStrMon[i].size() - posVar));
					arrStrMon[i] += arrVar[i] + "^1" + strTemp.erase(0, posVar + 1);
				}
			}
		}
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

	for (size_t i = 0; i < numMonom; i++)
		for (size_t j = numMonom - 1; j > i; j--)
			if (arrMonom[j - 1].degree > arrMonom[j].degree)
				swap(arrMonom[j - 1].degree, arrMonom[j].degree);
	TLink *p = new TLink;
	for (size_t i = 0; i < numMonom; i++)
	{
		if (i != 0)
			p = p->pNext;
		p->monom = arrMonom[i];
	}
	p->pNext = pHead;
	pHead->pNext = p;
}

CPolynom::~CPolynom()
{
	delete pHead;
	delete[] arrStrMon;
	delete arrMonom;
	delete[] arrVar;
}

CPolynom CPolynom::operator+(const CPolynom & polynom)
{
	CPolynom polF = *this;
	CPolynom polS(polynom);
	CPolynom result;
	result.arrMonom = new TMonom[polF.numMonom + polS.numMonom];
	TMonom mon_null;
	mon_null.coef = 0;
	mon_null.degree = -1;
	result.CreateHead();
	unsigned int k = 0, i = 1, j = 1;
	TLink *pF = polF.pHead;
	TLink *pS = polS.pHead;
	while (pF->pNext!=polF.pHead)
		while (pS->pNext != polS.pHead)
		{

			if (polF.arrMonom[i].degree > polS.arrMonom[j].degree)
			{
				result.arrMonom[k] = polF.arrMonom[i];
				i++;
			}
			else
			{
				result.arrMonom[k] = polS.arrMonom[j];
				j++;
			}
			if (polF.arrMonom[i].degree == polS.arrMonom[j].degree)
			{
				result.arrMonom[k].degree = polF.arrMonom[i].degree;
				result.arrMonom[k].coef = polF.arrMonom[i].coef + polS.arrMonom[j].coef;
				if (result.arrMonom[k].coef == 0)
				{

				}
				i++;
				j++;
			}
			k++;
		}
	TLink *p = pHead;
	for (size_t i = 0; i < result.numMonom; i++)
	{
		p->pNext;
		p->monom = arrMonom[i];
	}
	return result;
}

CPolynom CPolynom::operator*(double const c)
{
	CPolynom result = *this;
	for (size_t i = 0; i < numMonom; i++)
		result.arrMonom[i].coef *= c;
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
	for (size_t i = 0; i < numMonom; i++)
	{
		int tmp = arrMonom[i].degree;
		double tempMonom = 1;
		for (size_t j = 0; j < numVar; j++)
		{
			int tmpDelPow = pow(power, numVar - 1 - j);
			int tmpPower = (int)( tmp / tmpDelPow );
			tempMonom *= pow(arrArg[j], tmpPower);
			tmp = tmp % (int)(pow(power, numVar - 1 - j));
		}
		result += arrMonom[i].coef*tempMonom;
	}
	return result;
}