#ifndef __main_h_
#define __main_h_

#include <functional>
#include <math.h>

// Macro definitions for Question 1 + 3
#define INLINE_RET(BODY) \
   static inline double eval(double d){ \
      return BODY \
   };

#define INLINE_DERIV(BODY) \
   static inline double derivative(double d){ \
      return BODY \
   };

#define LR_TEMP template <class L, class R> struct 



// Question 1 + 3
template <class EXP> struct PAREN { INLINE_RET( EXP::eval(d); )};
LR_TEMP EXPONENT { 
   INLINE_RET( pow(L::eval(d), R::eval(d)); )
   INLINE_DERIV ( R::eval(d) * pow(L::eval(d), R::eval(d) - 1) * L::derivative(d); )
};

LR_TEMP MULTIPLY { 
   INLINE_RET( L::eval(d) * R::eval(d); )
   INLINE_DERIV( (L::eval(d) * R::derivative(d)) + (L::derivative(d) * R::eval(d) ); )
};
LR_TEMP DIVIDE   { 
   INLINE_RET( L::eval(d) / R::eval(d); )
   INLINE_DERIV( (R::eval(d) + L::derivative(d) - L::eval(d) * R::derivative(d)) / pow(R::eval(d),2); )
};

LR_TEMP ADDITION { 
   INLINE_RET( L::eval(d) + R::eval(d); )
   INLINE_DERIV( L::derivative(d) + R::derivative(d); )
};

LR_TEMP SUBTRACT { 
   INLINE_RET( L::eval(d) - R::eval(d); )
   INLINE_DERIV( L::derivative(d) - R::derivative(d); )
};

struct VAR  { 
   INLINE_RET( d; )
   INLINE_DERIV( 1; )
};

template <int v> struct LIT { 
   INLINE_RET( v; ) 
   INLINE_DERIV( 0; )
};

#endif
