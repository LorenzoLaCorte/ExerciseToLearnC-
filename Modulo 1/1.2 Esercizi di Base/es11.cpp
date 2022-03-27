// Scrivere un programma che calcola circonferenza e area di un cerchio, 
// dopo aver chiesto e letto i dati necessari.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiara le variabili
	float r, crf, area;
	const float PIGRECA = 3.14;
	// input
	cout << "Inserisci il Raggio: " << endl;
	cin >> r;
	// calcoli
	crf = 2 * PIGRECA * r;
	area = (PIGRECA * r * r);
	// output
	cout << "La Circonferenza risultante e': "<< crf << endl;
	cout << "L'Area risultante e': "<< area << endl;

	return 0;
}