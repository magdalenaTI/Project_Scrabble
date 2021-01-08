#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

string getLetters(int letters) {

    srand(time(NULL));
    string result;
   
    const int size = 10;
    for (int i = 0; i < size; i++) {
    result.push_back('a' + rand() % 26);
    }
    return result;

   
}
bool validation(vector<string> dictionary, char userInput[], string letters) {

}


void startNewGame(vector<string> dictionary, vector <int> gameOptions) {

    int letters, rounds;
    vector<string> dictionary;

}


void options(vector<int>& settings) {
    
}


void addNewWord(vector<string>& dictionary, fstream words) {

    string userInput;
  
    cout << "Enter your word";
    cin >> userInput;
    if (words.is_open())
    {
        if (find(dictionary.begin(), dictionary.end(), userInput) == dictionary.end())
        {
            dictionary.push_back(userInput);
           
            words.open("words.txt", ios::app);

            words << userInput;
        }
    }
    else
    {
        cerr << "Error reading from file!" << endl;
       
    }
   
}

int main() {

    vector<string> dictionary;

    fstream words;

    words.open("words.txt", ios::in | ios::app);
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
        cout << "Press 1 to start a new game." << endl;
        cout << "Press 2 to change game options." << endl;
        cout << "Press 3 to add a new word." << endl;
        cout << "Press 4 to exit the game." << endl;

        cin >> userInput;
        if (userInput == "1") { startNewGame(); }
        if (userInput == "2") { options(); }
        if (userInput == "3") { addNewWord(); }
        if (userInput == "4") { return 0; }

    }

    vector<int>settings;
}

