// Es 9 - Lorenzo La Corte
// Scrivere una funzione isUpper 
// che presa una matrice quadrata di caratteri 
// restituisce true se tutti gli elementi contenuti sono lettere maiuscole, 
// cioè caratteri nell’intervallo [ ' A ' , ' Z ' ] , 
// false altrimenti 
// usando l’aritmetica dei puntatori per scorrere la matrice.

/* [SUGGERIMENTO: Un array bidimensionale è un array di array; 
siccome gli elementi di un array sono memorizzati tutti di seguito, 
questo vuol dire anche gli elementi di un array bidimensionale sono memorizzati 
tutti di seguito; quindi per scorrere tutti gli elementi di un vettore bidimensionale
basta un unico puntatore incrementato sempre di uno
anche per passare da una riga alla successiva] 
[SUGGERIMENTO: Per inizializzare un puntatore all’indirizzo del primo
elemento di un array basta assegnargli l’ array stesso. 
Nel caso bidimensionale, però questo vuol dire avere un puntatore
al tipo array interno e non all’elemento della matrice. 
Per ottenere un puntore al tipo della singola cella, quindi, bisogna
assegnare al puntatore il primo elemento dell’ array . ]
*/

#include <iostream>
using namespace std;

// Scrivere una funzione isUpper 
// che presa una matrice quadrata di caratteri 
// restituisce true se tutti gli elementi contenuti sono lettere maiuscole, 
// cioè caratteri nell’intervallo [ ' A ' , ' Z ' ] , 
// false altrimenti 
// usando l’aritmetica dei puntatori per scorrere la matrice.
bool isUpper(char v[][5])
{
	char * p = v[0];
	for(int i=0; i<5*5; i++)
	{
		// usando l’aritmetica dei puntatori per scorrere la matrice.
		// guardo se l'elemento puntato non è una lettera maiuscola
		if(*(p+i)>='A' && *(p+i)<='Z') 
			// restituisco false 
			return false;
	}
	
	// restituisco true
	return true;
}

int main()
{
	char bidim1[5][5];
	char bidim2[5][5];
	char tmp1='A';
	char tmp2='a';

	for(int i=0; i<5; i++)
	{
		for(int k=0; k<5; k++)
		{
			bidim1[i][k] = tmp1;
			bidim2[i][k] = tmp2;
			tmp1++;
			tmp2++;					
		}
		tmp1='A';
		tmp2='a';
	}

	cout << "Stampo Array1:" << endl << endl;

	for(int i=0; i<5; i++)
	{
		for(int k=0; k<5; k++)
		{
			cout << bidim1[i][k] << " ";	
		}	
		cout << endl;
	}

	cout << endl;

	cout << "Stampo Array2:" << endl << endl;

	for(int i=0; i<5; i++)
	{
		for(int k=0; k<5; k++)
		{
			cout << bidim2[i][k] << " ";	
		}	
		cout << endl;
	}

	cout << endl;
	
	cout << "Array1 è costituito da sole lettere maiuscole? ";
	cout << boolalpha << isUpper(bidim1) << endl;

	cout << "Array2 è costituito da sole lettere maiuscole? ";
	cout << boolalpha << isUpper(bidim2) << endl;

	return 0;
}