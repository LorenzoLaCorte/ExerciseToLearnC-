#include "list.h"
#include <iostream>

using namespace std;

struct cell {
	double info;
	cell * next;
};

typedef cell * list;

// Creazione di un puntatore a una nuova cella con contenuto cont
// e corretta inizializzazione di next
cell * newcell(const double cont)
{
	// Dichiarare una variabile di double puntatore a cell, 
	// allocandola immediatamente con l ' operatore new
	cell * l= new cell;
	// Assegnare cont al membro info della variabile
	l->info = cont;
	// Assegnare nullptr al membro next della variabile
	l->next = nullptr;
	// restituire la variabile
	return l;
}

// Aggiunta di un elemento in testa alla lista, con contenuto cont
list push_front(list & mylist, const double cont)
{
	// Dichiarare una variabile temp di double puntatore a cell, 
	// allocandola immediatamente con la funzione newcell(cont)
	cell * temp = newcell(cont);
	// assegnare mylist al membro next di temp
	temp -> next = mylist;
	// assegnare temp a mylist
	mylist = temp;
	// restituire mylist
	return mylist;
}

// Aggiunta di un elemento in coda alla lista, con contenuto cont
list push_back(list & mylist, const double cont)
{
	// dichiarare una variabile cur di double puntatore a cella 
	// e inizializzarla a mylist
	cell * cur = mylist;
	// dichiarare una variabile temp di double puntatore a cell, 
	// allocandola immediatamente con la funzione newcell(cont)
	cell * temp = newcell(cont);

	// se mylist e ' nullptr,
	if(mylist == nullptr) 
		//assegnare temp a mylist
		mylist = temp;
	// altrimenti:
	else
	{
		// finche ' il membro next di cur non e ' nullptr
		while(cur -> next != nullptr)
		{
			// assegnare a cur il valore del suo membro next
			cur = cur -> next;
		}
		// assegnare temp all'elemento next di cur
		cur -> next = temp;
	}	
	// restituire mylist
	return mylist;
}

// Aggiunta di un elemento con contenuto cont alla lista 
// in posizione immediatamente successiva all’elemento numero n,
// oppure in coda se n maggiore della lunghezza della lista:
list insert_after(list mylist, double cont, int n)
{
	// dichiarare una variabile cur di double puntatore a cella 
	// e inizializzarla a mylist
	cell * cur = mylist;
	// dichiarare una variabile temp di double puntatore a cell, 
	// allocandola immediatamente con la funzione newcell(cont)
	cell * temp = newcell(cont);
	// se cur e ' nullptr, 
	if(cur == nullptr)
		// assegnare temp a mylist
		mylist = temp;
	// altrimenti:
	else
	{
		// finche ' il membro next di cur non e ' nullptr e n non e ' zero
		while(cur -> next != nullptr && n != 0)
		{		
			// assegnare a cur il valore del suo membro next
			cur = cur -> next;
			// decrementare n
			n--;
		}
		// assegnare l ' elemento next di cur all ' elemento next di temp
		temp -> next = 	cur -> next;
		// assegnare temp all ' elemento next di cur
		cur -> next = temp;
	}
	// restituire mylist
	return mylist;
}

// Eliminazione di tutti gli elementi da una lista.
list clear(list mylist)
{
	// se mylist non e ' nullptr:
	if(mylist != nullptr)	
	{
		// assegnare al membro next di mylist 
		// il risultato della chiamata clear(mylist->next)
		mylist -> next = clear(mylist->next);
		// deallocare (delete) mylist
		delete mylist;		
		// assegnare nullptr a mylist
		mylist = nullptr;	
	}
	// restituire mylist
	return mylist;
}

// stampa una lista in modo ricorsivo
void printlist(const list &mylist)
{
	if(mylist == nullptr) //passo base, lista vuota
		return;

	else //passo induttivo
	{
		cout << mylist->info << " ";
		printlist(mylist->next);
	}
}

