// Scrivere un programma per realizzare il gioco di carte UNO. 
// Dovrete definire almeno una struct che contiene le informazioni di una carta, 
// e i vector per memorizzare le carte in mano di ogni giocatore, 
// nel mazzo e in tavola.

// -- Carte --
// 10 carte di colore Blu, dall'1 al 9 più uno 0
// 10 carte di colore Rosso, dall'1 al 9 più uno 0
// 10 carte di colore Verde, dall'1 al 9 più uno 0
// 10 carte di colore Giallo, dall'1 al 9 più uno 0
// 4 carte +2 dei quattro colori sopracitati
// 4 carte Cambio giro dei quattro colori sopracitati
// 4 carte Stop dei quattro colori sopracitati
// 2 carte Cambio colore
// 2 carte +4
// per un totale di 56 carte

// -- Obiettivo --
// Vince chi finisce le carte

// -- Regole --
// Il giocatore che gioca una carta Salta può immediatamente giocarne un'altra.
// La carta Inverti ha lo stesso valore della carta Salta.
// Quando un giocatore gioca una carta Pesca Due 
// e l'avversario ha pescato le due carte, il gioco torna alla prima persona. 
// La stessa regola si applica per la carta Jolly Pesca Quattro.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// -- Carte --
// 10 carte di colore Blu, dall'1 al 9 più uno 0
// 10 carte di colore Rosso, dall'1 al 9 più uno 0
// 10 carte di colore Verde, dall'1 al 9 più uno 0
// 10 carte di colore Giallo, dall'1 al 9 più uno 0
// 4 carte +2 dei quattro colori sopracitati
// 4 carte Cambio giro dei quattro colori sopracitati
// 4 carte Stop dei quattro colori sopracitati
// 2 carte Cambio colore
// 2 carte +4
// per un totale di 56 carte


struct Carta{
	string colore;
	int numero;
	bool speciale;
	int posizione;
};

// funzione che crea il mazzo, da chiamare all'inizio del main
// In colore mette quello della carta (nero se speciale)
// In numero mette quello della carta, le speciali hanno le seguenti numerazioni:
// - 11 è +2
// - 12 è Cambio giro
// - 13 è Stop
// - 14 è Cambio colore
// - 15 è +4
// In speciale mette se è speciale
// In posizione mette la posizione nel mazzo
void GeneraMazzo(vector<Carta> &M)
{

	int cont = 0;
	// crea le carte colorate
	for(int i=0; i<10; i++)
	{
		M[i].colore = "Blu";
		M[i].numero = i;
		M[i].speciale = false;
		M[i].posizione = cont;

		M[i+10].colore = "Rosso";
		M[i+10].numero = i;
		M[i+10].speciale = false;
		M[i+10].posizione = (cont+1);

		M[i+20].colore = "Verde";
		M[i+20].numero = i;
		M[i+20].speciale = false;
		M[i+20].posizione = (cont+2);

		M[i+30].colore = "Giallo";
		M[i+30].numero = i;
		M[i+30].speciale = false;
		M[i+30].posizione = (cont+3);

		cont += 4;
	}

	// crea PiuDue / Stop / CambioGiro
	for(int i=0; i<4; i++)
	{	
		M[i+40].numero = 11; //PiuDue
		M[i+40].speciale = true;
		M[i+40].posizione = cont;

		M[i+44].numero = 12; //Stop
		M[i+44].speciale = true;
		M[i+44].posizione = (cont+1);

		M[i+48].numero = 13; //CambioGiro
		M[i+48].speciale = true;
		M[i+48].posizione = (cont+2);

		cont += 3;

		switch(i)
		{

			case 0:
			M[i+40].colore = "Blu"; 
			M[i+44].colore = "Blu"; 
			M[i+48].colore = "Blu"; 
			break; 
			case 1:
			M[i+40].colore = "Rosso"; 
			M[i+44].colore = "Rosso"; 
			M[i+48].colore = "Rosso"; 
			break; 
			case 2:
			M[i+40].colore = "Verde"; 
			M[i+44].colore = "Verde"; 
			M[i+48].colore = "Verde"; 
			break; 
			case 3:
			M[i+40].colore = "Giallo";
			M[i+44].colore = "Giallo"; 
			M[i+48].colore = "Giallo"; 
			break; 

		}
	}

	// crea CambioColore / PiuQuattro
	for(int i=0; i<2; i++)
	{
		M[i+52].colore = "Nero"; //CambioColore
		M[i+52].numero = 14;
		M[i+52].speciale = true;
		M[i+52].posizione = cont;

		M[i+54].colore = "Nero"; // PiuQuattro
		M[i+54].numero = 15;
		M[i+54].speciale = true;
		M[i+54].posizione = (cont+1);

		cont += 2;
	}
}


