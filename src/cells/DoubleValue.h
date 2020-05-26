#ifndef DOUBLEVALUE_H
#define DOUBLEVALUE_H

#include "CellValue.h"

class DoubleValue : public CellValue
{
private:
    double value;

public:
    DoubleValue(const std::string &);

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
};
#endif
