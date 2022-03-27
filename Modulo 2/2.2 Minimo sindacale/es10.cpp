// La Corte Lorenzo - Es. 10
/* Scrivere un programma che legge da input un numero intero Temp e stampa: 
• “Freddo dannato” se Temp è compreso fra −20 e 0 
• “Freddo” se Temp è compreso fra 1 e 15 
• “Normale” se Temp è compreso fra 16 e 23 
• “Caldo” se Temp è compreso fra 24 e 30 
• “Caldo da morire” se Temp è compreso fra 31 e 40 
• “Non ci credo, il termometro deve essere rotto” se Temp è superiore a 40 o inferiore a −20
*/

#include <iostream>
using namespace std;

int main()
{
int temp;

cout << "Quanti gradi ci sono?" << endl;
cin >> temp;

	if (temp < -20 || temp > 40)
		cout << "Non ci credo, il termometro deve essere rotto" << endl;
	
	if (temp >= -20 && temp <= 0)
		cout << "Fa un freddo dannato" << endl;
		
	if (temp >=1 && temp <=15)
		cout << "Fa freddo" << endl;
		
	if (temp >=16 && temp <=23)
		cout << "Clima mite" << endl;

	if (temp >=24 && temp <=30)
		cout << "Fa caldo" << endl;
	
	if (temp >=31 && temp <=40)
		cout << "Fa caldo" << endl;

return 0;
}