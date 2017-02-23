#include "ClassPolynom.h"

void main()
{
	string str;
	static unsigned int pow;
	char * ch;

	cout << "Enter a power:/t";
	cin >> pow;

	cout << "Enter a polynom:/t";
	cin >> str;

	CPolynom polynom(str, pow);

}