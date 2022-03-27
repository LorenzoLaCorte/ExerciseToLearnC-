

#include <iostream>
#include <string>
using namespace std;

int main()
{
	float a, b, A, P;
	// input variabili a,b
	cout << "Inserisci i lati:" << endl;
	cin >> a >> b;
	// operazioni
	A=a*b;
	P=(a+b)*2;
	cout << "Area: "<< A  << endl;
	cout << "Perimetro: "<< P  << endl;
	return 0;
}