#include <iostream>
using namespace std;

int main
{
	// stampare la stringa "Inserisci una lettera maiuscola"
	cout << "Inserisci una lettera maiuscola" << endl;
	// dichiarare una variabile first di tipo char
	char first;
	/* ripetere
	- leggere first
	finché first minore di `A' o maggiore di `Z'
	// Hint: ovvero finché l'utente non inserisce una lettera maiuscola
	*/
	// Hint: a questo punto sappiamo che first è una lettera maiuscola!
	// dichiarare una variabile c di tipo char inizializzata con `Z'
	// Hint: a questo punto sappiamo che first <= c!
	/* ripetere
	- se c è minore di first
	-- assegnazione di c a first
	- stampa della stringa "Inserisci una lettera maiuscola (o altro...
	... carattere per terminare)"
	- lettura di c
	finché c è maggiore di `A' e minore di `Z'
	// Hint: ovvero finché l'utente inserisce lettere maiuscole
	*/
	do()
	{
		cin >> first;

	} while (first < 'A' || first > 'Z');

	char c = 'Z';

	while (first <= c)
	{
		if(c < first)
		{
			c = first;
		}
	
		cout << "Inserisci una lettera maiuscola (o altro carattere per terminare)" << endl;
		cin >> c;
	}
	// stampare la stringa "La lettera più piccola inserita è " seguita da first
	cout << "La lettera più piccola inserita è " << first << endl;
	
	return 0;
}