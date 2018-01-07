#include <iostream>

using namespace std;

class Message {
protected:
  static inline size_t msgid( ) {
    static size_t id = 0;
    return ++id;
  }
public:
  virtual size_t messageKey( ) const noexcept = 0;
};

class Message1: public Message {
  static inline size_t msgid( ) {
    static size_t id = Message::msgid( );
    return id;
  }
public:
  size_t messageKey( ) const noexcept override { return msgid( ); }
};

class Message2: public Message {
  static inline size_t msgid( ) {
    static size_t id = Message::msgid( );
    return id;
  }
public:
  size_t messageKey( ) const noexcept override { return msgid( ); }
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
