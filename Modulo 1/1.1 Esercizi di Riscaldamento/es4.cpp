#include <iostream>
#include <string>
using namespace std;

int main()
{
	// chiedere di inserire due valori interi
	cout << "inserisci 2 valori interi divisi con uno spazio: " << endl;	// dichiarare due variabili a e b di tipo int
	int a, b;
	// leggere  a e b
	cin >> a >> b;
	// stampare la stringa "La differenza vale "
	// stampare il valore di a - b
	// stampare una andata a capo
	cout << "la differenza vale: " << a - b << endl;	
	
	return 0;
}