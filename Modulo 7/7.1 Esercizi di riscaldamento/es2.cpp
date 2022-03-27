// Es.2 - Lorenzo La Corte
// Riprendete la vostra implementazione della funzione reverse dell’esercizio 8
// in sezione 4 e provate a modificare il programma di test utilizzando
// source per instanziare entrambi i parametri di reverse . 
// Se avete implementato reverse nel modo ovvio, non otterrete il risultato atteso,
// perché copiando gli elementi dalla testa di source nella coda di dest 
// in realtà state modificando la coda di source stesso. 
// Per evitare questo problema, vogliamo premettere al corpo della funzione reverse
// il controllo che i due parametri corrispondano ad aree di memoria distinte
//  e se invece coincidono sollevare un’eccezione.

// Modificare il programma di test in modo che esegua la chiamata 
// reverse(source, source) e che venga catturata l’eccezione
// (stampate un messaggio di errore che dice che non si può chiamare reverse usando 
// la stesso parametro attuale per entrambii parametri formali).

#include <iostream>
using namespace std;

const int N = 5;

void reverse(const int source[N], int dest[N]) 
{
	// se indirizzo di source uguale a indirizzo di dest....
	// ...sollevare eccezione di tipo a vostra scelta
	if (&source == &dest)
	{
		throw 0;
	}
	
	for (int i = 0; i < N; ++i) 
	{
		dest[N - 1 - i] = source[i];
	}
}

int main()
{
	try
	{
		int a[N];
		int b[N];
		
	for(int i=0; i<N; i++)
	{
		cout << "Inserisci valore " << i << ": ";
		cin >> a[i];
		cout << "\n\n";
	}
	
	reverse(a,b);
	
	for(int i=0; i<N; i++)
	{
		cout << "Il valore " << i << " inverso e': " << b[i] << endl;
	}
	
	}
	catch(int errore)
	{
		if(errore == 0)
			cout << "Non si pu� chiamare reverse usando la stesso parametro attuale per entrambi i parametri formali" << endl;
	}
}
