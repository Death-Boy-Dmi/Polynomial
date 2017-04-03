#include "ClassPolynom.h"

unsigned int CPolynom::Power;

void main()
{
	string strPol;
	string strVar;
	double res;

	cout << "Enter the names of variabels as a priority (through a space):\n\n\t";
	getline (cin,strVar);
	cout << "\n";
	
	cout << "Enter the max power:\n\n\t";
	cin >> CPolynom::Power;
	cout << "\n";
	
	cout << "Enter the polynom:\n\n\t";
	cin >> strPol;
	cout << "\n";
	
	CPolynom polinom(strPol, strVar);
	
	res = polinom.Calculate();
	
	cout << "\tresult = " << res << endl;
	
	cout << "\n\n\t" << polinom.ToString() << endl;
	
	system("PAUSE");
}