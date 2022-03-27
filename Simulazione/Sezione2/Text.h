#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>

// cella: contiene la parola (string) ed il puntatore alla cella successiva
struct word_cell {
	std::string word;
	word_cell* next;
};

// testo: è un puntatore ad una cella
typedef word_cell* text;

// FUNZIONI CHE VENGONO FORNITE
text readText(const std::string filename);
void printText(const text mytext);

// FUNZIONI CHE DOVETE IMPLEMENTARE
bool findWord(const text mytext, const std::string myWord, int& pos);
bool removeWordFromText(text& mytext, const std::string myWord);

#endif
