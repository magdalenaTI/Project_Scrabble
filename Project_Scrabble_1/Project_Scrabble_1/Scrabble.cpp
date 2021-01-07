#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void startNewGame(vector<string> dictionary) {

}

void options() {
   
}
void addNewWord() {
  
}
void mainMenu(int userInput) {
    switch (userInput) {
    case 1: startNewGame(); break;
    case 2: options(); break;
    case 3: addNewWord(); break;
    case 4: return; break;
    default: break;
    }
}

int main() {

    vector<string> dictionary;
    fstream words;

    words.open("words.txt", ios::in | ios::out);
    if (words.is_open())
    {
        cout << "Loading dictionary..." << endl;
        string word;
        while (getline(words, word))
        {
            dictionary.push_back(word);
        }
        cout << "Done." << endl;
    }
    else
    {
        cerr << "Error reading from file!" << endl;
    }


    string userInput;

    while (true) { 
        cout << "Press 1 to strat new game" << endl;
        cout << "Press 2 for options" << endl;
        cout << "Press 3 to add new word" << endl;
        cout << "Press 4 to finish" << endl;
        cin >> userInput;
        if (userInput == "1") { startNewGame(); }
        if (userInput == "2") { options(); }
        if (userInput == "3") { addNewWord(); }
        if (userInput == "4") { return 0; }

    }

    

}

