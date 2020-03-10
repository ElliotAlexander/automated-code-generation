#ifndef __main_h_
#define __main_h_


#include <math.h>
#include <functional>

// Copied over from Question 1
//


#define INLINE_RET(BODY) \
   static inline double eval(double d){ \
      return BODY \
   };

#define LR_TEMP template <class L, class R> struct 
template <class EXP> struct PAREN { INLINE_RET( EXP::eval(d); )};
LR_TEMP EXPONENT { 
   INLINE_RET( pow(L::eval(d), R::eval(d)); )
};

LR_TEMP MULTIPLY { 
   INLINE_RET( L::eval(d) * R::eval(d); )
};
LR_TEMP DIVIDE   { 
   INLINE_RET( L::eval(d) / R::eval(d); )
};

LR_TEMP ADDITION { 
   INLINE_RET( L::eval(d) + R::eval(d); )
};

LR_TEMP SUBTRACT { 
   INLINE_RET( L::eval(d) - R::eval(d); )
};

struct VAR  { INLINE_RET( d; ) };
template <int v> struct LIT { INLINE_RET( v; ) };
template <int exp, int count> struct EXPONENT_UNROLL{
   enum { RET = exp * EXPONENT_UNROLL<exp, (count-1)>::RET};
};

template <int exp> struct EXPONENT_UNROLL<exp, 1>{
   enum { RET = 1 };
};

template <int d, class F>
struct EVAL;

template <int d, class EXP>
struct EVAL<d, PAREN<EXP> > {
   enum { RET = EVAL<d, EXP>::RET };
};

template <int d, class base, class exp>
struct EVAL<d, EXPONENT<base, exp > > {
   enum { RET = EVAL<d, base>::RET * EXPONENT_UNROLL<EVAL<d, base>::RET, EVAL<d, exp>::RET>::RET };
};

template <int d, class L, class R>
struct EVAL<d, MULTIPLY<L,R> > {
   enum { RET = EVAL<d, L>::RET * EVAL<d, R>::RET };
};

template <int d, class L, class R>
struct EVAL<d, DIVIDE<L,R> > {
   enum { RET = EVAL<d, L>::RET / EVAL<d, R>::RET };
};

template <int d, class L, class R>
struct EVAL<d, ADDITION<L,R> > {
   enum { RET = EVAL<d, L>::RET + EVAL<d, R>::RET };
};

template <int d, class L, class R>
struct EVAL<d, SUBTRACT<L,R> > {
   enum { RET = EVAL<d, L>::RET - EVAL<d, R>::RET };
};

template <int d>
struct EVAL<d, VAR> {
   enum { RET = d};
};

template <int d, int V>
struct EVAL<d, LIT<V> > {
   enum {RET = V};
};



// Question 2
// Inline integrals
//

template <class V>
struct RECTANGLE {
   static inline double body(double lower, double upper){
      return (upper - lower) * V::eval((upper + lower) / 2);
   }
};

template <class V>
struct TRAPEZOID {
   static inline double body(double lower, double upper){
      return (upper-lower) * ((V::eval(upper) + V::eval(lower)) / 2);
   }
};

template <int n, class B>
struct UNROLL { 
   static inline double eval(double start, double offset){
      return B::body(start + (offset * (n-1)), start + (offset * n)) + UNROLL<n-1,  B>::eval(start, offset);
   }; 
};

template <class B>
struct UNROLL<0, B> {
   static inline double eval(double lower, double upper) {
      return 0; 
   };
};

template <int n ,class V>
struct INTEGRAL {};

template <int n, class V> 
struct INTEGRAL<n, RECTANGLE<V> > {  
   static inline double integrate(double lower, double upper){
      return UNROLL<n, RECTANGLE<V> >::eval(lower,((upper - lower) / n));
   };
};

template <int n, class V>
struct INTEGRAL<n, TRAPEZOID<V> > {
   static inline double integrate(double lower, double upper){
      return UNROLL<n, TRAPEZOID<V> >::eval(lower,((upper - lower) / n));
   };
};

#endif

