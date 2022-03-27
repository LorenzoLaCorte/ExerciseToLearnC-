#include "list.h"
#include <iostream>

using namespace std;

struct cell {
	double info;
	cell * next;
};

typedef cell * list;

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
	cin >> f1;	
	push_back(l, f1);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout << "Inserisci un valore:" << endl;
	cin >> f1;
	cout << "Inserisci una posizione nell'array:" << endl;
	cout << "(L'elemento sara' inserito nella posizione immediatamente successiva)" << endl;
	int pos;
	cin >> pos;
	insert_after(l, f1, pos);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout << "Inserisci la posizione da cui eliminare un elemento:" << endl;
	cin >> pos;
	remove(l, pos);
	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout << "La tua lista ha " << length(l) << " elementi." << endl;

	cout << "Inserisci un valore da eliminare:" << endl;
	cin >> f1;

	if(is_present(l, f1))
	{
		cout << "Il primo elemento con questo valore precede quello con valore ";
		if(find_first(l, f1)->next == nullptr)
			cout << "nullo, perché l'elemento successivo è inesistente." << endl;
		else
			cout << ((find_first(l, f1))->next)->info << endl;

		remove_cont(l, f1);
		cout << "La mia lista è: " << endl;
		printlist(l);
		cout << endl << endl;
	}
	else
		cout << "L'elemento inserito non e' presente nella lista" << endl << endl;

	cout << "Inserisci la posizione da cui vuoi acquisire il valore:" << endl;
	cin >> pos;

	if(at(l, pos) == nullptr)
		cout << "In posizione " << pos << " non vi e' il valore."  << endl;
	else
		cout << "In posizione " << pos << " vi e' il valore " << at(l, pos)->info << endl;

	cout << endl << endl;

	cout << "La tua lista invertita è: " << endl;
	reverse(l);
	printlist(l);
	cout << endl << endl;

	cout << "Inserisci un elemento nella tua lista: " << endl;
	cin >> f1;
	ordered_insert(l, f1);
	cout << "La tua lista ordinata con il nuovo elemento è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout<<"Elimino i doppioni consecutivi: "<<endl;
	unique(l);
	printlist(l);
	cout<<endl << endl;

	list ll = nullptr;
	cout<<"Crea una NUOVA lista: " <<endl << endl;
	cout<<"Inserisci il numero di elementi: " << endl;
	int n_elem;	
	cin >> n_elem;

	for(int i=0; i<n_elem; i++)
	{
		cout<<"Elemento " << i << ": ";
		cin >> f1;
		push_back(ll, f1);
	}

	l =merge(l, ll);

	cout << "La mia lista è: " << endl;
	printlist(l);
	cout << endl << endl;

	cout << "Cerca un elemento che dista pos a partire dal fondo:" << endl;
	cout << "Inserisci pos:" << endl;
	cin >> pos;
	cell * res = nth_from_last(l, pos);

	if(res == nullptr)
		cout << "pos è maggiore del numero di elementi presenti o la lista è vuota" << endl;
	else
	{
		cout << "L'elemento che dista " << pos << " dalla fine è ";
		cout << res->info << endl;
	}

}

