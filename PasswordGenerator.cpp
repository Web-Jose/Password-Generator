// Libraries
#include <iostream> // cout and other standard stuff
#include <string> // To make the passwords generated strings
#include <limits> // This is so users won't put letters instead of #
#include <cstdlib> // Rand functions
#include <cstdio>

using namespace std; // This way I don't have to write std

// Used to ask and determine the length of the password
int PassLength(){
    // Variables
    int PL = 0;
    // Question of password length
    cout << "What is the length of the desired password?" << endl;
    cout << "Enter response: ";
    // User input
    cin >> PL;
    cout << endl;
    // Fail checker
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cin >> PL;
        cout << endl;
    }
    // Return length value
    return PL;
}
// Used to ask and determine if we are using letters
int LettersOp(){
    // Variables
    int LO = 5;
    // Question of including letters
    cout << "Would you like to include letters?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "Enter response: ";
    cin >> LO;
    cout << endl;
    // Fail checker
    while(cin.fail() || LO < 1 || LO > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cin >> LO;
        cout << endl;
    }
    // Return choice
    return LO;
}
// Used to ask and determine if to include uppercase letters
int UpperOp(){
    // Variables
    int UO = 5;
    // Question of including upper case letters
    cout << "Would you like to include upper case letters?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "Enter response: ";
    cin >> UO;
    cout << endl;
    // Fail checker
    while(cin.fail() || UO < 1 || UO > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cin >> UO;
        cout << endl;
    }
    // Return choice
    return UO;
}
// Used to ask and determine if we are using #s
int NumbersOp(){
    // Variables
    int NO = 5;
    // Question of including numbers
    cout << "Would you like to include numbers?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "Enter response: ";
    cin >> NO;
    cout << endl;
    // Fail checker
    while(cin.fail() || NO < 1 || NO > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cin >> NO;
        cout << endl;
    }
    // Return choice
    return NO;
}
// Used to ask and determine if we are using symbols
int SymbolsOp(){
    // Variables
    int SO = 5;
    // Question of including Symbols
    cout << "Would you like to include Symbols?" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "Enter response: ";
    cin >> SO;
    cout << endl;
    // Fail checker
    while(cin.fail() || SO < 1 || SO > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        cin >> SO;
        cout << endl;
    }
    // Return choice
    return SO;
}

// Generates and outputs a random lower case letter
char RandLowLet(){
    // Variables and assignments
    char RandLowChar = 'a' + rand() % 26;
    return RandLowChar;
}
// Generates and outputs a random upper case letter
char RandUppLet(){
    // Variables and assignments
    char RandUppChar = 'A' + rand() % 26;
    return RandUppChar;
}
// Generates and outputs a random number
char RandNum(){
    // Variables and assignments
    char RandNumber = '0' + rand() % 10;
    return RandNumber;
}
// Generates and outputs a random symbol
char RandSymb(){
    // Variables and assignments
    char symbols[] = "~`!@#%^&*()_-+={[}]|\\:\";'<,>.?/";
    int randomIndex = rand() % (sizeof(symbols) - 1);
    char randomSymbol = symbols[randomIndex];
    return randomSymbol;
    }

string PassAssemble(int PL, int LC, int UC, int NC, int SC){
    //Array for determining what to use
    int PassSpecs[] = {LC, UC, NC, SC};
    if (PassSpecs[0] == 2 && PassSpecs[1] == 2 && PassSpecs[2] == 2 && PassSpecs[3] == 2){
        cout << "No password specifcations made..." << endl;
        cout << "Goodbye." << endl;
        abort();
    }
    //Generating a password based on the specifications
    srand(time(0));
    string password;
    int randIndex;
    int i;
    for (i = 0; i < PL; i++){

        randIndex = rand() % 4;
        while ((PassSpecs[randIndex]) != 1){
            randIndex = rand() % 4;
        }
        if (randIndex == 0){
            password.push_back(RandLowLet());
        }
        else if (randIndex == 1){
            password.push_back(RandUppLet());
        }
        else if (randIndex == 2){
            password.push_back(RandNum());
        }
        else if (randIndex == 3){
            password.push_back(RandSymb());
        }
        else {
            cout << "ERROR @" << randIndex << endl;
        }
    }
    return password;
}

int main(){
    // Program start
    cout << "Welcome to the random password generator..." << endl;
    cout << endl << "First lets specify length and complexity" << endl;
    // Variables and assignments
    int PasswordLength = PassLength();
    int LetterChoice = LettersOp();
    int UpperChoice = 2;
    if (LetterChoice == 1){
        UpperChoice = UpperOp();
    }
    int NumberChoice = NumbersOp();
    int SymbolChoice = SymbolsOp();
    string password = PassAssemble(PasswordLength, LetterChoice, UpperChoice, NumberChoice, SymbolChoice);

    cout << "Your password is " << password << endl;

    char c;
    cout << "Enter e to exit." << endl;
    do{
        c = getchar();
    } while (c != 'e');

    cout << "Exiting now" << endl;

    return 0;
}