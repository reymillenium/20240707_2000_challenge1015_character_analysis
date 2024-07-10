/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 *   Name: 07-Arrays-intro                                             *
 *                                                                     *
 *   Purpose:                                                          *
 *   Receives 10 integers provided by the user from the console,       *
 *   and stores them in an array. And then based on them, it           *
 *   calculates the sum, the average and the largest element.          *
 *                                                                     *
 *   More Details:                                                     *
 *   https://github.com/reymillenium/20240621_0127_arrays_intro        *
 *                                                                     *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <climits> // For SHRT_MAX, SHRT_MIN, etc
#include <limits> // For SHRT_MAX, SHRT_MIN, etc
#include <iomanip> // for setprecision, setw, fixed
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream (used in humanizeInteger, humanizeDouble, etc)
#include <vector> // to use vectors
#include <fstream> // For ifstream, ofstrea, fstream
#include <numeric> // For accumulate, transform_reduce, inner_product (in the vectors)
#include <algorithm> // For max_element, min_element, find, transform (to use in vectors), or for max(), reverse
#include <regex> // For regex, regex_match
#include <cstring> // For strrev

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::setw;
using std::setfill;
using std::string;
using std::to_string;
using std::stringstream;
using std::accumulate;
using std::vector;
using std::find;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::stoi;
using std::stod;
using std::isalpha;

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &);

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &, int);

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &);

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &, int);

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &) -> T;

// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input);

// Determines if a given string is a valid floating point number, using a regular expression
bool isFloatingPoint(const string &input);

// Receives and validates an integer number from the console
int getInteger(const string &, int, int, bool = false, const string & = "Invalid input. Please try again.", const vector<int> & = {});

// Receives and validates a double number (or the equivalent of an integer) from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.", const vector<double> & = {});

// Determines if a given string is a single valid char
bool containsSingleChar(const string &input);

// Receives and validates a char from the console
char getAlphaChar(const string &, const string & = "Invalid input. Please try again.");

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &);

// Gets a string with or without spaces, from the terminal
string getString();

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(long long int);

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(long double, int = 2);

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(unsigned long int, bool = true, const string & = "$");

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(long double, int = 2, bool = true, const string & = "$");

// Rounds up a given double number, with a given amount of decimal places
double roundUp(double, int);

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(unsigned long long int);

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

// Determines is a given int number is prime or not
bool isPrime(unsigned long long int);

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegersInArray(const int [], int);

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegersInArray(const int [], int);

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&)[N]);

// Calculates the sum of all the elements inside an array of doubles
double simpleSumOfDoublesInArray(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
double neatSumOfDoublesInArray(const double [], int);

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&)[N]);

template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&)[N][M]);

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegersInArray(const int [], int);

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegersInArray(const int [], int);

// Calculates the average among all the numbers inside an array of integers
template<int N>
int templateAverageAmongIntegersInArray(int (&)[N]);

// Calculates the average among all the numbers inside an array of doubles
double simpleAverageAmongDoublesInArray(const double [], int);

// Calculates the average among all the numbers inside an array of doubles
double neatAverageAmongDoublesInArray(const double [], int);

template<int N>
double templateAverageAmongDoublesInArray(double (&)[N]);

template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&)[N][M]);

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int [], int);

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int [], int);

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double [], int);

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double [], int);

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&)[N][M]);

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&)[N][M]);

// Determines if the given value is lower than the also given minimum value
bool isInvalid(long double value, double);

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(long double, double);

// Function to validate the DateTime(YYYY-MM-DD HH:MM:SS)
bool validDateTime(const string &);

// Function to extract all the components of a DateTime(YYYY-MM-DD HH:MM:SS)
vector<string> getComponentsFromDateTime(const string &);

// Function to extract the year from a DateTime(YYYY-MM-DD HH:MM:SS)
string getYearFromDateTime(const string &);

// Function to extract the month from a DateTime(YYYY-MM-DD HH:MM:SS)
string getMonthFromDateTime(const string &);

// Function to extract the day from a DateTime(YYYY-MM-DD HH:MM:SS)
string getDayFromDateTime(const string &);

// Function to extract the hours from a DateTime(YYYY-MM-DD HH:MM:SS)
string getHoursFromDateTime(const string &);

