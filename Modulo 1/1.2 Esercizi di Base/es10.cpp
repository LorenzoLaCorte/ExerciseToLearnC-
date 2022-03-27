
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// dichiara le variabili
	int h, m;
	// input
	cout << "Inserisci inserisci nell'ordine: Ore, Minuti: " << endl;
	cin >> h >> m ;
	// operazioni	
	m=m+h*60;
	// output
	cout << "Il tempo in minuti e': "<< m << endl;
	return 0;
}