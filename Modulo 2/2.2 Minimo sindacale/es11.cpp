// La Corte Lorenzo - Es. 11

// Scrivere un programma che legge un numero intero compreso fra 1 e 12 e stampa il nome del mese corrispondente (1==gen- 
// naio. . . ). Se il numero non è compreso fra 1 e 12 stampa un messaggio di errore ed esce.

#include <iostream>
using namespace std;

int main()
{
int mese;

cout << "Inserisci il numero del mese: " << endl;
cin >> mese;

switch (mese)
{
	case 1 :
		cout << "È Gennaio." << endl;
		break;

	case 2 :
		cout << "È Febbraio." << endl;
		break;

	case 3 :
		cout << "È Marzo." << endl;
		break;

	case 4 :
		cout << "È Aprile." << endl;
		break;

	case 5 :
		cout << "È Maggio." << endl;
		break;

	case 6 :
		cout << "È Giugno." << endl;
		break;

	case 7 :
		cout << "È Luglio." << endl;
		break;

	case 8 :
		cout << "È Agosto." << endl;
		break;

	case 9 :
		cout << "È Settembre." << endl;
		break;

	case 10 :
		cout << "È Ottobre." << endl;
		break;

	case 11 :
		cout << "È Novembre." << endl;
		break;

	case 12 :
		cout << "È Dicembre." << endl;
		break;

	default:
		cout << "Inserisci un numero da 1 a 12." << endl;
}

return 0;
}