void StampaMazzo(const vector<Carta> &M)
{
	for(int i=0; i<M.size(); i++)
	{
		cout << M[i].numero << " ";
		cout << M[i].colore << " " << endl;
	}
}


// Pesca una carta casualmente
Carta PescaUnaCarta(const vector<Carta> &M)
{
	int casuale = rand() % 55; // genera un num tra 0 e 55
	return M.at(casuale); // ritorna la carta in posizione casuale
}

// Genera una mano iniziale, pescando 7 carte
void ManoIniziale(const vector<Carta> &MM, vector<Carta> &Mano)
{
	for(int i=0; i<7; i++)
	{
		Mano[i] = PescaUnaCarta(MM);
	}
}

string GeneraColoreCasuale()
{
	int casuale = rand() % 3; // genera un num tra 0 e 3
	
	if(casuale==0)
		return ("Blu");

	if(casuale==1)
		return ("Rosso");

	if(casuale==2)
		return ("Verde");

	if(casuale==3)
		return ("Giallo");
}

// Stampa una mano
void StampaMano(const vector<Carta> &Mano)
{
	cout << endl << endl << "---LA TUA MANO---" << endl << endl;	
	
	for(int i=0; i<Mano.size(); i++)
	{
	cout << (i+1) << ") \t";

		switch(Mano[i].numero)
		{
			case 11: // - 11 è +2
			cout << "+2 ";
			cout << Mano[i].colore;
			break;

			case 12: // - 12 è Cambio giro
			cout << "Cambio Giro ";
			cout << Mano[i].colore;
			break;

			case 13: // - 13 è Stop
			cout << "Stop ";
			cout << Mano[i].colore;
			break;

			case 14: // - 14 è Cambio colore
			cout << "Cambio Colore";
			break;

			case 15: // - 15 è +4
			cout << "+4";
			break;

			default:	
			cout << Mano[i].numero << " ";	
			cout << Mano[i].colore;
		}
			cout << endl << endl;
	}

	cout << "--------------------" << endl << endl;
}

// stampa la carta passata sul tavolo
void StampaTavolo(const Carta &in_tavola)
{
	cout << endl << endl << "---IL TAVOLO---" << endl << endl;	

	switch(in_tavola.numero)
	{
		case 11: // - 11 è +2
		cout << "+2 ";
		cout << in_tavola.colore;			
		break;

		case 12: // - 12 è Cambio giro
		cout << "Cambio Giro ";
		cout << in_tavola.colore;
		break;

		case 13: // - 13 è Stop
		cout << "Stop ";
		cout << in_tavola.colore;
		break;

		case 14: // - 14 è Cambio colore
		cout << "Cambio Colore";
		break;

		case 15: // - 15 è +4
		cout << "+4";
		break;

		default:	
		cout << in_tavola.numero << " ";	
		cout << in_tavola.colore;
	}

	cout << endl << endl << "--------------------" << endl << endl;
}


