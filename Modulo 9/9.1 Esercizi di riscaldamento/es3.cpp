#include <iostream>
#include <vector>
using namespace std;

void readVector(vector<int>& v) 
{
	// Stampare "Inserisci la dimensione della sequenza: "
	cout << "Inserisci la dimensione della sequenza: " << endl;
	// Dichiarare una variabile intera N
	int N;
	// Leggere N
	cin >> N;
	// iterare N volte
	for(int i=0; i<N; i++)
	{
		cout << "Inserisci un valore in posizione " << (i+1) << ": ";
		// - leggere un valore intero
		int value;
		cin >> value;
		// - memorizzare il valore letto in v
		v.push_back(value);
		cout << endl << endl;
	}
}

void printVector(const vector<int>& v) 
{
	// iterare v.size() volte
	for(int i=0; i<v.size(); i++)
	{
		// - stampare l'elemento corrente di v
		cout << "Il valore in posizione " << (i+1) << " è: " << v[i];
		cout << endl << endl;
	}	
}


void SelectionSort_vector(vector<int>& v) 
{
	// dichiarare una variabile int greatestIndex
	int greatestIndex, i;
	// iterare sul std::vector dalla prima all'ultima posizione
	for(i=0; i<v.size(); i++)
	{
		// - memorizzare in greatestIndex la posizione corrente (sia i)
		greatestIndex = i;
		// iterare sul std::vector dalla posizione successiva alla corrente ...
		//	... (i+1) fino all'ultimo elemento
		for(int j=(i+1); j<v.size(); j++)
		{
			//	-- se il valore alla pos corrente (j) e' < del valore...
			//... alla pos greatestIndex
			if(v[j] < v[greatestIndex])
			{
				// --- memorizzare j in greatestIndex
				greatestIndex = j;
			}
		}
		
		int aux;
		aux = v[i];
		v[i] = v[greatestIndex];
		v[greatestIndex] = aux;
	
	}	
}

int SequentialSearch_vector(const std::vector<int>& v, int item) 
{
	// dichiarare una variabile int loc e inizializzarla a -1
	int loc=-1;
	// dichiarare una variabile bool found e inizializzarla a false
	bool found = false;
	// iterare su v fino a che found diventa true o ...
	// ... si \`e iterato su tutto il vector
	for(int i=0; (i<v.size()||found); i++)
	{
		// - se il valore alla pos corrente (i) e' uguale a item
		if(v[i]==item)
		{
			// -- assegnare true a found e i a loc
			found = true;
			loc = i;
		}
			
	}
	// restituire loc
	return loc;
}

int main()
{
	// dichiarare un std::vector vect di interi
	vector<int> vect;
	// chiamare la funzione readVector su vect
	readVector(vect);
	
	cout << endl << "Il vettore inserito è:" << endl << endl;
	// chiamare la funzione printVector su vect
	printVector(vect);
	// chiamare la funzione SelectionSort_vector su vect
	SelectionSort_vector(vect);
	
	cout << endl << "Il vettore ordinato è:" << endl << endl;
	// chiamare la funzione printVector su vect
	printVector(vect);
	
	int elem;
	cout << "Cerca un elemento." << endl;
	cout << "Inserisci il valore dell'elemento da cercare:" << endl;
	cin >> elem;
	
	cout << "L'elemento cercato è in posizione: " << SequentialSearch_vector(vect, elem) << endl << endl; 
}
