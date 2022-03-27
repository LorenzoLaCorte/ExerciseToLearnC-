#include <iostream>
using namespace std;

int main()
{
	int a,b;

	cout << "Inserisci due numeri interi:" << endl;
	cin >> a >> b;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	cout << "I valori scambiati sono:" << endl;
	cout << a << "  " << b << endl;

	return 0;
}