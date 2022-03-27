// La Corte Lorenzo - Es. 6
// Scrivere un programma che verifica se tre numeri reali dati in input possono essere i lati di un triangolo, cioè se nessuno di 
// essi è maggiore della somma degli altri due o minore del valore assoluto della loro differenza.

#include <iostream>
using namespace std;

int main()
{
// dichiara 3 int
int a, b, c, sab, sac, sbc, dab, dac, dbc;

// input 3 int

cout << "Inserisci 3 valori:" << endl;
cin >> a >> b >> c;

// verifica che essi non siano maggiori della somma degli altri due che non siano minori del modulo della loro differenza

sab = a + b;
sac = a + c;
sbc = b + c;

dab = abs(a - b);
dac = abs(a - c);
dbc = abs(b - c);

if (a <= sbc && b <= sac && c <= sab && a >= dbc && b >= dac && c >= dab)
{
	cout << "Questi valori possono essere lati di un triangolo" << endl;
}
else
{
	cout << "Questi valori non possono essere lati di un triangolo" << endl;
}
}