// Function to extract the minutes from a DateTime(YYYY-MM-DD HH:MM:SS)
string getMinutesFromDateTime(const string &);

// Function to extract the seconds from a DateTime(YYYY-MM-DD HH:MM:SS)
string getSecondsFromDateTime(const string &);

// Function to convert from a military Time (24 hours format) to civilian Time (12 hours format with meridian)
string convertTimeToCivilian(int, int);

// CUSTOM FUNCTIONS

template<int N>
void loadRainfalls(const vector<string> &, double (&)[N]);

template<int N>
void loadRainfallsPlus(const vector<string> &, double (&)[N]);

// template<size_t a, size_t b>
template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &, double (&)[N][M]);

template<int N, int M>
void loadMonkeysFoodArraySlim(const vector<string> &, double (&)[N][M]);

string getLeastRainfallMonth(const vector<string> &, double [], int);

string getMostRainfallMonth(const vector<string> &, double [], int);

void displayResults(double, double, double);

// class MonthlyRainLog {
// public:
//     string monthName;
//     double rainAmount;
//
//     // dummy constructor
//     MonthlyRainLog() {
//     }
//
//     // Parameterized constructor
//     MonthlyRainLog(const string &aMonthName, const double &aRainAmount) {
//         monthName = aMonthName;
//         rainAmount = aRainAmount;
//     }
// };

// Main Function
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

// Prints a given value, of almost any kind, once in the terminal
template<typename T>
void print(const T &item) {
    cout << item;
}

// Prints a given value, of almost any kind, N given times in the terminal
template<typename T>
void printNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        print(item);
    }
}

// Prints a given value, of almost any kind, once in the terminal, and then breaks the line
template<typename T>
void printLine(const T &item) {
    cout << item << endl;
}

// Prints a given value, of almost any kind, N given times in the terminal, and then breaks the line
template<typename T>
void prinLineNTimes(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        printl(item);
    }
}

// Gets several types of values from the console (except strings with spaces, objects, etc, among others), as a response of a given question
template<typename T>
auto getValue(const string &message) -> T {
    cout << message;
    T value;
    cin >> value;
    cin.ignore();
    return value;
}

// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input) {
    const regex pattern("^[+-]?[0-9]+$");
    return regex_match(input, pattern);
}

// Determines if a given string is a valid floating point number, using a regular expression
bool isFloatingPoint(const string &input) {
    // const regex pattern("^[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?$");
    const regex pattern(R"(^[+-]?[0-9]+(.[0-9]+)?([eE][+-]?[0-9]+)?$)");
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

        if (const bool isIntegerNumber = isInteger(numberAsString); !isIntegerNumber) {
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

// Receives and validates a double number (or the equivalent of an integer) from the console
double getDouble(const string &message, const double minValue, const double maxValue, const bool showRange, const string &errorMessage, const vector<double> &sentinelValues) {
    string numberAsString; // Value typed by the user, that can be a valid (integer or floating point) number or not
    double number = 0; // Double convertion (if possible) of the value typed by the user
    bool keepAsking = true; // If we must keep asking for a value to the user, until receiving either an integer or a flating point number

    do {
        cout << fixed << setprecision(2) << message;
        if (showRange)
            cout << " (" << minValue << " - " << maxValue << ")";
        cout << ": ";
        getline(cin, numberAsString);

        if (const bool isIntegerOrFloatingPointNumber = isInteger(numberAsString) || isFloatingPoint(numberAsString); !isIntegerOrFloatingPointNumber) {
            cout << "That's not an integer number nor a valid floating point number. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even a valid integer nor a floating point number
        }

        number = std::stod(numberAsString); // When we reach this point, that means we have either a proper integer or a floating point number
        const bool invalidInput = number < minValue || maxValue < number; // If the input is valid, based only in minimum & maximum possible values
        // If the typed number is not among the given sentinel values (breaking values)
        const bool numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), number) == 0;
        keepAsking = invalidInput && numberIsNotSentinel;
        if (keepAsking) cout << errorMessage << endl;
    } while (keepAsking);

    return number;
}

bool containsSingleChar(const string &input) {
    if (input.empty() || input.length() > 1) return false;
    return true;
}

