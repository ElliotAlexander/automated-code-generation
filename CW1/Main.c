#include <iostream>
#include "Main.h"

int main(int argc, const char * argv[]){
   typedef OP<OP<OP<LIT<5>,PLUS,LIT<10> >, DIVIDE, OP<LIT<3>, PLUS, LIT<2> > >, MULTIPLY, VAR > FORMULA;
   printf("%f\n", (FORMULA::eval(5)));
   return 0;
}
