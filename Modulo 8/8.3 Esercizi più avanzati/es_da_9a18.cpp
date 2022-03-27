// Es. da 9 a 18 - Lorenzo La Corte

#include <iostream>
using namespace std;

/* Un oggetto di tipo myvector è una struct che contiene tre membri:
• Un intero size che rappresenta il numero di elementi effettivamente memorizzati nel vettore
• Un intero capacity che rappresenta il numero massimo di elementi che possono essere memorizzati nel vettore
• Un puntatore a intero store, che conterrà l’indirizzo di un’area di memoria allocata in modo da contenere capacity interi */

struct myvector{
	int size;
	int capacity;
	int * store;	
};

void resize(myvector&, int);

// funzione che, ricevendo come argomento il riferimento a un myvector v non ancora inizializzato, 
// fa l’allocazione di v.store con lunghezza capacity, 
// assegna v.capacity = capacity, 
// e assegna v.size = 0.
void create(myvector& v, int capacity)
{
	// fa l’allocazione di v.store con lunghezza capacity, 
	v.store = new int[10];
	// assegna v.capacity = capacity, 
	v.capacity = capacity;
	// e assegna v.size = 0.
	v.size = 0;
}

void print(const myvector& v)
{
	for(int i=0; i<v.size; i++)
	{
		cout << "Elemento numero " << i << ": " << v.store[i] << endl;
	}
	cout << endl << endl;
}

// funzione push_back che, ricevendo come argomento il riferimento a un myvector v già inizializzato, 
// e un valore x, opera come segue: 
// se v.size è minore di v.capacity 
// - inserisce x in v.store all’indice v.size 
// - e incrementa di uno v.size.
// Se v è già completamente pieno (cioè v.size == v.capacity), 
// - la funzione solleva un’eccezione
// AGGIORNATA A safe_push_back:
// in caso il myvector sia già completamente riempito
// raddoppia la capacità del parametro e inserisce il valore dato
void push_back(myvector& v, int x)
{
	// Se v è già completamente pieno (cioè v.size == v.capacity), 
	if(v.size == v.capacity)
	{	
		cout << "Il vettore è pieno, raddoppio la capacità per inserire il tuo elemento." << endl;
		// e nel corrispondente catch chiamate in ordine la funzione resize per raddoppiare la capacità 
		resize(v, (v.capacity*2));
	}
	
	// se v.size è minore di v.capacity 
	if(v.size < v.capacity)
	{
		// - inserisce x in v.store all’indice v.size 
		v.store[v.size] = x;
		// - e incrementa di uno v.size.
		v.size++;
	}

}



// funzione pop_back che dato per riferimento un myvector v inizializzato 
// se v.size è positivo 
// - restituisce il valore memorizzato in v.store all’indice v.size-1 
// - e decrementa di uno v.size. 
// Se v è vuoto (cioè 0 == v.size), 
// - la funzione solleva un’eccezione
int pop_back(myvector& v)
{
	// Se v è vuoto (cioè 0 == v.size), 
	if(v.size == 0)
	{
		// - la funzione solleva un’eccezione
		throw 1;
	}
	
	// se v.size è positivo 
	if(v.size > 0)
	{	
		int ret = v.store[v.size-1];
		// - e decrementa di uno v.size. 
		v.size--;
		// - restituisce il valore memorizzato in v.store all’indice v.size-1
		return ret;
	}
}

// funzione che assegna value all’elemento con indice index di v.store. 
// Solleva una eccezione se index non è un valore corretto, 
// ovvero se non è compreso fra 0 e v.size
void set(myvector& v, int value, int index)
{
	// se index non è un valore corretto, 
	// ovvero se non è compreso fra 0 e v.size
	if(index < 0 || index > v.size)
	{
		// - Solleva una eccezione
		throw 2;
		
	}
	// assegna value all’elemento con indice index di v.store.
	v.store[index] = value;
}

// funzione che restituisce il valore presente in v.store all’indice index.
// Solleva una eccezione se index non è un valore corretto, 
// ovvero se non è compreso fra 0 e v.size.
int get(const myvector& v, int index)
{
	// se index non è un valore corretto, 
	// ovvero se non è compreso fra 0 e v.size.
	if(index < 0 || index > v.size)
	{
		// - Solleva una eccezione
		throw 3;
	}	
	// restituisce il valore presente in v.store all’indice index
	return v.store[index];
}

// funzione che dealloca v.store 
// e pone a zero sia v.size 
// che v.capacity
void destroy(myvector& v)
 {
 	// che dealloca v.store
 	delete[] v.store;
 	v.store = 0;
	// e pone a zero sia v.size
	v.size = 0; 
	// che v.capacity
	v.capacity = 0;
 }
 
