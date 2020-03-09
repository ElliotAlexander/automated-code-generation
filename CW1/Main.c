#include <iostream>
#include "Main.h"

int main(int argc, const char * argv[]){
   // (5+5) - 15
   typedef SUBTRACT<PAREN<ADDITION<LIT<5>, LIT<5> > >,LIT<15>  > FORMULA;
   // (x-2)^2
   typedef EXPONENT<PAREN<SUBTRACT<VAR, LIT<2> > >, LIT<2> > FORMULA2;
   // x^4 + (x-2)^2 + (x*3) + 5
   typedef ADDITION<ADDITION<ADDITION<EXPONENT<VAR, LIT<4> >, EXPONENT<PAREN<SUBTRACT<VAR, LIT<2> > >, LIT<2> > >, PAREN<MULTIPLY<VAR, LIT<3> > > >, LIT<5> > FORMULA3;
   // (5-2)^3
   typedef EXPONENT<PAREN<SUBTRACT<LIT<5>, LIT<2> > >, LIT<3> > FORMULA4;
   // x^(x + 10) - Be careful of integer overflow
   typedef EXPONENT<VAR, PAREN<ADDITION<VAR, LIT<10> > > > FORMULA5;
   // x^x --
   typedef EXPONENT<VAR, VAR> FORMULA6;


   // Question 1
   //
   // (10-5)^(x+2)
   typedef EXPONENT<PAREN<SUBTRACT<LIT<10>, LIT<5> > >, PAREN<ADDITION<VAR, LIT<2> > > > FORMULA7;
   printf("Result is %f\n", FORMULA7::eval(2));

   double x = EVAL<2, FORMULA7>::RET;
   printf("Result 2 is %f\n", x);


   // Question 2
   // Integrals
   //
   typedef SUBTRACT<ADDITION<EXPONENT<VAR, LIT<2> >, PAREN<MULTIPLY<LIT<2>, VAR> > >, LIT<3> > POLY1;
   printf("Rectangle approximation Result is %f\n", INTEGRAL<100, RECTANGLE<POLY1> >::integrate(0, 10));
   printf("Trapezoid approxmination Result is %f\n", INTEGRAL<100, TRAPEZOID<POLY1> >::integrate(0,10));

   // Question 3
   // Derivatives
   //
   typedef DIVIDE<ADDITION<EXPONENT<VAR, LIT<20> >, LIT<3> >, SUBTRACT<VAR, LIT<3> > > FORMULA8;
   printf("Derivative result when x=5 is: %f\n", FORMULA8::eval(5));
   printf("Derivative result when x=10 is: %f\n", FORMULA8::eval(10));
   return 0;
}
