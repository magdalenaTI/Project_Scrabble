/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Magdalena Ivanova
* @idnumber 62513
* @compiler VC
*
* <file with helper functions>
*
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
#pragma warning (disable:4996)

//This function "tell" us if the user input is valid or not
// Upper case is also valid input, but we transform it
// into lower case, because we work only with it (so as it is in the dictionary)
bool stringToLowerAlpha(string userInput, string& validInput) {
    int inputSize = userInput.length();

// Work with char because some functions (like srtcpy)
//work easier with it (than with string)
    char* userInputChar = new char[inputSize + 1];
    strcpy(userInputChar, userInput.c_str());
    for (int i = 0; i < inputSize; i++) {
        if (userInputChar[i] >= 'A' && userInputChar[i] <= 'Z')
            userInputChar[i] = userInputChar[i] - 'A' + 'a';
        if (userInputChar[i] < 'a' || userInputChar[i] > 'z')
            return false;
    }
    validInput = string(userInputChar);
    delete[] userInputChar;
    return true;
}

// Function which generate random letters
string getLetters(int lettersCount) {

    srand((unsigned int)time(NULL));
    string result;

// Every word includes one or more vowel letters
// But without explicit addition the random letters not always includes a vowel one
// This makes the game impossible 
    int numberOfVowels = lettersCount / 4;
    for (int j = 0; j < numberOfVowels; j++) {

        // generate vowel letters
        char vowel = 'a' + rand() % 26; 
        while (vowel != 'a' && vowel != 'e' && vowel != 'i' && vowel != 'o' && vowel != 'u') {
            vowel = 'a' + rand() % 26;
        }
        result.push_back(vowel); // add the vowel letters into the result string
    }
    for (int i = numberOfVowels; i < lettersCount; i++) {
        result.push_back('a' + rand() % 26);// Add the letters into the result string
    }

    return result;
}

bool validation(vector<string> dictionary, string userInput, string letters) {

    // With no input the game cannot exist, so it have to have some
    if (userInput.length() == 0) return false;
    const int lettersInAlphabet = 26;

    //Array in which we will mark how many times every letter 
    //is met in the string from random letters
    int histogramLetters[lettersInAlphabet] = { 0 };

    //Array in which we will mark how many times every letter 
    //is met in the string from the user input letters
    int histogramUserInput[lettersInAlphabet] = { 0 };

    for (auto it = letters.cbegin(); it != letters.cend(); it++) {
        histogramLetters[(int)(*it - 'a')]++;

    }
    for (auto it = userInput.cbegin(); it != userInput.cend(); it++) {
        histogramUserInput[(int)(*it - 'a')]++;

    }

    //If some letter is used more times from the user than determined
    //it breaks the rules of the game, so the validation will not
    //let it happen
    for (int i = 0; i < lettersInAlphabet; i++) {
        if (histogramLetters[i] < histogramUserInput[i]) {
            cout << "Your word is not a valid one! Try again with the letters given! " << endl;
            return false;
        }
    }

    // Check if the user word is in the dictionary
    if (find(dictionary.begin(), dictionary.end(), userInput) == dictionary.end()) {

        cout << " The word is not found in the dictionary!" << endl;
        return false;
    }

    return true;

}

void startNewGame(vector<string> dictionary, vector<int> settings) {

    int points = 0; // The points from the words entered

    // The number of the letters as first element of the vector
    int lettersCount = settings[0]; 

    // The number of the rounds as second element of the vector
    int roundsCount = settings[1];

    //Actions in one round of the game
    for (int i = 0; i < roundsCount; i++) {
        string letters = getLetters(lettersCount);
        cout << "You have the following letters: " << endl ;

        //Generate letters
        for (int j = 0; j < lettersCount; j++) {
            cout << letters[j] << " ";
        }

        string userInput, validInput;
        cout << "\nEnter a word: "<< endl;
        cin >> userInput;

        //Check if the word entered is a string
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            cin >> userInput;
        }

        //Check if the string entered contains only letters
        while (!stringToLowerAlpha(userInput, validInput)) {
            cout << "Invalid word!" << endl;
            cout << "Enter new word: " << endl;
            cin >> userInput;
        }

        //Check if the rules of the game are followed
        while (!validation(dictionary, validInput, letters)) {

            //If not the letters are shown and the user will have to 
            //enter until the input is correct
            cout << "You have the following letters: " << endl;
            for (int j = 0; j < lettersCount; j++) {
                cout << letters[j] << " ";
            }
            cout << "\nEnter a word: ";
            cin >> userInput;
            while (!stringToLowerAlpha(userInput, validInput)) {
                cout << "Invalid word!" << endl;
                cout << "Enter new word: " << endl;
                cin >> userInput;
            }


        }
        //After finishing the game the user can see it's points.
        //They are equal to the sum of the lengths of the words he has entered
        points += userInput.length();
        cout << "Your points are: " << points << endl;


    }
    cout << "You finished! Your points are: " << points << endl;
}