// funzione che dato per riferimento un myvector v già inizializzato e un intero new_capacity strettamente positivo 
// modifica la capacità del vettore preservando i valori contenuti per quanto possibile.
void resize(myvector& v, int new_capacity)
{
	// Se new_capacity non è strettamente positiva, 
	if(new_capacity<=0)
	{
		// - la funzione solleverà un’eccezione.
		throw 4;
	}

	// alloca un blocco lungo new_capacity,
	int * aux;
	aux = new int[new_capacity];
	
	// se v.size>new_capacity aggiornare v.size
	if(v.size>new_capacity)
	{
		v.size = new_capacity;
	}
	// copia i valori contenuti in v.store 
	// se v.size>new_capacity verranno copiati solo i primi v.size
	for(int i=0; i<new_capacity; i++)
	{
		aux[i]=v.store[i];
	}
	
	// liberare lo spazio precedentemente occupato da v.store (per evitare memroy leak)
	delete[] v.store;
	
	// assegnare a v.store il nuovo blocco di memoria.
	v.store = aux;
	
	// aggiornare v.capacity 
	v.capacity = new_capacity;
}

// funzione che restituisce vero se v.store non è nullo, 0<=v.size, v.size<=v.capacity e 0<v.capacity.
bool looks_consistent(const myvector& v)
{
	// restituisce vero se v.store non è nullo, 0<=v.size, v.size<=v.capacity e 0<v.capacity.
	return(v.store!=0 && 0<=v.size && v.size<=v.capacity && 0<v.capacity);
}

int main()
{
	myvector vect;
	int elem;
	
	try
	{
		cout << "\t\t\t\tESERCITAZIONE SU ARRAY DINAMICI"<< endl << endl; 
		
		int cap;
		cout << "Inserisci la capacità massima del tuo vettore:" << endl;
		cin >> cap;
		cout << endl << endl; 
		
		create(vect, cap);
		
		if(looks_consistent(vect))
		{
			cout << "L'array è stato creato correttamente." << endl;
		}
		else
		{
			cout << "L'array non è consistente." << endl;
			return -1;
		}
		
		int n_elem;
		cout << "Quanti elementi vuoi inserire?" << endl;
		cin >> n_elem;
		cout << endl << endl; 
		
		for(int i=0; i<n_elem; i++)
		{
			cout << "Inserisci l'elemento numero " << i << ": ";
			cin >> elem;
			
			push_back(vect, elem);
		}
		cout << endl << "Il tuo array è:" << endl;
		print(vect);
		cout << endl << endl; 
		
		char scelta;
		cout << "Elimino l'ultimo elemento? (y/n)" << endl;
		cin >> scelta;
		
		if(scelta == 'Y' || scelta == 'y')
		{
			int canc = pop_back(vect);
			cout << "Hai eliminato l'ultimo elemento, ovvero " << canc << endl;
		}
		cout << endl << "Il tuo array è:" << endl;
		print(vect);
		cout << endl << endl; 
		
		int pos,val;
		cout << "Sovrascrivi un elemento: " << endl;
		cout << "Posizione nell'array: ";
		cin >> pos;
		cout << "Valore: ";
		cin >> val;
		cout << endl; 
		
		set(vect, val, pos);
		cout << endl << "Il tuo array è:" << endl;
		print(vect);
		cout << endl << endl;
		
		cout << "Acquisisci un elemento:" << endl;
		cout << "Posizione nell'array: ";
		cin >> pos;
		cout << endl; 
		
		int gotcha = get(vect, pos);
		cout << "L'elemento in posizione " << pos << " e' " << gotcha << endl << endl;
		cout << endl << "Il tuo array è:" << endl;
		print(vect);
		cout << endl << endl;
		
		int new_cap;
		cout << "Dai una nuova capacità:" << endl;
		cin >> new_cap;
		
		resize(vect, new_cap);
		
		for(int i=vect.size; i<vect.capacity; i++)
		{
			int elem;
			cout << "Inserisci l'elemento numero " << i << ": ";
			cin >> elem;
			
			push_back(vect, elem);
		}
		cout << endl << "Il tuo array è:" << endl;
		print(vect);
		cout << endl << endl;
		
		destroy(vect);
	}
	catch(int errore)
	{
		if(errore==1)
			cout << "Il vettore è vuoto, non puoi eliminare nulla." << endl << endl;
		if(errore==2)
			cout << "Stai cercando di inserire un elemento in una posizione inesistente." << endl << endl;
		if(errore==3)
			cout << "Stai cercando di acquisire un elemento da una posizione inesistente." << endl << endl;
		if(errore==4)
			cout << "Non puoi inserire una capacità nulla o negativa." << endl << endl;
	}
}
