#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiarare due variabili a e b di tipo int
	int a, b;	

	// leggere  a e b
	cin >> a >> b;	

	// dichiarare una variabile sum di tipo int inizializzata con il valore..
	// ... della somma di a e b	
	int sum = a + b;	

	// stampare la stringa "La somma vale " seguito da sum e un a capo
	cout << "la somma vale: " << sum << endl;

	return 0;
}