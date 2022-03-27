// Team 19

#include "header.h"

// Funzione che crea (e ritorna) una matrice densa m
// con nr: numero di righe e nc: numero di colonne 
// a partire da un vettore di valori v
Matrix matrix(const vector<double> &v, const int nr, const int nc)
{
	// definire una Matrix m
	Matrix m;
	// porre le sue dimensioni a nr e nc
	m.nc = nc;
	m.nr = nr;
	// ridimensionare il vector m.store alla dimensione nr
	m.store.resize(nr);
	
	for(int r=0; r<nr; r++)
	{
		// ridimensionare l'elemento r-esimo di m.store alla dimensione nc
		m.store[r].resize(nc);
	}

	// iterare r da 0  a nr-1 (scorro le righe)	
	for(int r = 0; r < nr; r++)
	{
		// iterare c da 0  a nc-1 (scorro le colonne)	
		for(int c = 0 ; c < nc; c++)
		{
			if(c+r*nc < v.size())
			{
				// inserisco l'elemento corretto del vettore v
				// nella matrice m
				m.store[r][c] =  v[c+r*nc];
			}
			// in caso il vettore fosse piú piccolo della matrice
			else 
			{
				// metto a 0 gli elementi in eccesso
				m.store[r][c] = 0;
			}
		}
	}

	// riempe la matrice con numeri (pseudo)casuali
	srand(time(0));
	for(int r = 0; r < nr; r++)
	{
		for(int c = 0 ; c < nc; c++)
		{
			m.store[r][c] = rand()%2;
		}
	}

	// ritorna la matrice aggiornata
	return m;
}

// Funzione che scorre una matrice densa e ne stampa i valori.
void printFullMatrix(const Matrix &m)
{
	cout << endl << endl;

	// scorre le righe
	for(int r = 0; r < m.nr; r++)
	{
		// scorre le colonne
		for(int c = 0; c < m.nc; c++)
		{
			// stampa l'elemento
			cout << "|" << " " << m.store[r][c] << " " << "|";
		}

		cout << endl;

		// formattazione
		for(int c = 0; c < m.nc; c++)
		{
			cout << "-----";
		}

		cout << endl;
	}

	cout << endl;
}

// Funzione che controlla che un valore sia nullo
// con una tolleranza di 10^-12
bool iszero(double val)
{
	static const double tolerance = 1e-12;
	return fabs(val) < tolerance;
}

// Funzione che converte una matrice densa in una matrice sparsa
SparseMatrix sparse(const Matrix &m)
{
	SparseMatrix sp_matrix; // dichiaro una sparse matrix

	// ne pongo gli attributi uguali a quelli della matrice di partenza
	sp_matrix.nr = m.nr;
	sp_matrix.nc = m.nc;
	sp_matrix.nnz = 0;

	// faccio puntare la sparse matrix creata con store alla nuova sequenza
	sp_matrix.store = new SparseEntry;		

	// creo un puntatore ausiliario alla matrice sparsa
	SparseMatrix spar_cur = sp_matrix;

	for(int r = 0; r < m.nr; r++)
	{
		for(int c = 0; c < m.nc; c++)
		{
			if(!iszero(m.store[r][c]))
			{
				spar_cur.store-> next =  new SparseEntry;

				spar_cur.store-> val = m.store[r][c];
				spar_cur.store-> r = r;
				spar_cur.store-> c = c;

				sp_matrix.nnz++;

				spar_cur.store = spar_cur.store-> next;		
			}	
		}
	}

	spar_cur.store-> next = nullptr;
	return sp_matrix;
}


// Funzione che converte una matrice sparsa in una matrice densa
Matrix full(const SparseMatrix &s)
{
	Matrix k;
	k.nr = s.nr;
	k.nc = s.nc;
	SparseMatrix aux = s;

	// creo il vector con le dimensioni massime prese dalla lista della matrice sparsa
	k.store.resize( k.nr );   
	for (int i = 0; i < k.nr; i++)
	{
		k.store[i].resize( k.nc );
	}

	// scorre la matrice
	while(aux.store-> next != nullptr)
	{
		if(!iszero(aux.store-> val))
		{
			k.store[aux.store->r][ aux.store->c] = aux.store->val;
		}
		else
		{
			k.store[aux.store->r][ aux.store->c] = 0;
		}

		aux.store = aux.store->next;
	}

	return k;
}

