#include <iostream>
#include "Main.h"

int main(int argc, const char * argv[]){
   
   // Question 2
   // Integrals
   //
   typedef SUBTRACT<ADDITION<EXPONENT<VAR, LIT<2> >, PAREN<MULTIPLY<LIT<2>, VAR> > >, LIT<3> > POLY1;
   printf("Rectangle approximation Result is %f\n", INTEGRAL<100, RECTANGLE<POLY1> >::integrate(0, 10));
   printf("Trapezoid approxmination Result is %f\n", INTEGRAL<100, TRAPEZOID<POLY1> >::integrate(0,10));
   return 0;


}
