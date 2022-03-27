#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// dichiara 4 var int a,b,max,min e due float media e semidist
	int a, b;
	float media, semidist,  min, max; 
	// input a, b
	cout << "Inserisci 2 valori interi separati da uno spazio." << endl;
	cin >> a >> b;
	// media tra a e b
	media = (a + b) / 2.0;
	// semidistanza tra a e b
	semidist = (a - b) / 2.0;
	// valore assoluto semidistanza
	semidist = fabs(semidist);
	// min = media - semidistanza
	min = media - semidist;
	max = min + semidist*2;
	// output min e max
	cout << "Ecco i tuoi valori ordinati in ordine crescente:" << endl;
	cout << min << " " << max << endl;

}	