void options(vector<int>& settings) {
    //The user can change the number of the letters or the number
    //of the rounds he will play during one whole game
    cout << "What would you like to change?" << endl;
    cout << "Press 1 to change the number of the letters." << endl;
    cout << "Press 2 to change the number of the rounds." << endl;
    char answerUser;
    cin >> answerUser;

    //Check if the answer entered is a string
    while (cin.fail()) {
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       cout << "Invalid input!" << endl;
       cin >> answerUser;
    }

    //Check if the user choose an option
    while (answerUser != '1' && answerUser != '2') {
        cout << "Please, choose first or second option!" << endl;
        cin >> answerUser;
    }

    unsigned int corrections;

    if (answerUser == '1') {
        cout << "Enter  new number of letters: " << endl;
        cin >> corrections; // The new number of letters
        //Check if the correction is a number
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            cin >> corrections;
        }

        //The user change the first element of the vector we save the
        //number of the letters and the number of the rounds
        settings[0] = corrections;

    }
    else {
        cout << "Enter  new number of rounds: " << endl;
        cin >> corrections; //The new number of rounds
        //Check if the correction is a number
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            cin >> corrections;
        }

        //The user change the second element of the vector we save the
        //number of the letters and the number of the rounds
        settings[1] = corrections;
    }

}

void addNewWord(vector<string>& dictionary, fstream& words) {

    string userInput, validInput;

    //When the user have chosen the option to add a new word
    //we save it at the end of the dictioary
    cout << "Enter your word: ";
    cin >> userInput;

    //Check if the word entered is a string
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        cin >>userInput;
    }

    //Check if the string entered contains only letters
    while (!stringToLowerAlpha(userInput, validInput)) {
        cout << "Invalid word!" << endl;
        cout << "Enter new word: " << endl;
        cin >> userInput;
    }

    //The file with the words
    if (words.is_open()) {
        //Search if the word is not in the dictonary
        if (find(dictionary.begin(), dictionary.end(), validInput) == dictionary.end()) {
            dictionary.push_back(validInput); //Add the word after the last word
            words.clear();
            words << validInput << endl;
            cout << "The word was successfully added!" << endl;
        }
    }
    else {
        //If the file cannot be open
        cerr << "Error writing to file!" << endl;
    }
}

int main() {
    //We hold the words in vector from strings, which
    //we load from the file with words
    vector<string> dictionary;

    fstream words;

    //We open the file with the words
    words.open("words.txt", ios::in | ios::app | ios::out);
    if (words.is_open()) {

        //Read from the dictionary
        cout << "Loading dictionary..." << endl;
        string word;
        while (getline(words, word)) {
            dictionary.push_back(word);
        }
        cout << "Done." << endl;
    }
    else {
        cerr << "Error reading from file!" << endl;
    }

    string userInput;

    //The default number of the letters and the rounds is 10
    //If willing the user can change it
    vector<int>settings;
    settings.push_back(10);
    settings.push_back(10);

    while (true) {
        //The start menu
        cout << "Press 1 to start a new game." << endl;
        cout << "Press 2 to change game options." << endl;
        cout << "Press 3 to add a new word." << endl;
        cout << "Press 4 to exit the game." << endl;

        cin >> userInput;
        //Check if the user input is a number
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            cin >> userInput;
        }
        //Calling the different functions depending on the user's choice
        if (userInput == "1") {
            startNewGame(dictionary, settings);
        }
        else if (userInput == "2") { 
            options(settings);
        }
        else if (userInput == "3") { 
            addNewWord(dictionary, words);
        }
        else if (userInput == "4") { 
            return 0;
        }
        else cout << "Wrong input! Enter again!" << endl;
    }

}


