/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                     *
 *   Name: Reinier Garcia Ramos                                                        *
 *                                                                                     *
 *   Program Title: Character Analysis                                                 *
 *                                                                                     *
 *   Purpose:                                                                          *
 *   Reads a .txt file and determines the amount of digits, uppercase and lowercase    *
 *   letters on it. It also dtermines the same from a constant string object.          *
 *                                                                                     *
 *   More Details:                                                                     *
 *   https://github.com/reymillenium/20240707_2000_challenge1015_character_analysis    *
 *                                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include <filesystem>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
using std::to_string;
using std::vector;
using std::regex;
using std::regex_match;
using std::stoi;
using std::isalpha;
using std::count_if;
using std::filesystem::exists;
using std::ifstream;
using std::ofstream;
using std::ios_base;


// UTILITY FUNCTIONS PROTOTYPES


// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input);

// Receives and validates an integer number from the console
int getInteger(const string &, int, int, bool = false, const string & = "Invalid input. Please try again.", const vector<int> & = {});

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &);

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Detects if a given filename exist or not on the root of the executable file
bool fileExist(const string &);

// Gets all the non-empty lines of text inside a given file name
vector<string> getLinesFromFile(const string &);

// Either creates a .txt file and adds a single line of text to it, or adds it to an existent one
void addTextToFile(const string &);


// CUSTOM MADE FUNCTIONS PROTOTYPES


// Shows the program's welcoming message
void showProgramWelcome();

// Shows the menu to the user
void showMenu(bool = false);

// Analyses a constant string object and reports the amount of digits, as well as uppercase & lowercase letters
void analyseSimpleStringObject();

// Analyses a given file name and reports the amount of digits, as well as uppercase & lowercase letters
void analyseOurTextFile(const string &);

// Displays the results to the user on the terminal
void displayResults(long int, long int, long int, const string & = "string");

// Processes the selection made by the user, based on the options of the menu
void processSelection(int selection, bool, const string &);

// Main Function
int main() {
    const string FILE_NAME = "text.txt"; // The name of the file to save text
    bool theFileExists = false; // If the file with text was already saved in the root of the executable
    int menuSelectedOption = 0; // The selection made by the user from the options of the menu
    int quittingOption = 3; // The option number on the menu that allows to quit the program

    // Shows the program's welcoming message
    showProgramWelcome();

    do {
        // Detects if the text file already exist
        theFileExists = fileExist(FILE_NAME);

        // Adjusts the quitting option number, based in the existence or not of the text file
        quittingOption = theFileExists ? 4 : 3;

        // Shows the menu with some options to the user
        showMenu(theFileExists);

        // Gets the selected menu option from the user
        menuSelectedOption = getInteger("Type your selection please", 1, quittingOption);

        // Processes the selection made by the user
        processSelection(menuSelectedOption, theFileExists, FILE_NAME);
    } while (menuSelectedOption != quittingOption);

    return 0;
}


// UTILITY FUNCTIONS DEFINITIONS


// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input) {
    const regex pattern("^[+-]?[0-9]+$");
    return regex_match(input, pattern);
}

