#include "ClassPolynom.h"

void main()
{
	string strPol;
	string strVar;
	double res;
	static unsigned int power;
	char * ch;

	cout << "Enter the names of variabels as a priority (through a space):\n\n\t";
	getline (cin,strVar);
	cout << "\n";
	cout << "Enter power:\n\n\t";
	cin >> power;
	cout << "\n";
	cout << "Enter the polynom:\n\n\t";
	cin >> strPol;
	cout << "\n";
	CPolynom polinom(strPol, strVar, power);
	res = polinom.Calculate();
	cout << "\tresult = " << res << endl;
	getchar();
}