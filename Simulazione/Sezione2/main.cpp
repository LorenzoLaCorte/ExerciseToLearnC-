#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Text.h"

using namespace std;

// Implementazioni delle funzioni per il tipo Text
text readText(const std::string filename) {
    
    ifstream infile(filename);
    if (!infile) {
        string msg = "File non trovato: " + filename;
        throw(msg);
    }
    
    text T = nullptr;
    word_cell *current = nullptr;
    
  
    std::string tmp_str;
    while(infile >> tmp_str) {
        
        word_cell *WC = new word_cell;
        WC->word = tmp_str;
        WC->next = nullptr;
            
        if(T == nullptr)
            T = WC;
        else
            current->next = WC;
        current = WC;
        
    }

    infile.close();
    
    return T;
}

void printText(const text mytext) {
    
    cout << endl;
    
    word_cell *WC = mytext;
    
    int nwords4row = 0;
    while(WC != NULL) {
        
        cout << WC->word << " ";
        WC = WC->next;
        
        ++nwords4row;
        
        if(nwords4row == 10) {
            cout << endl;
            nwords4row = 0;
        }
    }
    cout << endl << endl;
}

void showMenu(const string& msg, const vector<string>& menu){
    cout<<endl<<msg<<endl;
    for (int i = 1; i <= menu.size(); ++i) {
        cout<<i<<'\t'<<menu.at(i-1)<<endl;
    }
}

// Gets a choice in [1,maxChoice]
int getChoice(const int& maxChoice){
    int choice=0;
    cin>>choice;
    while(choice<=0||choice>maxChoice){
        cout<<endl<<"Scelta non riconosciuta, riprovare: ";
        cin.clear();
        cin.ignore();
        cin>>choice;
    }
    return choice;
}



// Makes the call under test and prints its result
void printTestResult(const bool& res, text& T){
    
    if(res) {
        cout << "Scegli la parola da cercare ";
        std::string myWord;
        cin >> myWord;
        
        int pos;
        if(findWord(T, myWord, pos))
            cout << endl << "Parola trovata alla posizione " << pos << endl;
        else
            cout << endl << "Parola non trovata nel testo." << endl;
        
    } else {
        
        cout << "Scegli la parola da eliminare ";
        std::string myWord;
        cin >> myWord;
        
        if(removeWordFromText(T, myWord))
            cout << endl << "Parola eliminata." <<  endl;
        else
            cout << endl << "Parola non trovata nel testo." << endl;

        printText(T);
    }
    
}

int main() {
    
    cout << endl << "Scegli il nome del file di input: ";
    string filename;
    cin >> filename;
    
    try {
        // Leggo il file per popolare il testo
        text T = readText(filename);
        // Stampo il testo
        printText(T);
        
        char continuing='y';
        do {
            
            vector<string> testFunChoices;
            testFunChoices.push_back("findWord");
            testFunChoices.push_back("removeWordFromText");
            
            cout << endl;
            showMenu("Scegli la funzione su cui vuoi eseguire il test ",testFunChoices);
            int funChoice=getChoice(testFunChoices.size());

            printTestResult(1==funChoice, T);
            
            cout<<endl<<"Vuoi continuare con altri test? ('y'/'n' default 'n')"<<endl;
            cin>>continuing;
            continuing = tolower(continuing);
            
        } while('n'!=continuing);
    } catch(string msg) {
        cout << msg << endl;
        return -1;
    }
    return 0;
    
}
