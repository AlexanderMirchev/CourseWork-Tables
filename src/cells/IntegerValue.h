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
    void setDependantCell(const std::shared_ptr<Cell> &, Table&) const override;
    void nullify() override;
};
#endif
