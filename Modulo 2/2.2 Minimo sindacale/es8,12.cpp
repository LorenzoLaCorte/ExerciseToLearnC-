// La Corte Lorenzo - Es. 8
// Scrivere un programma che verifica se un numero intero dato in input rappresenta o meno un anno bisestile.

#include <iostream>
using namespace std;

int main()
{
int anno;

cout << "Inserisci un anno: " << endl;
cin >> anno;

// divido per 4, se è T 100, se è F ok, se è T 400.

if (anno % 4 == 0)
{
	 if(anno % 100 == 0)
	 {
		  if(anno % 400 == 0)
		  {
		  cout << "È bisestile" << endl;
		  }
		  else
		  {
		  cout << "Non è bisestile" << endl;
		  }
	 }
	 else
	 {
	 cout << "È bisestile" << endl;
	 }
	}
else
{
cout << "Non è bisestile" << endl;
}

return 0;
}