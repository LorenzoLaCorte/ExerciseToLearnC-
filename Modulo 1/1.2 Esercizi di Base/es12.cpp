// Scrivere un programma che calcola circonferenza e area di un cerchio, 
// dopo aver chiesto e letto i dati necessari.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiara le variabili
	int a,b;
        float med;
	// input
	cout << "Inserisci 2 numeri interi: " << endl;
	cin >> a >>b;
	// calcoli
	med=(a+b)/2.0;
	// output
	cout << "La media e': "<< med << endl;


	return 0;
}