// Funzione che elimina l'elemento in riga r e colonna c
// e restituisce la matrice sparsa aggiornata
SparseMatrix removeEntry(const SparseMatrix &s, const int r, const int c)
{
	// dichiara una nuova matrice sparsa
	SparseMatrix nova;

	// ne pone i valori uguali a quelli della matrice di partenza
	nova.nr = s.nr;
	nova.nc = s.nc;
	nova.nnz = s.nnz;
	nova.store =  new SparseEntry;
	SparseEntry* aux = nova.store;

	// vado a leggere s (con un ptr ausiliario(aux))
	// per farne una copia che sarà la matrice sparsa aggiornata
	SparseEntry* read = s.store;

	// scorendo la matrice, ne eseguo la copia
	while(read->next != nullptr)
	{
		aux-> r = read-> r;
		aux-> c = read-> c;
		aux-> val = read-> val;
		aux-> next =  new SparseEntry;
		aux = aux-> next;

		read = read-> next;
	}

	aux = nullptr; //chiudo la matrice sparsa


	// per rimuovere un elemento dalla lista o matrice sparsa
	// sono necesari due puntatori 
	SparseEntry* curr = nova.store;   
	SparseEntry* prev = nova.store;

	// se l'elemento da eliminare è il primo lo gestisco
	if(nova.store->r == r && nova.store->c == c)
	{ 
		nova.store = nova.store->next;
	}

	// adesso gestisco gli altri casi:
	// scorrendo la matrice
	while(curr->next != nullptr){
		// ed eliminando l'elemento
		// in riga r e colonna c
		if(curr-> r == r && curr-> c == c)
		{
			SparseEntry* temp = curr;
			curr = curr-> next;
			delete temp;
			prev->next = curr;
			temp = nullptr;
		}
		else
		{
			prev = curr;
			curr = curr-> next;
		}
	}

	// ritorno la matrice aggiornata
	return nova;

}

