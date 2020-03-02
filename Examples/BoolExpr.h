//
//  BoolExpr.h
//  BoolExpr
//
//  Created by Julian Rathke on 15/03/2016.
//  Copyright (c) 2020 Julian Rathke. All rights reserved.
//

#ifndef BoolExpr_BoolExpr_h
#define BoolExpr_BoolExpr_h

template <bool b, class T, class E>
struct IF {
    typedef T RET;
};

template <class T, class E>
struct IF<false,T,E> {
    typedef E RET;
};

struct VAR { 
  static inline bool eval(bool b){
    return b;
  };  
};

template <bool V>
struct LIT {
  static inline bool eval(bool b){
    return V;
  };
};

template <class L, class R>
struct AND {
    static inline bool eval(bool b){
        return L::eval(b) && R::eval(b);
    };
};

template <class L, class R>
struct OR {
  static inline bool eval(bool b){
        return L::eval(b) || R::eval(b);
    };
};

template <class L, class R>
struct IMPLIES {
   static inline bool eval(bool b){
        return !(L::eval(b)) || R::eval(b);
    };
};

template <class F>
struct NEG {
  static inline bool eval(bool b){
        return !F::eval(b) ;
    };
};

//EVAL < true, IMPLIES < AND < VAR , NEG <VAR> > , LIT<false> > > :: RET

template <bool b, class F>
struct EVAL;

template <bool b>
struct EVAL <b, VAR> {
    enum {RET = b};
};

template <bool b, bool V>
struct EVAL <b, LIT<V> > {
    enum {RET = V};
};

template <bool b , class L, class R>
struct EVAL <b, AND<L,R> > {
   enum { RET = EVAL<b,L>::RET  &&  EVAL<b,R>::RET } ;
};

template <bool b , class L, class R>
struct EVAL <b, OR<L,R> > {
   enum { RET = EVAL<b,L>::RET  ||  EVAL<b,R>::RET } ;
};

template <bool b , class L, class R>
struct EVAL <b, IMPLIES<L,R> > {
   enum { RET = !(EVAL<b,L>::RET)  ||  EVAL<b,R>::RET } ;
};

template <bool b , class F>
struct EVAL <b, NEG<F> > {
   enum { RET = ! EVAL<b,F>::RET }; 
};


#endif

