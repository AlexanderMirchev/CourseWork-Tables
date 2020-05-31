#ifndef INTEGERVALUE_H
#define INTEGERVALUE_H

#include "CellValue.h"

/**
 * Static cell containing integer value
*/
class IntegerValue : public CellValue
{
private:
    int value;
    size_t minimalWidth;

public:
    IntegerValue(const std::string &);
    ~IntegerValue() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
    size_t getMinimalWidth() const override;
};
#endif
