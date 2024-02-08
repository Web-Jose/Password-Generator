# 🔒 Password Generator
This is a simple C++ program that generates random passwords based on user input. The user can specify the length of the password and choose whether to include letters (lowercase and/or uppercase), numbers, and symbols.

## 📚 Libraries
This program uses the following libraries:

- `iostream`: for input/output operations
- `string`: for creating the password as a string
- `limits`: for error checking and preventing invalid user input
- `cstdlib`: for generating random numbers
- `cstdio`: for standard input/output operations
  
## 🛠 Functions
The program includes the following functions:

### `PassLength()`
This function asks the user to input the desired length of the password and returns an integer value.

### `LettersOp()`
This function asks the user whether they want to include letters in the password and returns an integer value (1 for yes, 2 for no).

### `UpperOp()`
This function asks the user whether they want to include uppercase letters in the password and returns an integer value (1 for yes, 2 for no).

### `NumbersOp()`
This function asks the user whether they want to include numbers in the password and returns an integer value (1 for yes, 2 for no).

### `SymbolsOp()`
This function asks the user whether they want to include symbols in the password and returns an integer value (1 for yes, 2 for no).

### `RandLowLet()`
This function generates a random lowercase letter and returns a character.

### `RandUppLet()`
This function generates a random uppercase letter and returns a character.

### `RandNum()`
This function generates a random number and returns a character.

### `RandSymb()`
This function generates a random symbol and returns a character.

### `PassAssemble(int PL, int LC, int UC, int NC, int SC)`
This function assembles the password based on the user's specifications. It takes the password length (PL) and the user's choices for including lowercase letters (LC), uppercase letters (UC), numbers (NC), and symbols (SC) as integer arguments. It returns the final password as a string.

## 🚀 How to use
To use this program, simply run it in a C++ compiler. Follow the prompts to specify the length and character types you want in your password. Once all of the input is provided, the program will generate a random password and display it on the screen.

## 🙏 Credits
This project was created by Jose Cortes as a personal project.

## 📄 License
This code is licensed under the MIT License. See the LICENSE file for more information.
