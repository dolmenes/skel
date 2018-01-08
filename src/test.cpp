#include <iostream>

#include "skmessage.hpp"

using namespace std;

class Message1: public Message {
  SK_MESSAGE
};

class Message2: public Message {
  SK_MESSAGE
};

inline ostream &operator<<( ostream &os, const Message &msg ) {
  int id = msg.messageKey( );

  return os << "MessageId( ): " << id << "\n";
}

int main( ) {
  Message1 msg1;
  Message2 msg2;
  Message2 msg3;
  Message1 msg4;

  cout << msg1;
  cout << msg2;
  cout << msg3;
  cout << msg4;

  return 0;
}
