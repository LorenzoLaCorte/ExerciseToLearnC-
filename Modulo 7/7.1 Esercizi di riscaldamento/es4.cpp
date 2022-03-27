// Es.4 - Lorenzo La Corte
// Quando si passa un array come argomento ad una funzione, 
// il passaggio è per riferimento ovvero in realtà viene passato
// un puntatore all’indirizzo dove inizia l’ array ed è questa la ragione per cui 
// all’interno di una funzione non si conosce la dimensione dell’ array.
// Vediamo in pratica questo aspetto implementando il seguente programma

#include <iostream>
using namespace std;


// dichiarare una costante N di tipo int inizializzata ad un valore...
// ... strettamente maggiore di 0
// dichiarare la funzione

const int N=5;
void f(int vv[N]) 
{
	// stampare il messaggio "Dimensione del parametro == " seguito ...
	// ...dalla dimensione di vv e andare a capo
	cout << "Dimensione del parametro == " << sizeof(vv) << endl;
}

int main()
{

	// dichiarare un array v di N interi
	int v[N] = {1, 2, 3, 4, 5};
	// dichiarare un puntatore a interi p inizializzato con v
	int *p = v;
	// stampare il messaggio "Dimensione di v == " seguito ...
	// ...dalla dimensione di v e andare a capo
	cout << "Dimensione di v == " << sizeof(v) << endl;
	// stampare il messaggio "v ha dimensione " seguito dalla dimensione di v diviso...
	// ...la dimensione del suo primo elemento e andare a capo
	cout << "v ha dimensione == " << sizeof(v)/sizeof(v[0]) << endl;
	// stampare il messaggio "Dimensione di p == " seguito dalla dimensione di p ...
	// ... e andare a capo
	cout << "Dimensione di p == " << sizeof(p) << endl;
	// chiamare f su v
	f(v);
}