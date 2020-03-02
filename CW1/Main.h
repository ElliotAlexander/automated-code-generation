#ifndef _main_h_
#define _main_h_

#include <functional>

#define PLUS std::plus<double>
#define DIVIDE std::divides<double>
#define SUBTRACT std::minus<double>
#define MULTIPLY std::multiplies<double>

// Data types
//
struct VAR {
   static inline double eval(double d){
      return d;
   };
};

template <int v> 
struct LIT {
   static inline double eval(double d){
      return v;
   };
};

template <class L, typename Op,  class R>
struct OP{
   static inline double eval(double d){
      Op o;
      return o(L::eval(d), R::eval(d));
   };
};

#endif
