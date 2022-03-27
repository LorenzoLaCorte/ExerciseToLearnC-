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

int main()
{
	// dichiarare un std::vector vect di interi
	vector<int> vect;
	// chiamare la funzione readVector su vect
	readVector(vect);
	// chiamare la funzione printVector su vect
	printVector(vect);
}
