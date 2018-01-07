#include <iostream>

using namespace std;

#define SK_AUTOINCREMENTABLE( CLSNAME, MNAME ) class CLSNAME { protected: static size_t ai_next( ) noexcept { static size_t id = 0; return ++id; } public: virtual size_t MNAME( ) const noexcept = 0; }

#define SK_MESSAGE( MNAME ) public: size_t MNAME( ) const noexcept override { return classKey( ); } private: static inline size_t classKey( ) noexcept { static size_t mk = Message::ai_next( ); return mk; }

SK_AUTOINCREMENTABLE( Message, messageKey );

class Message1: public Message {
  SK_MESSAGE( messageId )
};

class Message2: public Message {
  SK_MESSAGE( messageId )
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