char getAlphaChar(const string &message, const string &errorMessage) {
    string characterAsString; // Value typed by the user, that can be a char or not
    char character = 'A'; // Char convertion (if possible) of the value typed by the user
    bool isNotAlphaCharacter = true; // If the character is alphabetic

    do {
        cout << message << ": ";
        getline(cin, characterAsString);

        if (!containsSingleChar(characterAsString)) {
            cout << "That's not a single character. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even a valid char
        }

        // const char *characterPointer = characterAsString.data(); // Only valid on C++ 17 or newer
        const char *characterPointer = characterAsString.c_str();
        character = characterPointer[0];

        isNotAlphaCharacter = !isalpha(character);
        if (isNotAlphaCharacter) cout << errorMessage << endl;
    } while (isNotAlphaCharacter);

    return character;
}

// Gets a string with or without spaces, from the terminal, as a response of a given question
string getStringFromMessage(const string &message) {
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

// Gets a string with or without spaces, from the terminal
string getString() {
    string value;
    getline(cin, value);
    return value;
}

// Formats a given negative or positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeInteger(const long long int integerValue) {
    const bool isNegative = integerValue < 0;
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > (isNegative ? 1 : 0); j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given negative or positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    const bool hasNegativeDecimals = decimals < 0;

    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34, -0.34 (the zero, and possibly also a negative sign, must be removed next)
    return humanizeInteger(integerValue) + decimalsAsString.substr(hasNegativeDecimals ? 2 : 1, precision + 1);
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

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Formats a given int by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeInteger(const unsigned long int integerValue, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedInteger(integerValue) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(const long double doubleValue, const int precision, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedDouble(doubleValue, precision) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Rounds up a given double number, with a given amount of decimal places
double roundUp(const double value, const int decimalPlaces) {
    const double multiplier = pow(10.0, decimalPlaces);
    return ceil(value * multiplier) / multiplier;
}

// Calculates the Recursive Sum of a given int number. Example: recursiveSum(5) == 5 + 4 + 3 + 2 + 1 = 15
int recursiveSum(const unsigned long long int number) {
    if (number != 0)
        return number + recursiveSum(number - 1);
    return 0;
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive = "th";

    switch (number) {
        case 11:
        case 12:
        case 13:
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
            }
    }

    return to_string(number) + additive;
}

// Determines is a given int number is prime or not
bool isPrime(const unsigned long long int value) {
    if (value <= 1)
        return false;
    for (unsigned long long int i = 2; i <= value / 2; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}

// Calculates the sum of all the elements inside an array of integers
int simpleSumOfIntegersInArray(const int integersArray[], const int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += integersArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of integers
int neatSumOfIntegersInArray(const int integersArray[], const int length) {
    return accumulate(integersArray, integersArray + length, 0);
}

// Calculates the sum of all the elements inside an array of integers
template<int N>
int sumOfIntegersWithRangeOverReference(int (&integersArray)[N]) {
    int sum = 0;
    for (auto number: integersArray) {
        sum += number;
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of doubles
double simpleSumOfDoublesInArray(const double doublesArray[], const int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += doublesArray[i];
    }
    return sum;
}

// Calculates the sum of all the elements inside an array of doubles
double neatSumOfDoublesInArray(const double doublesArray[], const int length) {
    return accumulate(doublesArray, doublesArray + length, 0.0);
}

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&doublesArray)[N]) {
    double sum = 0.0;
    for (auto number: doublesArray) {
        sum += number;
    }
    return sum;
}

// Calculates the sum of all the elements inside a two-dimensional array of doubles
template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    double sum = 0.0;

    for (auto &row: twoDimensionsDoublesArray) {
        for (auto &number: row) {
            sum += number;
        }
    }

    return sum;
}

// Calculates the average among all the numbers inside an array of integers
double simpleAverageAmongIntegersInArray(const int array[], const int length) {
    return simpleSumOfIntegersInArray(array, length) / static_cast<double>(length);
}

// Calculates the average among all the numbers inside an array of integers
double neatAverageAmongIntegersInArray(const int array[], const int length) {
    return neatSumOfIntegersInArray(array, length) / static_cast<double>(length);
}

// Calculates the average among all the numbers inside an array of integers
template<int N>
int templateAverageAmongIntegersInArray(int (&integersArray)[N]) {
    const int length = sizeof(integersArray) / sizeof(integersArray[0]);
    return sumOfIntegersWithRangeOverReference(integersArray) / length;
}

// Calculates the average among all the numbers inside an array of doubles
double simpleAverageAmongDoublesInArray(const double array[], const int length) {
    return simpleSumOfDoublesInArray(array, length) / length;
}

// Calculates the average among all the numbers inside an array of doubles
double neatAverageAmongDoublesInArray(const double array[], const int length) {
    return neatSumOfDoublesInArray(array, length) / length;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N>
double templateAverageAmongDoublesInArray(double (&doublesArray)[N]) {
    const int length = sizeof(doublesArray) / sizeof(doublesArray[0]);
    return sumOfDoublesWithRangeOverReference(doublesArray) / length;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&doublesTwoDimensionalArray)[N][M]) {
    const int rows = sizeof(doublesTwoDimensionalArray) / sizeof(doublesTwoDimensionalArray[0]);
    const int columns = sizeof(doublesTwoDimensionalArray[0]) / sizeof(doublesTwoDimensionalArray[0][0]);

    return templateSumOfDoublesInTwoDimensionsArray(doublesTwoDimensionalArray) / (rows * columns);
}

// Determines the highest number among an array of integers
int simpleHighestIntegerInArray(const int integersArray[], const int length) {
    int highestInteger = integersArray[0];
    if (length == 1) return highestInteger;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] > highestInteger)
            highestInteger = integersArray[i];
    }

    return highestInteger;
}

