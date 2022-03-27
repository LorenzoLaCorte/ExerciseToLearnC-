// Scrivere un programma che chiede all’utente in che anno è nato e stampa quanti anni ha.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiara le variabili
	int year, age;
	// input variabili year,age
	cout << "Inserisci in che anno sei nato: " << endl;
	cin >> year;
	// operazioni
	age = 2019 - year;
	// output
	cout << "Quest'anno compi (o hai gia compiuto) "<< age << " anni" << endl;
	return 0;
}