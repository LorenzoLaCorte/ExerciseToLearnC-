// La Corte Lorenzo - Es. 5
// Scrivere un programma che legge un numero intero da input e stampa se è o no divisibile per 13.

#include <iostream>
using namespace std;

int main()
{
int num;

cout << "Inserisci un numero: " << endl;
cin >> num;

// divido per 13 e vedo se da resto 0.

if (num % 13 == 0 && num != 0)
{
	 
	cout << "È divisibile per 13" << endl;

}
else
{
	cout << "Non è divisibile per 13" << endl;
}

return 0;
}