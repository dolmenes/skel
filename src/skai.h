#ifndef SK_AI_H
#define SK_AI_H

#define SK_AUTOINCREMENTABLE( CLSNAME, MNAME ) class CLSNAME { protected: static size_t ai_next( ) noexcept { static size_t id = 0; return ++id; } public: virtual size_t MNAME( ) const noexcept = 0; }

#endif