// funzione che restituisce il numero di elementi di mylist, zero se vuota.
int length(list mylist)
{
	cell * cur = mylist;
	int cont = 0;

	while(cur != nullptr)
	{
		cur = cur->next;
		cont++;
	}
	
	return cont;
}

// funzione che elimina l’elemento in posizione n se presente
// (ovvero se la lista ha almeno n+1 elementi), 
// e restituisce la lista aggiornata.
list remove(list & mylist, int n)
{
	cell * cur = mylist;
	cell * prev = mylist;
	// se la lista ha almeno n+1 elementi
	for(int i=0; i<n; i++)
	{
		prev = cur;
		cur = cur->next;
		
		if(cur==nullptr)
		{		
			cout << "In questa posizione non e' presente nessun elemento." << endl;
			return mylist;

		}
	}

	// -  elimina l’elemento in posizione n
	// gestisco il caso in cui devo eliminare il primo
	if(cur == prev)
	{
		mylist = mylist->next;
		delete cur;
		cur = mylist;
		prev = mylist;
	}
	// gestisco gli altri casi
	else 	
	{
		prev->next = cur->next;
		delete cur;
		cur = prev->next;
	}	

	// e restituisce la lista aggiornata.
	return mylist;
}

// funzione che elimina tutti gli elementi il cui membro info contiene cont, 
// se ce ne sono, e restituisce la lista aggiornata.
list remove_cont(list & mylist, double cont) 
{
	
	cell * cur = mylist;
	cell * prev = mylist;

	// scorre la lista
	while(cur != nullptr)
	{
		// elimina tutti gli elementi il cui membro info contiene cont
		if(cur->info == cont)
		{
			// gestisco il caso in cui devo eliminare il primo
			if(cur == prev)
			{
				mylist = mylist->next;
				delete cur;
				cur = mylist;
				prev = mylist;

			}
			// gestisco gli altri casi
			else 	
			{
				prev->next = cur->next;
				delete cur;

				// se l'elemento da eliminare e' l'ultimo devo evitare
				// che vada in segmentation fault
				// allo stesso tempo, se non e' l'ultimo devo aggiornare
				// cur in caso di piu' occorrenze:		
				if(prev->next !=nullptr)
					cur = prev->next;
			}
		}


		prev = cur;
		cur = cur->next;
			
	}	
	// restituisce la lista aggiornata
	return mylist;
}

// funzione che restituisce true se il valore cont è presente nella lista mylist, 
// false altrimenti.
bool is_present(list mylist, double cont)
{
	// guardo se il valore cont è presente nella lista mylist:

	cell * cur = mylist;
	cell * prev = mylist;

	// ciclo fino a nullptr
	while(cur != nullptr)
	{
		// - se trovo una cella (cur) con info uguale a cont
		if(cur->info == cont)	
			// - restituisco true
			return true;
		// - mando avanti prev e cur
		prev = cur;
		cur = cur ->next;
	}

	// restituisco false
	return false;
}

// funzione che cerca il primo elemento il cui membro info contiene cont 
// e restituisce il puntatore a tale elemento; 
// nullptr se non trovato.
cell * find_first(list & mylist, double cont)
{
	// cerco il primo elemento il cui membro info contiene cont

	cell * cur = mylist;
	cell * prev = mylist;

	// ciclo fino a nullptr
	while(cur != nullptr)
	{
		// e restituisce il puntatore a tale elemento; 
		if(cur->info == cont)	
			// - restituisco
			return cur;
		// - mando avanti prev e cur
		prev = cur;
		cur = cur ->next;
	}

	// restituisco false
	return nullptr;
}

// funzione che restituisce l’elemento numero n della lista mylist,
// oppure nullptr se n è maggiore del numero di elementi presenti 
// o la lista è vuota.
cell * at(list mylist, int n)
{
	cell * cur = mylist;

	for(int i=0; (i<n); i++)
	{
		if(cur == nullptr)
			return nullptr;
		else
			cur = cur->next;
	}

	return cur;
}

