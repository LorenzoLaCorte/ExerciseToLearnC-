#include <iostream>
#include <string>
using namespace std;

int main()
{
	// chiedere di inserire il valore per la variabile a
	cout << "inserisci un numero intero: " << endl;
	// dichiarare una variabile a di tipo int
	int a;
	// leggere a
	cin >> a;
	// chiedere di inserire il valore per la variabile b
	cout << "inserisci un numero intero: " << endl;
	// dichiarare una variabile b di tipo int
	int b;
	// leggere b
	cin >> b;
	// stampare un a capo seguito dalla stringa "a vale " e  dal valore di a
	cout << "'a' vale: " << a << endl;
	// stampare un a capo seguito dalla stringa "b vale " e  dal valore di b
	cout << "'b' vale: " << b << endl;	
	// scambiare fra loro i valori di a e b: per farlo serve una variabile di...
	// ... appoggio c
	// dichiarare una variabile c di tipo int inizializzata con il valore di a
	int c = a;
	// assegnare ad a il valore di b
	a = b;
	// assegnare a b il valore di c, ovvero il valore iniziale di a
	b = c;	
	// stampare un a capo seguito dalla stringa "a vale " e  dal valore di a
	cout << "'a' adesso vale: " << a << endl;	
	// stampare un a capo seguito dalla stringa "b vale " e dal valore di b
	cout << "'b' adesso vale: " << b << endl;	
	return 0;
}