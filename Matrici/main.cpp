// Team 19

#include "header.h"

int main()
{
	Matrix m; // dichiaro una matrice densa
	Matrix s; // dichiaro una matrice densa
	SparseMatrix j; // dichiaro una matrice sparsa
	vector<double> t; // dichiaro un vettore per riempire m
	int nr = 3; // dichiaro e assegno il numero di righe
	int nc = 5; // dichiaro e assegno il numero di righe

	m = matrix(t, nr, nc); // creo una matrice densa

	cout << endl << "Stampo la Matrice Densa: ";
	printFullMatrix(m); // stampo la matrice densa

	cout << endl << "Converto la Matrice Densa in Sparsa." << endl;
	j = sparse(m); // converte la matrice densa m in una matrice sparsa j

	// stampo valore, riga e colonna dei valori della Matrice Sparsa
	cout << "Stampo valore, riga e colonna dei valori della Matrice Sparsa: " << endl << endl;
	SparseEntry* test = j.store;
	while(test->next != nullptr)
	{
		cout << "| " << test->val << ", " << test->r << ", " << test->c << " |" << endl;

		test = test->next;
	}

	cout << endl << endl << "Converto la Matrice Sparsa in Densa." << endl;
	s = full(j); // converte la matrice densa j in una matrice sparsa s

	cout << "Stampo la Matrice Densa: ";
	printFullMatrix(s); // stampo la matrice densa

	int r; // dichiaro intero riga per inserimento utente
	int c; // dichiaro intero colonna per inserimento utente

	cout << endl << "PROVA DELLA REMOVE ENTRY" << endl;
	cout << "Inserisci la posizione (r,c) del valore da eliminare: ";
	cin >> r >> c;
	cout << endl;
	
	j = removeEntry(j, r, c); // rimuovo il valore in posizione (0,2)

	// stampo valore, riga e colonna dei valori della Matrice Sparsa aggiornata
	cout << "Stampo la Matrice Sparsa aggiornata:" << endl << endl;
	test = j.store;
	while(test-> next != nullptr)
	{
		cout << "| " << test->val << ", " << test->r << ", " << test->c << " |" << endl;

		test = test->next;

	}
	cout << endl;

	int v; // dichiaro intero valore per inserimento utente

	cout << endl << "PROVA DELLA SET ENTRY" << endl;
	cout << "Inserisci il valore da inserire: ";
	cin >> v;
	cout << endl;
	cout << "Inserisci la posizione (r,c) del valore da inserire: ";
	cin >> r >> c;
	cout << endl;

	try{
		j = setEntry(j, v, r, c);

		// stampo valore, riga e colonna dei valori della Matrice Sparsa aggiornata
		cout << "Stampo la Matrice Sparsa aggiornata:" << endl << endl;
		test = j.store;
		while(test-> next != nullptr)
		{
			cout << "| " << test->val << ", " << test->r << ", " << test->c << " |" << endl;
			test = test->next;

		}

		double valore;

		valore = getEntry(j , r, c);

		cout << endl << "Il valore alla posizione " << r << "," << c << " è " << valore << endl << endl;

		printSparseMatrix(j);
		cout << endl;
	}
	catch(int errore)
	{
		if(errore == -1)
			cout << "Hai inserito una riga e/o una colonna inesistente." << endl;
	}
}