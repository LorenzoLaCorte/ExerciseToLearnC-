#include <iostream>
using namespace std;

int main
{
	// dichiarare una variabile answer di tipo carattere
	char answer;
	/* ripetere
	- stampare la stringa "inserisci un numero intero positivo"
	- dichiarare una variabile n di tipo intero
	- leggere n
	- iterare su una variabile intera i a partire da 1 fino a n
	-- stampare `|'
	- stampare un'andata a capo
	- stampare su una nuova riga la stringa
	"inserisci s o S per terminare, qualsiasi altro carattere per proseguire"
	- leggere answer
	finché answer è diverso sia da `s' che da `S'
	*/
	do
	{
		cout << "inserisci un numero intero positivo" << endl;
		int n;
		cin >> n;
		
		for (int i=0; i<n; i++)
		{
			cout << "|" << endl << endl;
			cout << "inserisci s o S per terminare, qualsiasi altro carattere per proseguire" << endl;
		}
		
	} while (answer != 's' && answer != 'S');
	
	// stampare la stringa "ho terminato perchè hai inserito " seguita da answer
	cout << "ho terminato perchè hai inserito " << answer << endl;
	// che cosa succede se inserisci un numero negativo e perchè?

}