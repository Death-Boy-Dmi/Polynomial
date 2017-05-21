#include "ClassPolynom.h"

unsigned int CPolynom::Power;
double* CPolynom::arrArg;


void main()
{
	string strPol, _strPol;
	string strVar;
	double res;
	
	cout << "Enter the max power:\n\n\t";
	cin >> CPolynom::Power;
	cout << "\n";
	
	cout << "Enter the polynom:\n\n\t";
	cin >> strPol;
	cout << "\n";
	
	CPolynom polinom(strPol);
	
	polinom.StreamSetVar();
	res = polinom.Calculate();
	
	cout << "\tresult = " << res << endl;
	
	cout << "\n\n\t" << polinom.ToString() << "\n" << endl;
	
	cout << "Enter the second polynom to add it to the first:\n\n\t";
	cin >> _strPol;
	cout << "\n";

	CPolynom _polinom(_strPol);

	CPolynom pol = polinom + _polinom;
	res = pol.Calculate();
	cout << "\tresult = " << res << endl;
	cout << "\n\n\t" << pol.ToString() << endl;

	system("PAUSE");
}