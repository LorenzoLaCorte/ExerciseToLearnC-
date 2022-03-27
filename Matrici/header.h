// Team 19

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Struttura Dati Matrix:
// Rappresenta una matrice densa.

// Matrix è la matrice densa
struct Matrix
{
	vector<vector<double> > store; // informazioni
	int nc; // numero colonne	
	int nr; // numero righe
};

// Strutture Dati SparseEntry e SparseMatrix:
// Rappresentano una matrice sparsa come lista collegata semplice.

// SparseEntry è un elemento di una matrice sparsa: 
struct SparseEntry{
	int r; // la posizione (riga) dell'elemento
	int c; // la posizione (colonna) dell'elemento
	double val; // il valore dell'elemento
	SparseEntry *next; // puntatore al prossimo elemento (lista)
};

// SparseMatrix è la matrice sparsa
struct SparseMatrix{
	SparseEntry *store; // punta alla lista degli elementi
	int nr; // numero di righe
	int nc; // numero di colonne
	int nnz; // numero di elementi non nulli
};

Matrix matrix(const vector<double> &v, const int nr, const int nc);

void printFullMatrix(const Matrix &m);

bool iszero(double val);

SparseMatrix sparse(const Matrix &m);

Matrix full(const SparseMatrix &s);

SparseMatrix removeEntry(const SparseMatrix &s, const int r, const int c);

SparseMatrix setEntry(const SparseMatrix &s, const double val, const int r, const int c);

double getEntry(const SparseMatrix &s, const int r, const int c);

void printSparseMatrix(const SparseMatrix &s);

