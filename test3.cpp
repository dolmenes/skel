#include <iostream>

using namespace std;

template< int N > struct flag {
  friend constexpr int adl_flag( flag< N > );
};

template< int N > struct writer {
  friend constexpr int adl_flag( flag< N > ) {
    return N;
  }

  static constexpr int value = N;
};

template< int N, int = adl_flag( flag< N >{ } ) > int constexpr reader( int, flag< N > ) {
  return N;
}

template< int N > int constexpr reader( float, flag< N >, int R = reader( 0, flag< N - 1 >{ } ) ) {
  return R;
}

int constexpr reader( float, flag< 0 > ) {
  return 0;
}

template< int N = 1 > int constexpr next( int R = writer< reader( 0, flag< 32 >{ } ) + N >::value ) {
  return R;
}

class Message {
public:
  virtual int messageKey( ) const noexcept = 0;
};

class Message1: public Message {
  static constexpr int MessageKey = next( );
public:
  int messageKey( ) const noexcept override { return MessageKey; }
};

class Message2: public Message {
  static constexpr int MessageKey = next( );
public:
  int messageKey( ) const noexcept override { return MessageKey; }
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
