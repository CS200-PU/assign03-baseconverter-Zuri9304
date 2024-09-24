//******************************************************************************
// File name:   main.cpp
// Author:      Gabriel Zurita
// Date:        09/21/2024
// Class:       CS200
// Assignment:  Base Converter
// Purpose:     Conversion between Binary, Decimal, and Hexidecimal
// Hours:       0.25 lol
//******************************************************************************

#include <iostream>
#include <string>
#include <cmath>
#include<cstring>

using namespace std;

// FUNCTION DECLARATIONS
void printTitle(const string& myTitle);
string getNumber(const string& prompt);
char getBase (const string& strNumber);
int hexCharToInt (char hexDigit);
string binaryToDecimal (const string& strNumber);
string decimalToBinary(const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex(const string& strNumber);


int main () {
  string const sTitle = "HEX-DECIMAL-BINARY CONVERTER";
  string sPrompt = "\nEnter your string to convert (q to quit): ";
  string userInput;
  char baseType;
 
  printTitle(sTitle);
  
  userInput = getNumber(sPrompt);

  
  while (userInput != "q"){

    baseType = getBase(userInput);
    if (baseType == 'D') {
      cout << "The binary conversion is: " << decimalToBinary(userInput) 
      << endl;
      cout << "The hexadecimal conversion is: " << decimalToHex(userInput) 
      << endl;
    }
    if(baseType == 'B'){
      cout << "The decimal conversion is: " << binaryToDecimal(userInput) 
      << endl;
      cout << "THe hexadecimal conversion is: " << binaryToHex(userInput) 
      << endl;
    }
    if(baseType == 'H'){
      cout << "The decimal conversion is: " << hexToDecimal(userInput) << endl;
      cout << "The binary conversion is: " << hexToBinary(userInput) << endl;
    }
 

    userInput = getNumber(sPrompt);
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
int hexCharToInt(char hexDigit) {
  char digit;
  if (hexDigit >= '0' && hexDigit <= '9'){
    digit = hexDigit - '0';
  }
  else{
    digit = hexDigit - 'A' + 10;
  }
  
  return digit;
}
/*

FUNCTION binaryToDecimal

*/
string binaryToDecimal (const string& strNumber){
  int decimal = 0;
  int power = 0;

  for(int i = strNumber.length() - 1; i >= 0; i--){
    
    if(strNumber[i] == '1'){
      decimal += pow(2,power);
    }
    power++;
  }

  return to_string(decimal);

}
/*

FUNCTION decimalToBinary

*/
string decimalToBinary(const string& strNumber){
  int decimal = stoi(strNumber);

  string returnValue;

  while(decimal > 0) {
    returnValue = to_string(decimal % 2) + returnValue;

    decimal /= 2;
  }

  return returnValue; 
}
/*

FUNCTION decimalToHex

*/
string decimalToHex (const string& strNumber){
  int decimal = stoi(strNumber);
  int remainder;
  string returnValue;
  string signifier;
  string hexDigits = "0123456789ABCDEF";

  while (decimal > 0){
    remainder = decimal % 16;
    signifier = hexDigits[remainder] + signifier;
    decimal /= 16;
  }

  return "0x" + signifier; 

}

/*

FUNCTION hexToDecimal

*/
string hexToDecimal (const string& strNumber){
  string hex = strNumber.substr(2);
  int decimal = 0;
  int power = 1;
  if (strNumber.length() > 2 && strNumber.substr(0,2) == "0x"){
    hex = strNumber.substr(2);
  }
  else{
    hex = strNumber;
  }
  for (int i = hex.length() -1; i >= 0; i--){
    int digitValue = hexCharToInt(hex[i]);
    decimal += digitValue * power;
    power*= 16;
  }

  return to_string(decimal);
}
/*

FUNCTION hexToBinary

*/
string hexToBinary (const string& strNumber){
  string decimal = hexToDecimal(strNumber);

  return "0b" + decimalToBinary(decimal);
}
/*

FUNCTION binaryToHex

*/
string binaryToHex(const string& strNumber){
  string decimal = binaryToDecimal(strNumber);

  return decimalToHex(decimal);
}