void MiaGiocata(const vector<Carta> &M, vector<Carta> &Mano, Carta &in_tavola, vector<Carta> &ManoPC)
{
	// stampo la mia mano
	StampaMano(Mano);

	// - Seleziona una sua carta (con numero) oppure pesca e passa
	int scelta = -1;
	bool carta_valida = false;
	bool rigioca = false;
	string n_colore;				
	// -- Guardo se la carta selezionata e' valida (ciclo finche' non e' valida)
	while(!carta_valida && scelta != 0)
	{	
		cout << "Seleziona una carta da giocare oppure pesca (scrivendo 0) e passa. " << endl;		
		cin >> scelta;
		
		// guardo se il numero è valido
		if (scelta > 0 && scelta <= Mano.size())
		{
			// guardo se è del colore giusto o è nera
			bool col_uguale = (Mano.at(scelta-1).colore == in_tavola.colore || Mano.at(scelta-1).colore == "Nero");
			// guardo se è lo stesso numero di quella in tavola
			bool num_uguale = (Mano.at(scelta-1).numero ==  in_tavola.numero);						

			if(col_uguale || num_uguale)
			{
				carta_valida = true;
			}
			else
			{
				carta_valida = false;
			}
		}
	}

	if(scelta != 0) // se sceglie di buttare una carta
	{
		if(Mano.at(scelta-1).numero > 10) // guardo se è speciale
		{
			// eseguo il suo effetto
			switch(Mano.at(scelta-1).numero)
			{
				case 11: // - 11 è +2
				cout << "L'avversario pesca 2 carte!" << endl;
				ManoPC.push_back(PescaUnaCarta(M));
				ManoPC.push_back(PescaUnaCarta(M));				
				break;

				case 12: // - 12 è Cambio giro
				cout << "Cambio Giro, tocca di nuovo a te!";
				// Fare in modo che tocchi di nuovo a lui
				rigioca = true;
				break;

				case 13: // - 13 è Stop
				cout << "Stop, tocca di nuovo a te!";
				// Fare in modo che tocchi di nuovo a lui
				rigioca = true;
				break;

				case 14: // - 14 è Cambio colore
				cout << "Cambio Colore, scegli un colore: ";		
				cin >> n_colore;
				in_tavola.colore = n_colore;				
				break;

				case 15: // - 15 è +4
				cout << "L'avversario pesca 4 carte!" << endl;
				ManoPC.push_back(PescaUnaCarta(M));		
				ManoPC.push_back(PescaUnaCarta(M));		
				ManoPC.push_back(PescaUnaCarta(M));		
				ManoPC.push_back(PescaUnaCarta(M));		
				cout << "Scegli un colore: ";			
				cin >> n_colore;
				in_tavola.colore = n_colore;				
				break;
			}
			
		}

		// -- Levo la carta da MyHand (prima la devo salvare in Tavolo)
		in_tavola.numero = Mano.at(scelta-1).numero;
		// se non è un cambio colore o +4 gli cambio anche il colore
		if (Mano.at(scelta-1).numero <= 13)
			in_tavola.colore = Mano.at(scelta-1).colore;

		// Mano.erase(scelta-1);
		Mano.erase(Mano.begin()+scelta-1);

		// -- Visualizzo la carta sul tavolo (la salvo in Tavolo e poi chiamo StampaTavolo)
		StampaTavolo(in_tavola);

		// se c'è stato uno stop o cambio giro
		// e il giocatore non ha vinto (e quindi non deve rigiocare)
		// allora fallo rigiocare
		if(rigioca==true && Mano.size()!=0)
			MiaGiocata(M, Mano, in_tavola, ManoPC);	
	}
	else // se sceglie di pescare
	{
		// PescaUnaCarta
		// la metto in MyHand (push_back())
		Mano.push_back(PescaUnaCarta(M));
		// stampo la mia mano
		StampaMano(Mano);
		// stampo il tavolo (invariato)
		StampaTavolo(in_tavola);
	}
	
}


