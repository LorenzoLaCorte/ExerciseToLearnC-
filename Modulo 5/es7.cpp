// Es.7 - Lorenzo La Corte
// Definire una struct Time per mantenere informazioni orarie come terne ora, minuti, secondi 
// (memorizzabili con degli interi senza segno).
// Scrivere un programma che legge le informazioni relative a due variabili
// T1, T2 di tipo Time, ne verifica la correttezza e
// calcola il tempo trascrso tra i due orari, 
// assumendo che si riferiscano allo stesso giorno

#include <iostream>
#include <cmath>
using namespace std;

// Definire una struct Time per mantenere informazioni orarie come terne ora, minuti, secondi 
// (memorizzabili con degli interi senza segno).
struct Time{
 unsigned int ore;   
 unsigned int min;
 unsigned int sec;
};

int main()
{
    // Scrivere un programma che legge le informazioni relative a due variabili
    // T1, T2 di tipo Time,
    Time T1,T2;
    cout << "CALCOLA IL TEMPO TRASCORSO TRA DUE ORARI DELLO STESSO GIORNO" << endl << endl;
    cout << "Inserisci il primo orario (hh mm ss)" << endl;
    cin >> T1.ore >> T1.min >> T1.sec;
    cout << "Inserisci il secondo orario (hh mm ss)" << endl;
    cin >> T2.ore >> T2.min >> T2.sec;
    // ne verifica la correttezza e
    if(T1.ore > 23 || T1.min > 59 || T1.sec > 59 || T2.ore > 23 || T2.min > 59 || T2.sec > 59)
    {
        cout << "Uno dei due orari è sbagliato" << endl;
    }
    // calcola il tempo trascrso tra i due orari, 
    // assumendo che si riferiscano allo stesso giorno
    unsigned int T1_tot = T1.ore*3600 + T1.min*60 + T1.sec; // tutto in secondi
    unsigned int T2_tot = T2.ore*3600 + T2.min*60 + T2.sec; // tutto in secondi
    int tempo_trasc = T1_tot - T2_tot;
    tempo_trasc = abs(tempo_trasc);
    
    unsigned int ore_trasc = tempo_trasc/3600;
    unsigned int min_trasc = (tempo_trasc - ore_trasc*3600)/60;
    unsigned int sec_trasc = (tempo_trasc - ore_trasc*3600 - min_trasc*60);

    cout << "Tra i due orari sono passate " << ore_trasc << " ore, " << min_trasc << " minuti e " << sec_trasc << " secondi." << endl << endl;
}
