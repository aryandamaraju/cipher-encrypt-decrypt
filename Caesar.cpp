#include "Caesar.h"

Caesar::Caesar(){
  m_shift = 3;
}


Caesar::Caesar(string message, bool isEncrypted, int shift):Cipher(message, isEncrypted){
  m_shift = shift;
}

Caesar::~Caesar(){

}

void Caesar::Encrypt(){
  string encryptedMessage = "";
  string message = GetMessage();

  
  if(m_shift >= 27){
    m_shift = m_shift % 26;
  }
  for (int i = 0; i < (int) message.size(); ++i){ 
    if(((int(message[i]) >= 97 && int(message[i]) <= 122))||((int(message[i]) >= 65 && int(message[i]) <= 90))){
    if (isupper(message[i]))
          encryptedMessage += char(int(message[i]+m_shift-65)%26 +65);
 
    // Encrypt Lowercase letters
    else
        encryptedMessage += char(int(message[i]+m_shift-97)%26 +97);
    
      }else{
     encryptedMessage = encryptedMessage + message[i];
    }
  }
  SetMessage(encryptedMessage);
}


void Caesar::Decrypt(){
  string encryptedMessage = "";
  string message = GetMessage();

  
  if(m_shift >= 27){
    m_shift = m_shift % 26;
  }
  for (int i = 0; i < (int) message.size(); ++i){ 
    if(((int(message[i]) >= 97 && int(message[i]) <= 122))||((int(message[i]) >= 65 && int(message[i]) <= 90))){
    if (isupper(message[i]))
          encryptedMessage += char(int(message[i]+(26-m_shift)-65)%26 +65);
 
    // Encrypt Lowercase letters
    else
        encryptedMessage += char(int(message[i]+(26-m_shift)-97)%26 +97);
    
      }else{
     encryptedMessage = encryptedMessage + message[i];
    }
  }
  SetMessage(encryptedMessage);
}


string Caesar::ToString(){
  return "Caesar";
}


string Caesar::FormatOutput(){
  stringstream ss;
  ss << 'c' << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << DELIMITER << m_shift << endl;
  return ss.str();
  
}