//
//  main.cpp
//  BoolExpr
//
//  Created by Julian Rathke on 15/03/2016.
//  Copyright (c) 2016 Julian Rathke. All rights reserved.
//

#include <iostream>
#include "BoolExpr.h"

int main(int argc, const char * argv[]) {
    
    typedef IMPLIES< NEG<VAR>, AND< LIT<false>, NEG<VAR> > > FORMULA ;
    
    printf("Result is %s\n", (FORMULA::eval(false)  ? "TRUE" : "FALSE" ));
    printf("Result is %s\n", (FORMULA::eval(false) ? "TRUE" : "FALSE" ));

    IF < EVAL<true, FORMULA>::RET, int, char>::RET x;
    x = 5;

    IF < EVAL<false, FORMULA>::RET, int, char>::RET y;
    y = 'a';
    
    printf("x and y are %d and %c\n", x, y);

    return 0;
}

