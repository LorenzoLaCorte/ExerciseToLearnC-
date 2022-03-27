#include "Text.h"

// funzione che dato un text ed una std::string , cerca la stringa nel testo. 
// Se la trova, nella variabile intera pos va
// a mettere la posizione della parola nel testo e restituisce true, 
// altrimenti restituisce false .
bool findWord ( const text mytext , const std :: string myWord , int & pos )
{
	// Definire un puntatore a word_cell che si chiama current 
	// e farlo puntare alla testa della lista (= mytext )
	word_cell * current = mytext;
	// Inizializzare pos a zero
	pos = 0;
	// finche ` current e ` diverso dal puntatore nullo e la parola 
	// nel campo word della cella puntata da current e ` diversa da myWord
	while(current!=nullptr && current->word != myWord)
	{
		// incrementa pos di 1
		pos++;
		// fai puntare current al campo next di current stesso
		current = current->next;
	}
	// restituisci il risultato dell ' espressione 
	// "current diverso dal puntatore nullo"
	return (current!=nullptr);
}

// funzione che, data una std::string, 
// elimina tutte le occorrenze della stringa nel testo, 
// se presente, e restituisce true; 
// altrimenti lascia il testo inalterato e restituisce false .

bool removeWordFromText(text& mytext, const std::string myWord)
{
	bool presente = false;
	word_cell * curr = mytext;

	while(curr->next != nullptr)
	{
		// se trovo myWord
		if(curr->info == myWord)
		{
			// elimina tutte le occorrenze della stringa nel testo, 
			// e pone presente a true; 
		}

		// altrimenti 
		else
		{
			// lascia il testo inalterato 
		}

		// avanzo curr
		curr = curr -> next;
	}
	return presente;
}