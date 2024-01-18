#include "CipherTool.h"


CipherTool::CipherTool(string filename){
  m_filename = filename;
}

CipherTool::~CipherTool(){
 for (unsigned int i = 0; i < m_ciphers.size(); i++){
        delete m_ciphers.at(i);
    }
}


void CipherTool::LoadFile(){
// Name: LoadFile
// Desc - Opens file and reads in each Cipher. Each Cipher dynamically allocated
// and put into m_ciphers (c is Caesar, r is RailFence, and o is Ong)
// Preconditions - Input file passed and populated with Ciphers
// Postconditions - m_ciphers populated with Ciphers

  // string initialization
 
    string cypher, cytype, cybool, cymessage, cyshift;
    fstream Cypher(m_filename);
    int t;
    while(getline(Cypher,cypher,DELIMITER)){
        cytype = cypher;
        getline(Cypher,cypher,DELIMITER);
        cybool = cypher;
        getline(Cypher,cypher,DELIMITER);
        cymessage = cypher;
        if(cytype == "c")
        {
            getline(Cypher,cypher);
            cyshift = cypher;
            t = 1;
        }
        else if(cytype == "r")
        {
            getline(Cypher,cypher);
            cyshift = cypher;
            t = 2;
        }
        else if(cytype == "o")
        {
            t = 3;
        }

      if(t == 1)
      {            
            Caesar *caesar = new Caesar(cymessage, StringToBoolean(cybool), stoi(cyshift));
            m_ciphers.push_back(caesar);
        }
      if(t == 2){
            RailFence *railfence = new RailFence(cymessage, StringToBoolean(cybool), stoi(cyshift));
            m_ciphers.push_back(railfence);
        }
      if(t == 3){      
      Ong *ong = new Ong(cymessage, StringToBoolean(cybool));
            m_ciphers.push_back(ong);
            }
          }
  Cypher.close();
    }

bool CipherTool::StringToBoolean(string input){
  if (input == "0"){
    return false;
  }
  return true;
}

void CipherTool::DisplayCiphers(){
 // LoadFile();
  for (int i = 0; i < (int)m_ciphers.size(); i++){
      
    cout << i+1 << ". " << m_ciphers[i]->GetMessage() << " ("<< m_ciphers[i]->ToString()<< ')' << endl;
  
    }
}


void CipherTool::EncryptDecrypt(bool val){
  
  int count = 0;
    // if cipher should be decrypted
    if (val == true){
        //checks which ciphers in the vector of ciphers are not decrypted, and decrypts those
        for (unsigned int i = 0; i < m_ciphers.size(); i++){
            if (m_ciphers[i]->GetIsEncrypted() == val){
                m_ciphers[i]->Decrypt();
                m_ciphers[i]->ToggleEncrypted();
                count++;
            }
          }
        cout << count << " ciphers Decrypted." << endl;
    }else{
        // checks which ciphers in the vector of ciphers are not encrypted, encrypts those
        for (unsigned int i = 0; i < m_ciphers.size(); i++){
          //cout <<"m_ciphers: " << m_ciphers[i]->GetMessage() << endl;
            if (m_ciphers[i]->GetIsEncrypted() == val){
                 m_ciphers[i]->Encrypt();
                 m_ciphers[i]->ToggleEncrypted();
                 count++;
             }
          //cout << i << endl;
        }
  //vector.size() = 
        cout << count << " ciphers Encrypted." << endl;
    }
      }
    
void CipherTool::Export(){
    ofstream outputStream;
    string userFile;
    // checks if m_ciphers has been populated
    if (m_ciphers.size() == 0){
        cout << "There are not any Ciphers." << endl;
    }else{
        // takes in user input of file name
        cout << "What would you like to call the export file?" << endl;
        cin >> userFile;
        outputStream.open(userFile);
        // if the file is open, ciphers will be loaded
        if (outputStream.is_open()){
            for (unsigned int i = 0; i < m_ciphers.size(); i++){
              outputStream << m_ciphers.at(i)->FormatOutput();
        }
        outputStream.close();
        cout << m_ciphers.size() << " files exported." << endl;
      }
    }
  }
 
int CipherTool::Menu(){
  int choice;
  cout << "What would you like to do ?" << endl;
  cout << "1. Display All Ciphers" << endl;
  cout << "2. Encrypt All Ciphers" << endl;
  cout << "3. Decrypt All Ciphers"<< endl;
  cout << "4. Export All Ciphers" << endl;
  cout << "5. Quit" << endl;
  cin >> choice;
  while (choice != 5){
  while ( choice < 1 || choice > 5){
  cout << "Invalid input, please try again: " << endl;
  cout << endl;
  cout << "What would you like to do ?" << endl;
  cout << "1. Display All Ciphers" << endl;
  cout << "2. Encrypt All Ciphers" << endl;
  cout << "3. Decrypt All Ciphers"<< endl;
  cout << "4. Export All Ciphers" << endl;
  cout << "5. Quit" << endl;
  cin >> choice;
  }
  if(choice == 1){
    DisplayCiphers();
  }else if (choice == 2){
    //cout << "success." << endl;
    EncryptDecrypt(false);
    
  }else if(choice == 3){
    EncryptDecrypt(true);
  } else if(choice == 4){
    Export();
  }
  cout << endl;
  cout << "What would you like to do ?" << endl;
  cout << "1. Display All Ciphers" << endl;
  cout << "2. Encrypt All Ciphers" << endl;
  cout << "3. Decrypt All Ciphers"<< endl;
  cout << "4. Export All Ciphers" << endl;
  cout << "5. Quit" << endl;
  cin >> choice;  
  }
  cout << "Thanks for using UMBC Encryption." << endl;
  return 0;
}
  
  void CipherTool::Start(){
    LoadFile();
    Menu();
  }

