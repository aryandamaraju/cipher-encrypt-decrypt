//Title: Vignere.h
//Author: Aryan Damaraju
//Date: 4/1/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#ifndef VIGENERE_H
#define VIGENERE_H
#include "Cipher.h"
#include <istream>
#include <string>
using namespace std;

class Vigenere: public Cipher{
 public:
  // Name: Vignere (Default Constructor)
  // Desc: Constructor to build an empty Vignere Cipher (Defaults to 3 rails)
  // Preconditions - None
  // Postconditions - Creates a Vignere cipher
  Vigenere();
  // Name: Vignere (Overloaded Constructor)
  // Desc: Constructor to build a populated Vignere Cipher (Defaults to 3 rails)
  // Preconditions - Pass it the message, isEncrypted, and number of rails (any integer)
  // Postconditions - Creates a Vignere cipher to be encrypted
  Vigenere(string, bool, string);
  // Name: Vignere (Destructor)
  // Desc: Destructor - Anything specific part of Vignere to delete?
  // Preconditions - ~Vignere exists
  // Postconditions - Vignere destroyed
  ~Vigenere();
  // Name: Encrypt
  // Desc: Letters are placed on a fence rail based on the number of rails
  //       Letters are read from one rail at a time into a single string
  // Preconditions - Message exists
  // Postconditions - A single encrypted string is stored
  void Encrypt();
  // Name: Decrypt
  // Desc: Single encrypted string is pushed back on the rails and reversed
  // Preconditions - Message exists
  // Postconditions - The decrypted string is stored
  void Decrypt();
  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Vignere in this case)
  string ToString();
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - r, delimiter, isencrypted, delimiter,
  //                  message, delimiter, m_rails are returned for output
  string FormatOutput();
private:
  string m_key; //Vignere key.
};


#endif