// Funzione che assegna all'elemento di riga r e colonna c della matrice sparsa s il valore val,
// e restituisce la matrice aggiornata
SparseMatrix setEntry(const SparseMatrix &s, const double val, const int r, const int c)
{
	// controllo la correttezza dei parametri
	// se l'utente inserisce una riga o una colonna inesistente
	// allora restituisco un errore
	if(r >= s.nr || c >= s.nc)
	{
		throw -1;
	}

	// dichiaro una variabile contatore
	// che corrisponderà alla lungheza della lista
	int counter = 0;

	// faccio una copia della matrice sparsa come nella funzione precedente
	SparseMatrix nova2;

	// copio quindi anche gli attributi della vecchia lista nella nuova
	nova2.nr = s.nr;
	nova2.nc = s.nc;
	nova2.nnz = s.nnz;
	nova2.store =  new SparseEntry;
	SparseEntry* aux = nova2.store;

	// vado a leggere s (con un ptr ausiliario(aux))
	// per farne una copia che sarà la matrice sparsa aggiornata
	SparseEntry* read = s.store;		
	while(read->next != nullptr)
	{
		aux-> r = read-> r;
		aux-> c = read-> c;
		aux-> val = read-> val;
		aux-> next =  new SparseEntry;
		aux = aux-> next;

		counter++;
		read = read-> next;
	}

	aux = nullptr; // chiudo la matrice sparsa

	// - Se nella matrice sparsa è già presente un elemento con le coordinate indicate,
	// ed il valore che si vuole assegnare è zero,
	// allora la funzione deve eliminare la tripla dalla lista,
	// per rispettare la definizione di matrice sparsa:

	// - Se nella matrice sparsa è già presente un elemento con le cordinate indicate,
	// la funzione deve solo aggiornare il valore 
	// se quello che si vuole assegnare è diverso da zero:

	// per la rimozione o la sostituzione di un elemento
	// necessito di due puntatori ausiliari
	SparseEntry* curr = nova2.store;
	SparseEntry* prev = nova2.store;

	// preparo la cella da inserire nella matrice sparsa
	SparseEntry* inserimento = new SparseEntry;     
	inserimento-> r = r;
	inserimento-> c = c;
	inserimento-> val = val;

	// rimozione: gestisco il caso in cui debba rimuovere la prima cella
	if(curr->r == r && curr->c == c && iszero(inserimento->val))
	{			
		nova2.store = nova2.store->next;
		curr = nova2.store;
		prev = nova2.store;
		return nova2; 
	}
	
	// sostituzione: gestisco il caso in cui debba sostituire la prima cella
	if(curr->r == r && curr->c == c && !iszero(inserimento->val))
	{    
		nova2.store-> val = val;
		return nova2;
	}


	// gestisco i casi in cui devo rimuovere o sostituire
	// celle diverse dalla prima
	// dichiaro una booleana che dice se ho effettuato la sostituzione
	bool isDone = false;
	while(curr->next != nullptr)
	{
		// rimozione: cancello la cella
		// se sto inserendo un val zero (nullo)
		if(curr->r == r && curr->c == c && val == 0)
		{      
			curr = curr-> next;
			prev->next = curr;
			isDone = true;
		}

		// sostituzione: modifico il val della cella
		// se inserisco un valore diverso in una cella esistente
		else if(curr->r == r && curr->c == c && val != 0)
		{  
			curr-> val = val;
			isDone = true;
		}

		prev = curr;
		curr = curr-> next;
		
		// questo if serve per evitare che il programma vada avanti
		// nel caso in cui io abbia eseguito la sostituzione
		if(isDone)
			return nova2;
	}

	// - Se non esiste nella matrice sparsa un elemento con le stesse coordinate,
	// la funzione aggiunge una tripla alla lista 
	// solo se il valore assegnato non è zero

	// dichiaro un puntatore per leggere la lista
	SparseEntry* read2 = nova2.store;
	// e una booleana che sarà true se nella posizione passata nella funzione
	// è presente un elemento
	bool isPresent = false;

	// leggo la lista e se trovo una cella con le coordinate 
	// aggiorno la booleana isPresent, marcando l'esistenza
	while(read2->next != nullptr)
	{                   
		if(read2-> r == r && read2-> c == c && inserimento-> val == val)	
		{
			isPresent = true;
		}

		read2 = read2-> next;
	}

	// se non è presente l'elemento e l'utente inserisce zero
	// non devi eliminarlo, quindi non fare nulla
	if(!isPresent && val==0)
	{
		return nova2;
	}

	// anche per l'inserimento di un elemento
	// necessito di due puntatori ausiliari
	SparseEntry* now = nova2.store;
	SparseEntry* bef = nova2.store;

	// gestisco il caso in cui la cella da inserire sia in testa alla lista 
	if((inserimento->r <= now->r) && (inserimento->c < now->c) && !iszero(inserimento->val))
	{
		inserimento-> next = now;
		nova2.store = inserimento;
		now = inserimento;
		bef = inserimento;
		return nova2;
	}

	// gestisco il caso in cui la cella da inserire non sia in testa o in coda alla lista
	// se l'elemento non esiste allora leggo la lista e lo inserisco
	if(!isPresent)
	{
		while(now-> next != nullptr)
		{
			// ovviamente solo se il suo val è diverso da zero
			if(!iszero(inserimento->val))
			{
				if((inserimento->r == now->r) && (inserimento->c < now->c) && !iszero(inserimento->val))
				{
					bef-> next = inserimento;
					inserimento-> next = now;

					return nova2;
				}

				if((inserimento->r < now->r) && (inserimento->c > now->c) && !iszero(inserimento->val))
				{
					bef-> next = inserimento;
					inserimento-> next = now;

					return nova2;
				}

				bef = now;
				now = now -> next;
			}
		}
	}
	

	// gestisco il caso in cuoi debba inserire una cella in coda
	// dichiaro un puntatore per leggere la lista
	SparseEntry* read3 = nova2.store;   

	// sposto il puntatore di tante posizione quanto la lunghezza della lista
	for(int i = 0; i < counter; i++)
	{
		read3 = read3->next;
	}

	// creo un nuovo elemento
	SparseEntry* arcc = new SparseEntry;

	// lo inizializzo con i valori passati
	read3-> val = val;
	read3-> r = r;
	read3-> c = c;

	// e lo inserisco in coda
	read3-> next = arcc;
	arcc-> next = nullptr;

	// per poi ritornare la matrice sparsa aggiornata
	return nova2;
}

// Funzione che cerca un elemento in posizione (r,c) e lo restituisce
double getEntry(const SparseMatrix &s, const int r, const int c)
{
	// vado a leggere s (con un ptr ausiliario(aux))
	// per farne una copia che sarà la matrice sparsa aggiornata
	SparseEntry* read = s.store;	
	
	while(read-> next != nullptr)
	{
		if(read->r == r && read->c == c)
		{
			return read-> val;
		}

		read = read-> next;
	}
	// se l'elemento non è presente ritorna 0
	return 0;
}

// Funzione che stampa i valori di una matrice sparsa
void printSparseMatrix(const SparseMatrix &s)
{
	cout << "I valori della matrice sparsa sono: ";
	double val;

	// scorre le righe
	for(int r = 0; r < s.nr; r++)
	{
		// scorre le colonne nella riga
		for(int c = 0; c < s.nc; c++)
		{
			// utilizza la funzione per cercare il valore in (r,c)
			val = getEntry(s,r,c);
			// e se è diverso da 0 lo stampa
			if(val != 0) 
				cout << " " << val << " ";
		}	
	}

	cout << endl;
}