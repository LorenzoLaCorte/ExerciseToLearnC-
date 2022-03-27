
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiara le variabili
	float b, c1, c2, h, Perimetro, Area;
	// input
	cout << "Inserisci inserisci nell'ordine: Base, Cateto 1, Cateto 2, Altezza: " << endl;
	cin >> b >> c1 >> c2 >> h;
	// operazioni
	Perimetro=b+c1+c2;
	Area=(b*h)/2;
	// output
	cout << "Il perimetro e'"<< Perimetro << " , L'area e'" << Area <<  endl;
	return 0;
}