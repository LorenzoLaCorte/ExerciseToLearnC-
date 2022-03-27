

#include <iostream>
#include <string>
using namespace std;

int main()
{
	float a, b, c, x, y, z;
	// input variabili a,b
	cout << "Inserisci 3 numeri minori" << endl;
	cin >> a >> b >> c;
	cout << "Hai inserito i valori " << a << " , " << b <<" , " << c << endl;
	// operazioni
	z=a;
        y=c;
	x=b;
	// stampa a e b
	cout << "I valori scambiati sono: "<< x << " , " << y <<" , " << z << endl;

	return 0;
}