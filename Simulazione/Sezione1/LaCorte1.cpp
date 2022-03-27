#include "array.h"

bool isSorted(const int a[], const int n)
{
	// se n e ` minore o uguale a 2,
 	if(n<=2)
		// restituisci true
		return true;
	// crea due variabili booleane " crescente " e " decrescente " 
	// inizializzate a true
	bool crescente = true;
	bool decrescente = true;

	// per i da 1 a n ( escluso ):
	for(int i=1; i<n; i++)
	{
		// se elemento i -1 di a > elemento i di a :
		if(a[i-1] > a[i])
			// poni a false la variabile " crescente "
			crescente = false;
		// altrimenti se elemento i -1 di a < elemento i di a :
		else if(a[i-1] < a[i])
			// poni a false la variabile " decrescente "
			decrescente = false;	
	}	
	// se " crescente " e ` true oppure " decrescente " e ` true ,
	if(crescente || decrescente)
		// restituisci true 
		return true;
	// altrimenti 
	else
		// restituisci false
		return false;

}

// funzione che riceve in ingresso un array di interi a,
// ordinato in senso debole (possibili elementi duplicati),
// e la sua lunghezza n.
// La funzione rimuove da a tutti i numeri duplicati, 
// e restituisce la nuova lunghezza dell’array, ovvero
// il numero di elementi rimasti dopo avere eliminato i duplicati.
int removeDuplicates(int a[], const int n)
{
	int cont = n;
	// rimuove da a tutti i numeri duplicati:
	// ciclo i da 0 a n escluso
	for(int i=0; i<n; i++)
	{
		// ciclo j da i+1 a cont escluso
		for(int j=i+1; j<cont; j++)
		{			
			// se a[i] == a[j]
			while(a[i] == a[j])
			{
				// elimino elemento:
				// ciclo k da j a cont
				for(int k=j; k<cont; k++)
				{
					// a[k] = a[k+1]
					a[k] = a[k+1];
				}	
			// decrementa cont
			cont--;			
			}
		}
	}
	// restituisce la nuova lunghezza dell’array
	return cont;
}

