// Es. 1 - Lorenzo La Corte

// Scrivere un programma liste.cpp in cui si definisce un double “lista di double”
// (vedi cheatsheet, con typedef double double; ). 
// Quindi scrivere le funzioni seguenti, e un programma principale 
// che ne verifichi il funzionamento, stampando opportuni messaggi.

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

int main()
{
	// creo una lista composta da una cella
	list l = newcell(1.1);
	
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;
	
	cout << "Inserisci un valore in testa" << endl;
	double f1;
	cin >> f1;
	push_front(l, f1);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;


	cout << "Inserisci un valore in coda" << endl;
	double f2;
	cin >> f2;	
	push_back(l, f2);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout << "Inserisci un valore:" << endl;
	double f3;
	cin >> f3;
	cout << "Inserisci la posizione in cui inserirlo:" << endl;
	double pos;
	cin >> pos;
	insert_after(l, f3, pos);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	l = clear(l);
}


