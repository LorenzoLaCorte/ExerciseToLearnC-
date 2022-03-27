// Es.8 - Lorenzo La Corte
#include <iostream>
using namespace std;

void print_menu(string choice1, string choice2, string choice3, string choice4)
{
    // stampare `1' seguito da un carattere tab seguito da choice1
    cout << "1\t" << choice1 << endl;
    // stampare su una nuova riga `2' seguito da un tab seguito da choice2
    cout << "2\t" << choice2 << endl;
    // stampare su una nuova riga `3' seguito da un tab seguito da choice3
    cout << "3\t" << choice3 << endl;
    // stampare su una nuova riga `4' seguito da un tab seguito da choice4
    cout << "4\t" << choice4 << endl;
}

void print_choice(int n, string ch1, string ch2, string ch3, string ch4)
{
    // Stampare un a capo seguito da "Scelta effettuata: "
    cout << endl << "Scelta effettuata: ";
    // A seconda del valore di n
    switch(n)
    {
        // Nel caso 1:
        case 1:
        // - stampare ch1
        cout << ch1 << endl;
        break;
        // Nel caso 2:
        case 2:
        // - stampare ch2
        cout << ch2 << endl;
        break;

        // Nel caso 3:
        case 3:
        // - stampare ch3
        cout << ch3 << endl;
        break;
        // Nel caso 4:
        case 4:
        // - stampare ch4
        cout << ch4 << endl;
        break;
    }
}

int get_choice(int max){
    // Dichiarare una variabile scelta di tipo int
    int scelta;
    // Ripetere finché scelta minore di uno o maggiore di max
    do 
    {
        //- Stampare "Inserisci una scelta fra 1 e " seguito da max
        //- Stampare un a capo
        cout << "Inserisci una scelta fra 1 e " << max << endl;
        //- Leggere scelta
        cin >> scelta;
        
    } while (scelta < 1 || scelta > max);
    // Restituire scelta
    return scelta;
}

int use_menu(string choice1, string choice2, string choice3, string choice4)
{
    // Chiamare print_menu su choice1, choice2, choice3, choice4
    cout << endl;
    print_menu(choice1,choice2,choice3,choice4);
    cout << endl;
    // Dichiarare una variabile n di tipo int inizializzata con il risultato...
    // ... della chiamata di get_choice su 4
    int n = get_choice(4);
    // Chiamare print_choice su n, choice1, choice2, choice3, choice4
    print_choice(n, choice1, choice2, choice3, choice4);
    // Restituire n
    return n;
}

int main()
{
/*    // dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
    const string s1 = "Prima scelta";
    // dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
    const string s2 = "Seconda scelta";
    // dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
    const string s3 = "Terza scelta";
    // dichiarare una costante s4 di tipo string inizializzata con "Quarta scelta"
    const string s4 = "Quarta scelta";
    // chiamare print_menu su s1, s2, s3, s4
    print_menu(s1,s2,s3,s4);

    // chiamare print_choice su 1, s1, s2, s3, s4
    print_choice(1,s1,s2,s3,s4);
    // chiamare print_choice su 2, s1, s2, s3, s4
    print_choice(2,s1,s2,s3,s4);
    // chiamare print_choice su 3, s1, s2, s3, s4
    print_choice(3,s1,s2,s3,s4);
    // chiamare print_choice su 4, s1, s2, s3, s4
    print_choice(4,s1,s2,s3,s4);
    
    // stampare il risultato della chiamata di get_choice su 7
    get_choice(7);
    
    // chiamare use_menu su s1, s2, s3, s4
    use_menu(s1, s2, s3, s4);
    */
    
    // dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
    const string s1 = "Prima scelta";
    // dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
    const string s2 = "Seconda scelta";
    // dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
    const string s3 = "Terza scelta";
    // dichiarare una costante s4 di tipo string inizializzata con "Basta!"
    const string s4 = "Basta!";
    // ripetere finché answer è diverso da quattro
    int answer = 0;
    while(answer!=4)
    {
        // - dichiarare una variabile intera answer inizializzata con use_menu su s1, s2, s3, s4
        answer = use_menu(s1, s2, s3, s4);
    }
}
