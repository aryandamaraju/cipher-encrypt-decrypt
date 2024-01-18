#include "Cipher.h"

Cipher::Cipher(){
  
}


Cipher::Cipher(string message, bool isEncrypted){
  m_message = message;
  m_isEncrypted = isEncrypted;
}


 Cipher::~Cipher(){
  
}


string Cipher::GetMessage(){
  return m_message;
}


bool Cipher::GetIsEncrypted(){
  return m_isEncrypted;  
}


void Cipher::SetMessage(string message){
  m_message = message;
}


void Cipher::ToggleEncrypted(){
  if(m_isEncrypted == true){
    m_isEncrypted = false;
  }else{
    m_isEncrypted = true;
  }
}

ostream &operator<<( ostream &output, Cipher &C){
    output << C.m_message << ", " << C.m_isEncrypted;
    return output;
}