// La Corte Lorenzo - Es. 7
// Scrivere un programma che chiede all’utente un numero reale e lo legge.
// Quindi, in cascata (ovvero usando il risultato di ciascuna operazione come argomento per la successiva), lo divide per 4.9, 
// per 3.53 e per 6.9998. Poi, sempre in cascata, moltiplica per 4.9, per 3.53 e per 6.9998.

#include <iostream>
using namespace std;

int main()
{
double num;

cout << "Inserisci un Numero Reale: " << endl;
cin >> num;

num = num / 4.9;
num = num /  3.53;
num = num / 6.9998;

num = num * 4.9;
num = num *  3.53;
num = num *  6.9998;

cout << "Il tuo Numero Reale è: " << num << endl;
}