void PCGiocata(const vector<Carta> &M, vector<Carta> &Mano, Carta &in_tavola, vector<Carta> &ManoPC)
{
	if(ManoPC.size() == 1)
		cout << endl << "L'avversario ha " << ManoPC.size() << " carta." << endl << endl;
	else
		cout << endl << "L'avversario ha " << ManoPC.size() << " carte." << endl << endl;		

	// - Seleziona una sua carta (con numero) oppure pesca e passa
	bool rigioca = false;
	int scelta = 0;
	bool carta_valida = false;
	string n_colore;	

	bool col_ug;
	bool num_ug;

	// Guardo se ha una carta giocabile
	// Se ce l'ha metto scelta = -1, cosí entra nel while
	// Se non ce l'ha scelta rimarrà 0 e non entrerà nel while
	for(int i=0; i<ManoPC.size(); i++)
	{
		// guardo se è del colore giusto o è nera
		col_ug = (ManoPC.at(i).colore == in_tavola.colore || ManoPC.at(i).colore == "Nero");
		// guardo se è lo stesso numero di quella in tavola
		num_ug = (ManoPC.at(i).numero ==  in_tavola.numero);						

		if(col_ug || num_ug)
		{
			scelta = -1;
		}
	}

	bool col_uguale;
	bool num_uguale;
	// -- Guardo se la carta selezionata e' valida 
	// ciclo finche' non e' valida o se non scelgo di pescare
	while(carta_valida == false && scelta != 0)
	{	
		// Genero un numero casuale tra 1 e size
		// e lo assegno a scelta		
		scelta = 1+(rand() % (ManoPC.size()));

		// guardo se il numero è valido
		// guardo se è del colore giusto o è nera
		col_uguale = (ManoPC.at(scelta-1).colore == in_tavola.colore || ManoPC.at(scelta-1).colore == "Nero");
		// guardo se è lo stesso numero di quella in tavola
		num_uguale = (ManoPC.at(scelta-1).numero ==  in_tavola.numero);						

		carta_valida = (col_uguale || num_uguale);
	}


	if(scelta != 0) // se sceglie di buttare una carta
	{
		if(ManoPC.at(scelta-1).numero > 10) // guardo se è speciale
		{
			// eseguo il suo effetto
			switch(ManoPC.at(scelta-1).numero)
			{
				case 11: // - 11 è +2
				cout << "L'avversario gioca +2, pesca 2 carte!" << endl;
				Mano.push_back(PescaUnaCarta(M));
				Mano.push_back(PescaUnaCarta(M));				
				break;

				case 12: // - 12 è Cambio giro
				cout << "L'avversario gioca Cambio Giro, tocca di nuovo a lui!";
				// Fare in modo che tocchi di nuovo a lui
				rigioca = true;
				break;

				case 13: // - 13 è Stop
				cout << "L'avversario gioca Stop, tocca di nuovo a lui!";
				// Fare in modo che tocchi di nuovo a lui
				rigioca = true;
				break;

				case 14: // - 14 è Cambio colore
				cout << "L'avversario gioca Cambio Colore, sceglie il colore ";		
				// chiama la funzione GeneraColoreCasuale
				n_colore = GeneraColoreCasuale();
				cout << n_colore << endl; 
				in_tavola.colore = n_colore;				
				break;

				case 15: // - 15 è +4
				cout << "L'avversario gioca +4, peschi 4 carte!" << endl;
				Mano.push_back(PescaUnaCarta(M));		
				Mano.push_back(PescaUnaCarta(M));		
				Mano.push_back(PescaUnaCarta(M));		
				Mano.push_back(PescaUnaCarta(M));		
				cout << "Sceglie il colore ";			
				// chiama la funzione GeneraColoreCasuale
				n_colore = GeneraColoreCasuale();
				cout << n_colore << endl; 
				in_tavola.colore = n_colore;				
				break;
			}
		}
		else
		{
			cout << "L'avversario gioca " << ManoPC.at(scelta-1).numero << " " << ManoPC.at(scelta-1).colore << endl;
		}

		// -- Levo la carta da MyHand (prima la devo salvare in Tavolo)
		in_tavola.numero = ManoPC.at(scelta-1).numero;
		// se non è un cambio colore o +4 gli cambio anche il colore
		if (ManoPC.at(scelta-1).numero <= 13)
			in_tavola.colore = ManoPC.at(scelta-1).colore;

		// Mano.erase(scelta-1);
		ManoPC.erase(ManoPC.begin()+scelta-1);

		// -- Visualizzo la carta sul tavolo (la salvo in Tavolo e poi chiamo StampaTavolo)
		StampaTavolo(in_tavola);
		// se c'è stato uno stop o cambio giro
		// e il giocatore non ha vinto (e quindi non deve rigiocare)
		// allora fallo rigiocare
		if(rigioca==true && ManoPC.size()!=0)
			PCGiocata(M, Mano, in_tavola, ManoPC);
	}

	else // se sceglie di pescare
	{
		cout << "L'avversario Pesca." << endl;
		// PescaUnaCarta
		// la metto in MyHand (push_back())
		ManoPC.push_back(PescaUnaCarta(M));
		// stampo la mia mano
		// StampaMano(ManoPC);
		// stampo il tavolo (invariato)
		StampaTavolo(in_tavola);		
	}
	
}

int main()
{
	srand(time(NULL));

	// ------- SITUAZIONE INIZIALE -------

	cout << endl << " \t \t \t*** UNO - by Lorenzo La Corte *** " << endl << endl;

	vector<Carta> Deck(56); // vettore per il mazzo
	GeneraMazzo(Deck); // genero il mazzo
	
	/* StampaMazzo(Deck); */ // debug

	vector<Carta> MyHand(7); // vettore per la mia mano
	ManoIniziale(Deck, MyHand); // genero la mia mano

	vector<Carta> PCHand(7); // vettore per la mano del PC
	ManoIniziale(Deck, PCHand); // genero per la mano del PC

	// variabile per carta sul tavolo
	Carta Tavolo;

	// pesca una carta e mettila sul tavolo (stampala) 
	// la carte deve essere NON speciale (cicla finche' non lo e')
	do{	
		Tavolo = PescaUnaCarta(Deck);
	} while(Tavolo.numero > 10);

	StampaTavolo(Tavolo);
	
	// ------- SITUAZIONE IN GIOCO -------

	// Finchè qualcuno ha 0 carte (ha vinto e finisce tutto)
	while(MyHand.size() != 0 && PCHand.size() != 0)
	{
		// Giocatore Gioca una carta
		MiaGiocata(Deck, MyHand, Tavolo, PCHand); 

		// Se non ho già vinto
		if(MyHand.size() != 0)	
			// PC Gioca una carta
			PCGiocata(Deck, MyHand, Tavolo, PCHand);
	}
	
	// ------- SITUAZIONE FINALE -------

	// Guardo chi ha vinto
	if(MyHand.size() == 0)
		cout << "HAI VINTO!!" << endl;

	if(PCHand.size() == 0)
		cout << "Ha Vinto il tuo avversario, riprova!" << endl << endl;
 
	cout << endl;
}