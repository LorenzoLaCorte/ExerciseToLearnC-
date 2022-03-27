#include <iostream>
using namespace std;

int main
{
	// dichiarare una variabile how_many di tipo int
	int how_many;
	// stampare la stringa "Di quanti numeri vuoi fare la media?"
	cout << "Di quanti numeri vuoi fare la media?" << endl;
	// leggere how_many
	cin >> how_many;
	// se how_many non è strettamente positivo
	if (how_many < 0)
	{
		// - stampare "Errore: il numero doveva essere positivo"
		cout << "Errore: il numero doveva essere positivo" << endl;
		// - uscire dal main ritornando il codice di errore 42
		return 42;
	}
	// dichiarare una variabile sum di tipo float inizializzata a 0
	float sum = 0;
	float x;
	/* iterare how_many volte le seguenti istruzioni

	- stampare un a capo seguito dalla stringa "Inserisci un numero "
	- dichiarare una variabile x di tipo float
	- leggere x
	- assegnare a sum la somma di sum e x
	*/
		while (how_many)
	{
				cout << "Inserisci un numero " << endl;
				cin >> x;
				sum = sum + x;
	}
			
	// stampare un a capo seguito dalla stringa "La media è "
	cout << "La media è " << endl;
	// stampare la divisione di sum per how_many
	cout << sum / how_many << endl;
	
	
	
	
}