// Determines the lower number among an array of integers
int simpleLowerIntegerInArray(const int integersArray[], const int length) {
    int lower = integersArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (integersArray[i] < lower)
            lower = integersArray[i];
    }

    return lower;
}

// Determines the lower number among an array of doubles
double simpleLowerDoubleInArray(const double doublesArray[], const int length) {
    double lower = doublesArray[0];
    if (length == 1) return lower;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] < lower)
            lower = doublesArray[i];
    }

    return lower;
}

// Determines the higher number among an array of doubles
double simpleHigherDoubleInArray(const double doublesArray[], const int length) {
    double higher = doublesArray[0];
    if (length == 1) return higher;

    for (int i = 1; i < length; i++) {
        if (doublesArray[i] > higher)
            higher = doublesArray[i];
    }

    return higher;
}

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double lower = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number < lower)
                lower = number;
        }
    }

    return lower;
}

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double higher = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number > higher)
                higher = number;
        }
    }

    return higher;
}

// Determines if the given value is lower than the also given minimum value
bool isInvalid(const long double value, const double minValue) {
    return value < minValue;
}

// Prints on the terminal a text if the given value is lower than the also given minimum value
void scoldUserIfInvalidInput(const long double value, const double minValue) {
    if (isInvalid(value, minValue))
        cout << "You must type a number greater or equal than " << minValue << ". Try again!" << endl;
}

// Function to validate the DateTime(YYYY-MM-DD HH:MM:SS)
bool validDateTime(const string &datetimeAsString) {
    if (datetimeAsString.empty()) return false;

    // RegExp to check a valid DateTime(YYYY-MM-DD HH:MM:SS).
    const regex pattern("^([0-9]{4})-(01|02|03|04|05|06|07|08|09|10|11|12)-([0-2][0-9]|30|31)"
        "\\s([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])"
        "$");

    return regex_match(datetimeAsString, pattern);
}

// Function to extract all the components of a DateTime(YYYY-MM-DD HH:MM:SS)
vector<string> getComponentsFromDateTime(const string &datetimeAsString) {
    vector<string> dataComponents;

    // RegExp to check a valid DateTime(YYYY-MM-DD HH:MM:SS).
    const regex pattern("^([0-9]{4})-(01|02|03|04|05|06|07|08|09|10|11|12)-([0-2][0-9]|30|31)"
        "\\s([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])"
        "$");
    std::smatch matches;

    if (std::regex_search(datetimeAsString.begin(), datetimeAsString.end(), matches, pattern)) {
        for (string match: matches) {
            dataComponents.push_back(match);
        }
    }

    return dataComponents;
}

// Function to extract the year from a DateTime(YYYY-MM-DD HH:MM:SS)
string getYearFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[1] : ""; // YYYY
}

// Function to extract the month from a DateTime(YYYY-MM-DD HH:MM:SS)
string getMonthFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[2] : ""; // MM
}

