#include "ClassPolynom.h"

unsigned int CPolynom::Power;
unsigned int CPolynom::numVar;
string* CPolynom::arrVar;

void main()
{
	//string strPol;
	//string strVar;
	//double res;

	//cout << "Enter the names of variabels as a priority (through a space):\n\n\t";
	//getline (cin,strVar);
	//cout << "\n";
	//
	//cout << "Enter the max power:\n\n\t";
	//cin >> CPolynom::Power;
	//cout << "\n";
	//
	//cout << "Enter the polynom:\n\n\t";
	//cin >> strPol;
	//cout << "\n";
	//
	//CPolynom polinom(strPol, strVar);
	//
	//polinom.StreamSetVar();
	//res = polinom.Calculate();
	//
	//cout << "\tresult = " << res << endl;
	//
	//cout << "\n\n\t" << polinom.ToString() << endl;
	
	CPolynom::Power = 10;
	CPolynom pol1("-3x^2y^3+3x^3y^2", "x y");
	CPolynom pol2("-3x^2y^3+3x^3y^2", "x y");
	CPolynom pol = pol1 + pol2;

	cout << "\n\n\t" << pol.ToString()<< endl;
	system("PAUSE");
}