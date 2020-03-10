#include "Main.h"
#include <iostream>

int main(int argc, const char * argv[]) {
   // Question 3
   // Derivatives
   //
   typedef DIVIDE<ADDITION<EXPONENT<VAR, LIT<20> >, LIT<3> >, SUBTRACT<VAR, LIT<3> > > FORMULA8;
   printf("Derivative result when x=5 is: %f\n", FORMULA8::eval(5));
   printf("Derivative result when x=10 is: %f\n", FORMULA8::eval(10));
   return 0;
}

