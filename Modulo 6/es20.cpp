// Es.20 - Lorenzo La Corte

#include <iostream>
#include <math.h> 
using namespace std;

int n_zeri(int n)
{
    int num_zeri = n/5;
    return num_zeri;
}

int main()
{
    cout << "\t\tNUMERO DI ZERI DI UN FATTORIALE\t" << endl;

    int numero;
    
    cout << "Inserisci un numero: " << endl;
    cin >> numero;
    
    if(numero >= 5 && numero < 10)
        cout << "Il fattoriale di " << numero << " ha " << n_zeri(numero) << " zero." << endl;
    else
        cout << "Il fattoriale di " << numero << " ha " << n_zeri(numero) << " zeri." << endl;


}