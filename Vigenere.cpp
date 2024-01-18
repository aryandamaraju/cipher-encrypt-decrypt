#include "Vigenere.h"

// Name: Vignere (Default Constructor)
  // Desc: Constructor to build an empty Vignere Cipher (Defaults to 3 rails)
  // Preconditions - None
  // Postconditions - Creates a Vignere cipher
  Vigenere::Vigenere(){
    m_key = 3;
  }
  // Name: Vignere (Overloaded Constructor)
  // Desc: Constructor to build a populated Vignere Cipher (Defaults to 3 rails)
  // Preconditions - Pass it the message, isEncrypted, and number of rails (any integer)
  // Postconditions - Creates a Vignere cipher to be encrypted
  Vigenere::Vigenere(string message, bool val, string key):Cipher(message, val){
    m_key = key;
  }
  // Name: Vignere (Destructor)
  // Desc: Destructor - Anything specific part of Vignere to delete?
  // Preconditions - ~Vignere exists
  // Postconditions - Vignere destroyed
  Vigenere::~Vigenere(){}
  // Name: Encrypt
  // Desc: Letters are placed on a fence rail based on the number of rails
  //       Letters are read from one rail at a time into a single string
  // Preconditions - Message exists
  // Postconditions - A single encrypted string is stored
  void Vigenere::Encrypt(){
    string mess = GetMessage();
    string encryptedMessage = "";
    string cipher_text;
 
    for (int i = 0; i < mess.size(); i++)
    {
        // converting in range 0-25
        char x = (mess[i] + m_key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        encryptedMessage += x;
    }
    SetMessage(encryptedMessage);
  }
  // Name: Decrypt
  // Desc: Single encrypted string is pushed back on the rails and reversed
  // Preconditions - Message exists
  // Postconditions - The decrypted string is stored
  void Vigenere::Decrypt(){
   string mess = GetMessage();
    string encryptedMessage = "";
 
    for (int i = 0; i < mess.size(); i++)
    {
        // converting in range 0-25
        char x = (mess[i] - m_key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        encryptedMessage += x;
    }
    SetMessage(encryptedMessage);
  }
  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Vignere in this case)
  string Vigenere::ToString(){
    return "Vigenere";
  }
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - r, delimiter, isencrypted, delimiter,
  //                  message, delimiter, m_rails are returned for output
  string Vigenere::FormatOutput(){
    stringstream ss;
  ss << 'v' << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << DELIMITER << m_key << endl;
  return ss.str();
  }