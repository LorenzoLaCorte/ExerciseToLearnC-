// Es.19 - Lorenzo La Corte
// Scrivere una funzione con un argomento intero n 
// che verifica se un numero intero positivo dato in input
// è un numero di Armstrong 
// e se sì restituisce true, 
// altrimenti restituisce false.
// Un intero positivo che si può rappresentare con n cifre 
// si dice numero di Armstrong 
// se è uguale alla somma delle potenze n-esime delle cifre che lo compongono. 

#include <iostream>
#include <math.h> 
using namespace std;

int num_cifre(int num)
{
    int cont = 0;
	// iterare 
	if(num == 0)
	{
		cont++;
	}
	for(int i=1; i<=num; i=i*10)
	{
		cont++;
	}	
	return cont;
}

// Scrivere una funzione con un argomento intero n 
bool isArmstrong(int n)
{
    int n_cifre, ris;
    int aux = 0;
    int sum=0;
    int cifra = 0;
    // trovare il numero di cifre
    n_cifre = num_cifre(n);
    
    // ripetere da 1 a numero di cifre compreso
    for(int i=1; i<=n_cifre; i++)
    {
        // - prendere la cifra in posizione i
        cifra =  n/pow(10,(n_cifre-i)) - aux * 10; // 153 per prendere 3 devo fare 153 - 15*10
        aux = n/pow(10,(n_cifre-i)); // per 153 è 1 per i=1, 15 per i=2, 153 per i=3

        // fare quella cifra elevata alla n_cifre e assegnare il risultato a ris
        ris = pow(cifra, n_cifre);

        // fare sum+=ris;
        sum+=ris;
    }
    
    // se sum == n restituisce true,
    // altrimenti restituisce false.
    return (sum==n);
}

int main()
{
    cout << "\t\tVERIFICA DI UN NUMERO DI ARMSTRONG\t" << endl;

    int numero;
    
    cout << "Inserisci un numero: " << endl;
    cin >> numero;
    
    if(isArmstrong(numero))
        cout << "E' un numero di Armstrong" << endl;
    else
        cout << "Non è un numero di Armstrong" << endl;

}