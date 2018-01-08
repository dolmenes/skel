#ifndef SK_MESSAGE_HPP
#define SK_MESSAGE_HPP

#include "skai.h"

namespace sk {

#define SK_MESSAGE public: size_t messageKey( ) const noexcept override { return classKey( ); } private: static inline size_t classKey( ) noexcept { static size_t mk = Message::ai_next( ); return mk; }

SK_AUTOINCREMENTABLE( Message, messageKey );

}

#endif
