#include "ClassPolynom.h"

void main()
{
	string strPol;
	string strVar;
	static unsigned int power;
	char * ch;

	cout << "Enter the names of variabels as a priority (through a space):/n/t";
	cin >> strVar;
	cout << "Enter power:/t";
	cin >> power;

	cout << "Enter the polynom:/n/t";
	cin >> strPol;
	CPolynom(strPol, strVar, power);
}