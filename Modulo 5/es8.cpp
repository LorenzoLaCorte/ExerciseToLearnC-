// Es.8 - Lorenzo La Corte
// Definire un tipo struct Complex che rappresenta un numero complesso in due forme:
// (a) come parte reale e parte immaginaria (forma cartesiana);
// (b) come modulo e fase (forma esponenziale),
// tutte variabili-membro di tipo double .
// Scrivere un programma che legge due numeri complessi e ne calcola:
// • Somma
// • Differenza
// • Prodotto
// • Rapporto
// Ogni operazione deve mantenere consistenti, allineate fra loro, le due rappresentazioni,
// ovvero le coppie (re, im) e (modulo,fase) 
// di un dato numero complesso devono sempre rappresentare lo stesso numero.
// Stampare i risultati delle operazioni nelle due forme, cartesiana ed esponenziale.

#include <iostream>
using namespace std;

// Definire un tipo struct Complex che rappresenta un numero complesso in due forme:
// (a) come parte reale e parte immaginaria (forma cartesiana);
// (b) come modulo e fase (forma esponenziale),
// tutte variabili-membro di tipo double .

struct Complex
{
	 double R;
	 double I;
};

int main()
{
	
	// Scrivere un programma che legge due numeri complessi 
	Complex C1, C2, C3, C4, C5, C6;
	cout << "Inserisci un numero complesso in forma: x x (senza i)" << endl;
	cin >> C1.R >> C1.I;

	cout << "Inserisci un altro numero complesso in forma: x x (senza i)" << endl;
	cin >> C2.R >> C2.I;

	// e ne calcola:
	// • Somma (C3)
	C3.R = C1.R + C2.R; 
	C3.I = C1.I + C2.I; 

	// • Differenza(C4)
	C4.R = C1.R - C2.R; 
	C4.I = C1.I - C2.I; 

	// • Prodotto(C5)
	C5.R = (C1.R * C2.R) - (C1.I * C2.I);
	C5.I = (C1.R * C2.I) + (C1.I * C2.R);

	// • Rapporto(C6)
	C6.R = ((C1.R * C2.R) + (C1.I * C2.I)) / (C2.R*C2.R + C2.I*C2.I); 
	C6.I = ((C1.I * C2.R) - (C1.R * C2.I)) / (C2.R*C2.R + C2.I*C2.I); 

	// Ogni operazione deve mantenere consistenti, allineate fra loro, le due rappresentazioni,
	// ovvero le coppie (re, im) e (modulo,fase) 
	// di un dato numero complesso devono sempre rappresentare lo stesso numero.
	// Stampare i risultati delle operazioni nelle due forme, cartesiana ed esponenziale.

	cout << "La somma e': " << C3.R << " " << C3.I << "i" << endl;
	cout << "La Differenza e': " << C4.R << " " << C4.I << "i" << endl;
	cout << "Il Prodotto e': " << C5.R << " " << C5.I << "i" << endl;
	cout << "Il Rapporto e': " << C6.R << " " << C6.I << "i" << endl;
	
	return 0;
}