void reverse(list & mylist)
{
	cell * cur = mylist;
	cell * last = mylist;
	int len = length(mylist);
	
	for(int i=0; i<(len/2); i++)
	{
		for(int j=0; j<(len-1); j++)
		{
			last = last->next;
		}
		
		double aux= cur->info;
		cur->info=last->info;
		last->info=aux;

		cur = cur->next;
		last=mylist;
	}
}


// funzione che restituisce la lista mylist ordinata.
void sort(list & mylist)
{
	// ORDINO LA LISTA:

	int len = length(mylist);

	for(int i=0; i<len; i++)
	{
		// dichiaro 2 puntatori prev e curr a mylist
		cell * prev = mylist;
		cell * cur = mylist;
		cur = cur -> next;

		// scorro la lista:
		// ciclo finche cur != nullptr
		while(cur != nullptr)
		{
			// - se info di cur < info di prev
			if(prev->info > cur->info)
			{
				// -- li scambio
				double aux = cur -> info;
				cur -> info = prev -> info;
				prev -> info = aux;
			}
			// - prev = cur
			prev = cur;
			// - cur = cur -> next;
			cur = cur -> next;
		}
	}
}

// funzione  che inserisce un nuovo elemento,
// con contenuto cont,
// in posizione ordinata
// e restituisce la lista aggiornata.
void ordered_insert(list & mylist, double cont)
{
	// INSERISCO IL NUOVO ELEMENTO in testa:
	// chiamo la funzione di inserimento in testa
	push_front(mylist, cont);

	sort(mylist);
}

list unique(list & mylist)
 {
	 // dichiaro 2 puntatori prev e curr a mylist
	cell * prev = mylist;
	cell * cur = mylist;
	cur = cur -> next;
	int pos = 0;
	// scorro la lista:
	// ciclo finche cur != nullptr
	while(cur != nullptr)
	{
		// - se info di cur < info di prev
		if(cur->info == prev -> info)
		{
			// elimino cur
			remove(mylist,pos);
		}
		// - prev = cur
		prev = cur;
		// - cur = cur -> next;
		cur = cur -> next;
		pos++;
	}
 }

// funzione che assume che le liste mylist1 e mylist2 siano ordinate, 
// e crea una terza lista contenente il contenuto delle due liste, sempre ordinato. 
// Restituisce la terza lista.
list merge(list mylist1, list mylist2)
{
	list mylist3=nullptr;

	// fa tante iterazioni quanto la somma delle lunghezze di mylist1 e mylist2
	while(mylist1 != nullptr)
	{
		// - usa ordered_insert()
		ordered_insert(mylist3, mylist1->info);
		mylist1 = mylist1->next;

	}

	while(mylist2 != nullptr)
	{
		// - usa ordered_insert()
		ordered_insert(mylist3, mylist2->info);
		mylist2 = mylist2->next;
	}
	
	return mylist3;
}

// funzione che restituisce un puntatore all’elemento che dista n posizioni dall’ultimo, 
// oppure nullptr se n è maggiore del numero di elementi presenti o la lista è vuota.

cell * nth_from_last(list mylist, double n)
{
	int len = length(mylist);

	// restituisce nullptr se n è maggiore del numero di elementi presenti
	// o la lista è vuota
	if(n > len || mylist ==  nullptr)
		return nullptr;

	// restituisce un puntatore all’elemento che dista n posizioni dall’ultimo:
	// dichiaro cur
	cell * cur = mylist;
	// dichiaro aux	
	cell * aux = mylist;
	// scorro cur di n
	for(int i=0; i<n; i++)
		cur = cur->next;
	 
	// faccio scorrere fino a nullptr
	while(cur != nullptr)
	{
		// sia il cursore principale
		cur = cur->next; 
		// che questo secondo cursore
		aux = aux->next;
	}
	
	return aux;
}
