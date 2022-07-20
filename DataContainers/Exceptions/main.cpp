#include<iostream>
using namespace std;

//#define TRY_SYNTAX

void main()
{
	setlocale(LC_ALL, "");
#ifdef TRY_SYNTAX
	try
	{
		throw 1;
	}
	catch (short e)
	{
		cerr << "Error #" << e << " (short)\n";
	}
	catch (int e)
	{
		cerr << "Error #" << e << " (int)\n";
	}
#endif // TRY_SYNTAX

	//cout << 2 / 0 << endl;
	int a, b;
	cout << "¬ведите два числа: "; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (...)
	{
		cerr << "Something happened :-(\n" << endl;
	}
}