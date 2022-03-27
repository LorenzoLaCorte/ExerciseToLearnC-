/* Scrivere un programma che scrive in lettere i nomi italiani delle ore, approssimati per difetto a 15 minuti. Il programma deve
prendere in input due valori interi, uno tra 1 e 12 (ore) e l’altro tra 0 e 59 (minuti) e se i valori dati in input non rispettano
il vincolo stampa un messaggio di errore ed esce ritornando -1 come codice di errore. Se l’input è corretto, scrive “Sono le
ore " seguito dal valore delle ore (p.es. se è 11 scrive “undici", ma se è 1 scrive “una") e dal valore dei minuti, approssimato
al quarto d’ora (p.es. se è 18 scrive “ e un quarto", se è 39 scrive “ e mezza", se è 55 scrive “ e tre quarti"; se è 0 invece non
scrive niente). Infine, se i minuti non sono divisibili esattamente per 15, scrive “ circa".
*/

#include <iostream>
using namespace std;

int main()
{
int ora, min;

// input ora e minuti e verifica
cout << "Inserisci l'ora (un numero intero da 1 a 12)" << endl;
cin >> ora;

cout << "Inserisci i minuti (un numero intero da 1 a 59)" << endl;
cin >> min;


if (ora > 0 && ora < 13 && min > 0 && min < 60)
{
	if (ora > 1 && ora < 13)
		cout << "Sono le ";
	
	if (ora == 1)
		cout << "E' l'";

	// switch per le ore
	switch (ora)
	{
		case 1:
			cout << "una";
			break;
			
		case 2:
			cout << "due";
			break;
		
		case 3:
			cout << "tre";
			break;
			
		case 4:
			cout << "quattro";
			break;
			
		case 5:
			cout << "cinque";
			break;
			
		case 6:
			cout << "sei";
			break;
			
		case 7:
			cout << "sette";
			break;
			
		case 8:
			cout << "otto";
			break;
			
		case 9:
			cout << "nove";
			break;
			
		case 10:
			cout << "dieci";
			break;
			
		case 11:
			cout << "undici";
			break;
			
		case 12:
			cout << "dodici";
			break;	
	}
	// if per i minuti
	
	if (min > 0 &&  min < 15)
		cout << ", circa." << endl;
		
	if (min > 15 &&  min < 30)
		cout << " e un quarto, circa." << endl;
		
	if (min == 15)
		cout << " e un quarto." << endl;
		
	if (min > 30 &&  min < 45)
		cout << " e mezza, circa." << endl;
		
	if (min == 30)
		cout << " e mezza." << endl;
		
	if (min > 45)
		cout << " e tre quarti, circa." << endl;
		
	if (min == 45)
		cout << " e tre quarti." << endl;

}	
else
{
	cout << "Inserisci dei valori validi." << endl;
}

return 0;
}