// Scrivere un programma che scambia i valori di due variabili di tipo char, 
// lette da input, e stampa i valori prima e dopo lo scambio.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiarare 3 variabile di tipo char a, b, c
	char a, b, c;
	// input variabili a,b
	cout << "Metti 2 numeri minori di 128 separati da uno spazio" << endl;
	cin >> a >> b;
	// stampa a e b
	cout << "Hai inserito i valori " << a << " e " << b << endl;
	// operazioni	
	c = a;
	a = b;
	b = c;
	// stampa a e b
	cout << "I valori scambiati sono: " << a << " e " << b << endl;

	return 0;
}