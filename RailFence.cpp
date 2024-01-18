#include "RailFence.h"

RailFence::RailFence() {}

RailFence::RailFence(string message, bool isEncrypted, int rails)
    : Cipher(message, isEncrypted) {
  m_rails = rails;
}

RailFence::~RailFence() {}

void RailFence::Encrypt() {
  string message = GetMessage();
  int messageLength = message.length();
  string newmessage;
  // creates an array using m_rails and length of message to encrypt the cipher
  char railFence[m_rails][messageLength];
  // iterates through the array and adds a newline on each index
  for (int i = 0; i < m_rails; i++) {
    for (int j = 0; j < messageLength; j++) {
      railFence[i][j] = '\n';
    }
  }
  // checks direction of cipher, row and column
  int upOrDown = -1;
  int column = 0;
  int row = 0;
  // iterates through the array and populates it with a character from message
  // while it changes direction
  for (int i = 0; i < messageLength; i++) {
    railFence[row][column] = message[i];
    // if it is on the first row, the direction will go down if it is the last
    // row the direction will go up
    if (row == 0 || row == m_rails - 1) {
      upOrDown *= -1;
    }
    column++;
    row += upOrDown;
  }
  // iterates through the array and if the space at the index is not a new line,
  // it is added to new message
  for (int i = 0; i < m_rails; i++) {
    for (int j = 0; j < messageLength; j++) {
      if (railFence[i][j] != '\n') {
        newmessage.push_back(railFence[i][j]);
      }
    }
  }
  // sets the new message as the message
  SetMessage(newmessage);
}

void RailFence::Decrypt() {
  string message = GetMessage();
  int messageLength = message.length();
  string newmessage;
  // counter to build the array
  int counter = 0;
  // array built with m_rails and length of message
  char railFence[m_rails][messageLength];
  // populates the array with new lines
  for (int i = 0; i < m_rails; i++) {
    for (int j = 0; j < messageLength; j++) {
      railFence[i][j] = '\n';
    }
  }
  // checks direction of cipher, row and column
  int upOrDown = -1;
  int column = 0;
  int row = 0;
  // iterates through the array and fills some new line spaces with a character
  // which will be tracked changes direction
  for (int i = 0; i < messageLength; i++) {
    // if it is on the first row, the direction will go down if it is the last
    // row the direction will go up
    if (row == 0 || row == m_rails - 1) {
      upOrDown *= -1;
    }
    railFence[row][column] = '.';
    column++;
    row += upOrDown;
  }
  // column, row, and direction value are reset
  column = 0;
  row = 0;
  upOrDown = -1;
  // iterates through the array and replaces corresponding spaces with character
  // at message index if conditions are met
  for (int i = 0; i < m_rails; i++) {
    for (int j = 0; j < messageLength; j++) {
      if (railFence[i][j] == '.') {
        railFence[i][j] = message[counter];
        counter++;
      }
    }
  }
  // new message is created based on the populated array when counter was being
  // used
  for (int i = 0; i < messageLength; i++) {
    newmessage.push_back(railFence[row][column]);
    column++;
    if (row == 0 || row == m_rails - 1) {
      upOrDown *= -1;
    }
    row += upOrDown;
  }
  // sets message as new message
  SetMessage(newmessage);
}

string RailFence::ToString() { return "RailFence"; }

string RailFence::FormatOutput() {
  stringstream ss;
  ss << 'r' << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage()
     << DELIMITER << m_rails << endl;
  return ss.str();
}