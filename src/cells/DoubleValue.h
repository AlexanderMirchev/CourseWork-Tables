#ifndef DOUBLEVALUE_H
#define DOUBLEVALUE_H

#include "CellValue.h"

class DoubleValue: public CellValue
{
private:
    double value;

public:
    DoubleValue(const std::string&);

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table&) override;
};
#endif
