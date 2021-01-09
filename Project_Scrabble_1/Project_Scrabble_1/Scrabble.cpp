#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

string getLetters(int lettersCount) {

    srand((unsigned int)time(NULL));
    string result;
    int numberOfVowels = 3;
    for (int i = 0; i < lettersCount; i++) {
        char letters = 'a' + rand() % 26;
        result.push_back('a' + rand() % 26);
    }
    return result;
}

bool validation(vector<string> dictionary, string userInput, string letters) {
    if (userInput.length() == 0) return false;
   

    int histogramLetters[26] = { 0 };
    int histogramUserInput[26] = { 0 };

    for (auto it = letters.cbegin(); it != letters.cend(); it++) {
        histogramLetters[(int)(*it - 'a')]++;

    }
    for (auto it = userInput.cbegin(); it != userInput.cend(); it++) {
        histogramUserInput[(int)(*it - 'a')]++;

    }
    for (int i = 0; i < 26; i++) {
        if (histogramLetters[i] < histogramUserInput[i]) {
            cout << "Your word is not a valid one! Try again with the letters given!"<< endl;
            return false;
        }
    }

    if (find(dictionary.begin(), dictionary.end(), userInput) == dictionary.end()) { 
        
        cout << " The word is not found in the dictionary!" << endl;
        return false; 
    }
     
    return true;

}

void startNewGame(vector<string> dictionary, vector<int> settings) {

    int points = 0;
    int lettersCount = settings[0];
    int roundsCount= settings[1];
    for (int i = 0; i < roundsCount; i++) {
        string letters = getLetters(lettersCount);
        cout << "You have the following letters: ";
        for (int j = 0; j < lettersCount; j++) {
            cout << letters[j] << " ";
        }

        string userInput;
        cout << "Enter a word: "; 
        cin >> userInput; 
    
        while (!validation(dictionary, userInput, letters)) {
          
            cout << "You have the following letters: ";
            for (int j = 0; j < lettersCount; j++) {
                cout << letters[j] << " ";
            }
            cout << "Enter a word: ";
            cin >> userInput;
       }
        points += userInput.length();
        cout << "Your points are: " << points << endl;

    }

    cout << "You finished! Your points are: " << points << endl;

}


void options(vector<int>& settings) {
    cout << "What would you like to change?"; 
    
        char answerUser;
}

void addNewWord(vector<string>& dictionary, fstream& words) {

    
    string userInput; 

    cout << "Enter your word";
    cin >> userInput;

    
    if (words.is_open())
    {
        if (find(dictionary.begin(), dictionary.end(), userInput) == dictionary.end())
        {
            dictionary.push_back(userInput);

            words << userInput;
            cout << "The word was successfully added!" << endl;
        }
    }
    else
    {
        cerr << "Error writing to file!" << endl;
        
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
    vector<int>settings;
    settings.push_back(10);
    settings.push_back(10);

    while (true) {
        cout << "Press 1 to start a new game." << endl;
        cout << "Press 2 to change game options." << endl;
        cout << "Press 3 to add a new word." << endl;
        cout << "Press 4 to exit the game." << endl;

        cin >> userInput;
        if (userInput == "1") { startNewGame(dictionary, settings); }
        else if (userInput == "2") { options(settings); }
        else if (userInput == "3") { addNewWord(dictionary, words); }
        else if (userInput == "4") { return 0; }
        else cout << "Wrong input! Enter again!" << endl;
    }

}

