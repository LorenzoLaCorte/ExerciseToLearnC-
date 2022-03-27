// Es.5 - Lorenzo La Corte
// Modificare il programma che legge N valori reali, 
// li memorizza in un array di lunghezza N , 
// e ne restituisce la media richiesto
// dall’esercizio 4 della sezione 4 usando l’aritmetica dei puntatori 
// per migliorarne l’efficienza, secondo il seguente schema

#include <iostream>
using namespace std;

int main()
{
	// dichiarare una costante N di tipo int inizializzata ad un valore...
	// ... strettamente maggiore di 0
	const int N = 5;
	// dichiarare un array v di N interi
	int v[N];
	// dichiarare un puntatore a interi p inizializzato con v
	int *p = v;
	
	cout<< "Inserire una serie di valori interi:" << endl;
	// iterare su i a partire da 0 e fino a N-1
	for (int i=0; i<N; i++)
	{
		// - leggere un valore intero memorizzandolo nella cella puntata da p
		cin >> *p;		
		// - incrementate p
		p++;
	}
	// dichiarare una variabile sum di tipo float e inizializzarla a zero
	float sum = 0;
	// assegnare v a p (per ricominciare da capo a scorrere v)
	p = v;
	// iterare su i a partire da 0 e fino a N-1
	for (int i=0; i<N; i++)
	{	
		// - sommare il contenuto della cella puntata da p a sum
		sum = sum + *p;
		p++;
	}
	// stampare la divisione di sum per N
	cout << "La Media è: " << (sum/N) << endl;
}