// La Corte Lorenzo - Es. 9
// Scrivere un programma che implementa un turno di gioco di forbice carta sasso, ovvero che legge in input la mossa dei due 
// giocatori e restituisce in output chi ha vinto.

#include <iostream>
using namespace std;

int main()
{
char g1, g2;

cout << "Giocatore 1, scegli (c)arta, (f)orbice o (s)asso" << endl;
cin >> g1;

cout << "Giocatore 2, scegli (c)arta, (f)orbice o (s)asso" << endl;
cin >> g2;

if ((g1 == 'c' || g1 == 's' || g1 == 'f') && (g2 == 'c' || g2 == 's' || g2 == 'f'))
{

	if (g1 == 'c')
	{
		 if (g2 == 'c'){
		 	cout << "Pareggio."<< endl; }
		 if (g2 == 'f'){
		 	cout << "Ha vinto il Giocatore 2."<< endl; }
		 if (g2 == 's'){
		 	cout << "Ha vinto il Giocatore 1."<< endl; }
	}

	if (g1 == 'f')
	{
		 if (g2 == 'f'){
			 cout << "Pareggio."<< endl; }
		 if (g2 == 's'){
		 	cout << "Ha vinto il Giocatore 2."<< endl; }
		 if (g2 == 'c'){
			 cout << "Ha vinto il Giocatore 1."<< endl; }
	}

	if (g1 == 's')
	{
		 if (g2 == 's'){
		 	cout << "Pareggio."<< endl; }
		 if (g2 == 'c'){
		 	cout << "Ha vinto il Giocatore 2."<< endl; }
		 if (g2 == 'f'){
		 	cout << "Ha vinto il Giocatore 1."<< endl; }
	}

}
else 
{
 	cout << "Inserite una giocata valida." << endl;
}

return 0;
}