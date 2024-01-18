#include "Ong.h"

Ong::Ong(){
  
}

Ong::Ong(string message, bool isEncrypted):Cipher(message, isEncrypted){
  
}

Ong::~Ong(){
  
}

bool Ong::IsVowel(char ch){
  char vowelArr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  char punctArray[] = {'.', '!', '?', ',', '"', '-', ':', ';', '(', ')', ' '};
  for(int i = 0; i < (int)(sizeof(vowelArr)/sizeof(vowelArr[0])); i++){
    if(ch == vowelArr[i] || ch == punctArray[i]){
        return true;
      }
  }
  return false;
}

void Ong::Encrypt(){
  string message = GetMessage();
    int messageLength = message.length();
    string newmessage;
    // iterates through the message, adds "ong-" if it is not a vowel or punctuation or space, else adds "ong-"
    for (int i = 0; i < messageLength; i++){
        char temp = message[i];
        bool flag = IsVowel(temp);
        // compares the flag
        if (flag == false && temp != ' '){
            newmessage.push_back(temp);
            newmessage.push_back('o');
            newmessage.push_back('n');
            newmessage.push_back('g');  // That bunkle = Tong-hong-a-tong 'ong'bong-u-nong-kong-long-e
        }
        if (flag == true || temp == ' '){
            newmessage.push_back(temp);
        }
        // checks to make sure the current character is not a space or backwards parenthesis and also if the character after
        // it is not a space
        if (message[i+1]!= ' ' && temp != ' ' && temp != ')'){
            newmessage.push_back('-');
        }
       // if (temp == ' '){
       //    i = i+1;
       //   temp = message[i];
       //  }      
    }
    // sets the new message as the message
    SetMessage(newmessage);
}




void Ong::Decrypt(){
  string message = GetMessage();
    int messageLength = message.length();
    string newmessage;
    // iterates through the message to check if it has "ong-", only pushes back vowels, punctuation, spaces, and consonants
    for (int i = 0; i < messageLength;){
        if (message[i+1] == 'o' && message[i+2] == 'n' && message[i+3] == 'g' && message[i+4] == '-'){
            newmessage.push_back(message[i]);
            i+=5;
        }else if (message[i] == '-'){
            // checks if character is a dash, skips it
            i++;
        }else if ((message[i+1] == 'o' && message[i+2] == 'n' && message[i+3] == 'g' && message[i+4] == ' ')){
            // checks if it is the last consonant of the word
            newmessage.push_back(message[i]);
            i+=4;
        }else{
            newmessage.push_back(message[i]);
            i++;
        }
      SetMessage(newmessage);
    }
    

}

string Ong::ToString(){
  return "Ong";
}


string Ong::FormatOutput(){
  stringstream ss;
  ss << 'o' << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << DELIMITER << endl;
  return ss.str();
}