#ifndef INTEGERVALUE_H
#define INTEGERVALUE_H

#include "CellValue.h"

class IntegerValue: public CellValue
{
private:
    int value;
    
public:
    IntegerValue(const std::string&);
    ~IntegerValue() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table&) override;
};
#endif
