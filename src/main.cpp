//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        09/21/2024 
// Class:       CS200
// Assignment:  Base Converter
// Purpose:     Conversion between Binary, Decimal, and Hexidecimal
// Hours:       0.25 lol
//******************************************************************************

#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATIONS
void printTitle(const string& myTitle);
string getNumber(const string& prompt);
char getBase (const string& strNumber);
int hexCharToInt (char hexDigit);


int main () {
  string const sTitle = "HEX-DECIMAL-BINARY CONVERTER";
  string sPrompt = "\nEnter your string to convert (q to quit): ";
 
  printTitle(sTitle);
  getNumber(sPrompt);
  while (getNumber(sPrompt) != "q"){



    getNumber(sPrompt);
  }

  return EXIT_SUCCESS;
}
/*

FUNCTION printTitle

*/
void printTitle(const string& myTitle){
  
  cout << "**************************************\n";
  cout << "*****" + myTitle + "*****\n";
  cout << "**************************************\n";
}
/*

FUNCTION getNumber

*/
string getNumber(const string& prompt){
  string userInput;
  cout << prompt;
  cin >> userInput;

  return userInput; 
}
/*

getBase

*/
char getBase (const string& strNumber){ 
  char letterVar;
  
  if (strNumber[1] == 'x'){
    letterVar = 'H';
  }
  else if (strNumber[1] == 'b'){
    letterVar = 'B';
  }
  else {
    letterVar = 'D'; 
  }

  return letterVar;
}
/*

FUNCTION hexChartoInt

*/
int hexCharToInt (char hexDigit){
  

}