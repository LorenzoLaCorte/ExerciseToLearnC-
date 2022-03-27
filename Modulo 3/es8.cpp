#include <iostream>
using namespace std;

int main
{
	// stampare la stringa "Inserire un numero positivo: "
	cout << "Inserire un numero positivo: " << endl;
	// dichiarare una variabile intera k
	int k;
	// leggere k
	cin >> k;
	// se k è minore di zero
	if (k < 0)
	{
		// - stampare "Valore non valido"
		cout << "Valore non valido" << endl;
		// - uscire dal programma ritornando il codice di errore 666
		return 666;
	}
	
	// stampare su una nuova riga la stringa "Rovesciando " seguita da k
	cout << "Rovesciando " << k << endl;
	// dichiarare una variabile intera inv inizializzata a zero
	int inv = 0;
	/* finché k è maggiore di zero
	- dichiarare una variabile intera mod inizializzata con il resto della...
	... divisione intera di k per 10
	- assegnare a k il quoziente di k per 10
	- assegnare a inv la moltiplicazione di inv per 10
	- assegnare a inv la somma di inv e mod
	*/
	while (k > 0)
	{
		int mod = k % 10;
		k = k / 10;
		inv = inv * 10;
		inv = inv + mod;
	}
	
	// stampare la stringa " si ottiene " seguita da inv
	cout << " si ottiene " << inv << endl;

}