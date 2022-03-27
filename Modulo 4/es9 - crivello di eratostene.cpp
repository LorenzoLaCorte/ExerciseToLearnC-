// Es.9 - Lorenzo La Corte
// CRIVELLO DI ERATOSTENE

#include <iostream>

using namespace std;

int main()
{

	// 1) Creare un array di bool chiamato isprime di lunghezza n
	int n=1000;
	bool isprime[n], finita=false;
	// 2) Inizialmente, sia p pari a 2, il numero primo più piccolo.
	int p = 2;
	// inizializza isprime a tutti valori true.
	for (int i=0; i<n; i++)
	{
		isprime[i]=true;
	}

	while (!finita)
	{
		finita = true;
		// 3) Partendo da p escluso, marcare come NON PRIMI tutti i numeri multipli di p
		for (int i=p; i<n/p; i++)
		{
			isprime[i*p] = false;
		}
		// 4) Partire da p=p+1 e scorrere in avanti l'array isprime finché non si trova il primo numero
		// NON marcato (isprime[p] è true), oppure finché non è finita la lista
		// 5) Se la lista è finita, stop. Altrimenti p diventa pari al numero trovato
		for (int i=p+1; i<n; i++)
		{
			if (isprime[i] == true)
			{
				p = i;
				finita = false;
				break;
			}
		}
	}

	// Stampare tutti i numeri tali che il corrispondente elemento di isprime e’ true.
	cout << "I numeri primi minori di 1000 sono:" << endl;
	for (int i=2; i<n; i++)
	{
		if (isprime[i] == true)
		{
			cout << i << "\t";
		}
	}
}
