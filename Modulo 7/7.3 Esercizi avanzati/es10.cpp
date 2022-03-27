// Es.10 - Lorenzo La Corte 
// Scrivere una funzione isUpper che presa una matrice quadrata di caratteri 
// restituisce true se tutti gli elementi contenuti 
// sono lettere maiuscole, cioè caratteri nell’intervallo [ ' A ' , ' Z ' ] , 
// false altrimenti usando l’aritmetica dei puntatori per scorrere la matrice

#include <iostream>
using namespace std;


const int N=10;

bool isUpper(char matrice[10])
{
 	return true;		
}

int main()
{
	//creo la matrice
	char matrice[N][N];
	char carattere = 'A';

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			matrice[i][j]=carattere;
			carattere++;	
		}
	carattere='A';			
	}

	// stampo la matrice
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << matrice[i][j] << " ";		
		}
	cout << endl;		
	}

	cout << endl;
	
	// sono tutte maiuscole??
	bool a = isUpper(matrice);
	cout << a <<  endl;
	
}