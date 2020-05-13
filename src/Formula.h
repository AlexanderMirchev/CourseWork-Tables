#ifndef FORMULA_H
#define FORMULA_H

class Formula
{
public:
    virtual ~Formula() = default;
    virtual double getValue() = 0;
};
#endif
