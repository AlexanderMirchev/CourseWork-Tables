#ifndef IDFORMULA_H
#define IDFORMULA_H

#include "Formula.h"

class IdentityFormula: public Formula
{
private:
    class Value {
        public:
            virtual Value()
            virtual double getValue() = 0;
    };

    class 

    /* data */
public:
    IdentityFormula(/* args */);
    ~IdentityFormula();
};

IdentityFormula::IdentityFormula(/* args */)
{
}

IdentityFormula::~IdentityFormula()
{
}


#endif