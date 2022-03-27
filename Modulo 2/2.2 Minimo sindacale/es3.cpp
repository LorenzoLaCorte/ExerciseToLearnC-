#include <iostream>
using namespace std;

int main()
	{
	//dichiaro un numero intero
	int num;
	// input
	cout << "Inserisci un numero intero: " << endl;
	cin >> num;
	//se è negativo ne faccio il valore assoluto
	if (num < 0)
	{
		num = -(num);
	}
	//output
	cout << "Il valore assoluto del numero inserito è: " << num << endl;

	return 0;
}