// Function to extract the day from a DateTime(YYYY-MM-DD HH:MM:SS)
string getDayFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[3] : ""; // DD
}

// Function to extract the hours from a DateTime(YYYY-MM-DD HH:MM:SS)
string getHoursFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[4] : ""; // HH
}

// Function to extract the minutes from a DateTime(YYYY-MM-DD HH:MM:SS)
string getMinutesFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[5] : ""; // MM
}

// Function to extract the seconds from a DateTime(YYYY-MM-DD HH:MM:SS)
string getSecondsFromDateTime(const string &datetimeAsString) {
    vector<string> dateTimeComponents = getComponentsFromDateTime(datetimeAsString);
    return dateTimeComponents.size() > 1 ? dateTimeComponents[6] : ""; // SS
}

// Function to convert from a military Time (24 hours format) to civilian Time (12 hours format with meridian)
string convertTimeToCivilian(const int militaryHours, const int minutes) {
    string meridian;
    int civilianHours;

    // Handle midnight and noon
    if (militaryHours == 0) {
        civilianHours = 12;
        meridian = "AM";
    } else if (militaryHours == 12) {
        civilianHours = 12;
        meridian = "PM";
    } else if (militaryHours < 12) {
        civilianHours = militaryHours;
        meridian = "AM";
    } else {
        civilianHours = militaryHours - 12;
        meridian = "PM";
    }

    // cout << civilianHours << ":" << (minutes < 10 ? "0" : "") << minutes << meridian << endl;
    return to_string(civilianHours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes) + " " + meridian;
}


// CUSTOM FUNCTIONS


template<int N>
void loadRainfalls(const vector<string> &months, double (&rainfalls)[N]) {
    const int arraySize = sizeof(rainfalls) / sizeof(rainfalls[0]);
    for (int i = 0; i < arraySize; i++) {
        rainfalls[i] = getDouble("Enter rainfall for " + months[i], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
    }
}

template<int N>
void loadRainfallsPlus(const vector<string> &months, double (&rainfalls)[N]) {
    int count {0};
    for (double &rainfall: rainfalls) {
        rainfall = getDouble("Enter rainfall for " + months[count], 0, INT_MAX, false, "invalid data (negative rainfall) -- retry");
        count++;
    }
}

// template<size_t a, size_t b>
template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &weekDays, double (&monkeysFood)[N][M]) {
    const int rows = sizeof(monkeysFood) / sizeof(monkeysFood[0]);
    const int columns = sizeof(monkeysFood[0]) / sizeof(monkeysFood[0][0]);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            monkeysFood[row][col] = getDouble("Please type how many pounds of food the " + ordinalFromNumber(row + 1) + " monkey will eat on " + weekDays[col], 0, INT_MAX);
        }
    }
}

template<int N, int M>
void loadMonkeysFoodArraySlim(const vector<string> &weekDays, double (&monkeysFood)[N][M]) {
    int rowIndex = 0;

    for (auto &row: monkeysFood) {
        int cellIndex = 0;

        for (auto &cell: row) {
            cell = getDouble("Please type how many pounds of food the " + ordinalFromNumber(rowIndex + 1) + " monkey will eat on " + weekDays[cellIndex], 0, INT_MAX);
            cellIndex++;
        }
        rowIndex++;
    }
}

string getLeastRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleLowerDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string leastRainfallMonth = months[targetIndex];
    return leastRainfallMonth;
}

string getMostRainfallMonth(const vector<string> &months, double rainfalls[], const int arraySize) {
    const double *targetPointer = find(&rainfalls[0], rainfalls + arraySize, simpleHigherDoubleInArray(rainfalls, arraySize));
    const int targetIndex = targetPointer - rainfalls;
    string mostRainfallMonth = months[targetIndex];
    return mostRainfallMonth;
}

void displayResults(const double average, const double lowerAmount, const double higherAmount) {
    cout << endl;
    cout << "The average amount of food eaten per day by the whole family of monkeys is " << humanizeDouble(average) << " lbs." << endl;
    cout << "The least amount of food eaten during the week by any one monkey is " << humanizeDouble(lowerAmount) << " lbs." << endl;
    cout << "The greatest amount of food eaten during the week by any one monkey is " << humanizeDouble(higherAmount) << " lbs." << endl;
}
