#include <iostream>
using namespace std;

int main()
{
	// dichiarare due variabili a e b di tipo char
	char a,b; 
	// leggere a e b
	cout << "Inserisci due caratteri:" << endl;		
	cin >> a >> b; 
	cout << "I due caratteri ";
	// se a e b sono uguali
	if (a == b)
	// stampare la stringa "Uguali"
	{
		cout << "sono Uguali." << endl;
	} 
	// altrimenti
	else 
	// stampare la stringa "Diversi"
	{
		cout << "sono Diversi." << endl;
	}

	return 0;
}