// Receives and validates an integer number from the console
int getInteger(const string &message, const int minValue, const int maxValue, const bool showRange, const string &errorMessage, const vector<int> &sentinelValues) {
    string numberAsString; // Value typed by the user, that can be an integer or not
    int number = 0; // Integer convertion (if possible) of the value typed by the user
    bool keepAsking = true; // If we must keep asking for a value to the user, until receiving an integer

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        getline(cin, numberAsString);

        if (!isInteger(numberAsString)) {
            cout << "That's not an integer number. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even an integer
        }

        number = stoi(numberAsString); // When we reach this point, that means we have a proper integer
        const bool invalidInput = number < minValue || maxValue < number; // If the input is valid, based only in minimum & maximum possible values
        // If the typed number is not among the given sentinel values (breaking values)
        const bool numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), number) == 0;
        keepAsking = invalidInput && numberIsNotSentinel;
        if (keepAsking) cout << errorMessage << endl;
    } while (keepAsking);

    return number;
}

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &message) {
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Detects if a given filename exist or not on the root of the executable file
bool fileExist(const string &fileName) {
    bool theFileExist = false; // If the file with text was already saved in the root of the executable

    if (exists(fileName))
        theFileExist = true;

    return theFileExist;
}

// Gets all the non-empty lines of text inside a given file name
vector<string> getLinesFromFile(const string &fileName) {
    ifstream inputFile(fileName);
    vector<string> lines;

    if (inputFile.is_open()) {
        string line; // one single line at the time, to be read from the file

        while (getline(inputFile, line)) {
            if (!line.empty()) // If the line is empty then it's not interesting for us
                lines.push_back(line);
        }
    } else {
        cerr << "Error opening file\n";
    }

    // Closing the input file
    inputFile.close();

    return lines;
}

// Either creates a .txt file and adds a single line of text to it, or adds it to an existent one
void addTextToFile(const string &fileName) {
    // Opens the input file & keeps the existing data (opens in append mode)
    ofstream outputFile(fileName, ios_base::app);
    // string textLine;

    if (outputFile.is_open()) {
        // We temporally store a single line of text, to be saved/added later to the .txt file
        const string textLine = getStringFromMessage("Write a single line of text please: ");
        if (!textLine.empty()) // There is no point on adding an empty string
            outputFile << textLine << endl;
    } else {
        cerr << "Error opening file\n";
    }

    // Closing the output file
    outputFile.close();
}


// CUSTOM MADE FUNCTIONS DEFINITIONS


// Shows the program's welcoming message
void showProgramWelcome() {
    cout << endl;
    cout << "Welcome to Character Analysis Pro" << endl;
}

// Shows the menu to the user
void showMenu(const bool fileExists) {
    cout << endl;
    cout << "1. Simple & boring character analysis from a string object." << endl;
    cout << "2. " << (fileExists ? "Add more" : "Save some") << " text to" << (fileExists ? " our" : " a") << " file, so we can analyse it later." << endl;
    if (fileExists)
        cout << "3. Fun Y Cool Character Analysis of our text file." << endl;
    cout << (fileExists ? 4 : 3) << ". Quit the program." << endl;
    cout << endl;
}

// Analyses a constant string object and reports the amount of digits, as well as uppercase & lowercase letters
void analyseSimpleStringObject() {
    const string simpleTextToAnalyse = "The quick Brown Fox jumps over the 23 lazy dogs.";
    int upperCaseLettersAmount = 0; // The amount of uppercase letters in the string
    int lowerCaseLettersAmount = 0; // The amount of lowercase letters in the string
    int digitsAmount = 0; // The amount of digits in the string

    // Then we determine each one of our counters
    upperCaseLettersAmount = count_if(simpleTextToAnalyse.begin(), simpleTextToAnalyse.end(),
                                      [](const unsigned char ch) { return isupper(ch); });
    lowerCaseLettersAmount = count_if(simpleTextToAnalyse.begin(), simpleTextToAnalyse.end(),
                                      [](const unsigned char ch) { return islower(ch); });
    digitsAmount = count_if(simpleTextToAnalyse.begin(), simpleTextToAnalyse.end(),
                            [](const unsigned char ch) { return isdigit(ch); });

    displayResults(upperCaseLettersAmount, lowerCaseLettersAmount, digitsAmount);
}

// Analyses a given file name and reports the amount of digits, as well as uppercase & lowercase letters
void analyseOurTextFile(const string &fileName) {
    long int upperCaseLettersAmount = 0; // The amount of uppercase letters in the string
    long int lowerCaseLettersAmount = 0; // The amount of lowercase letters in the string
    long int digitsAmount = 0; // The amount of digits in the string

    // We get all the non-empty lines of text from the file
    const vector<string> textLinesFromFile = getLinesFromFile(fileName);

    // And now we increment each one of our counters on each loop, based on each line of text
    for (string textLine: textLinesFromFile) {
        upperCaseLettersAmount += count_if(textLine.begin(), textLine.end(),
                                           [](const unsigned char ch) { return isupper(ch); });
        lowerCaseLettersAmount += count_if(textLine.begin(), textLine.end(),
                                           [](const unsigned char ch) { return islower(ch); });
        digitsAmount += count_if(textLine.begin(), textLine.end(),
                                 [](const unsigned char ch) { return isdigit(ch); });
    }

    displayResults(upperCaseLettersAmount, lowerCaseLettersAmount, digitsAmount, "file");
}

// Displays the results to the user on the terminal
void displayResults(const long int upperCaseLettersAmount, const long int lowerCaseLettersAmount, const long int digitsAmount, const string &source) {
    cout << "" << endl;
    cout << "Character Analysis Results:" << endl;
    cout << "The " << source << " contains " << humanizeUnsignedInteger(digitsAmount) << " digits, ";
    cout << humanizeUnsignedInteger(upperCaseLettersAmount) << " uppercase letters & ";
    cout << humanizeUnsignedInteger(lowerCaseLettersAmount) << " lowercase letters." << endl;
}

// Processes the selection made by the user, based on the options of the menu
void processSelection(const int selection, const bool fileExist, const string &fileName) {
    switch (selection) {
        case 1:
            analyseSimpleStringObject();
            break;
        case 2:
            addTextToFile(fileName);
            break;
        case 3:
            if (fileExist)
                analyseOurTextFile(fileName);
            break;
        default:
            break;
    }
}
