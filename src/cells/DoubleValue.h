#ifndef DOUBLEVALUE_H
#define DOUBLEVALUE_H

#include "CellValue.h"

/**
 * Static cell containig double value
*/
class DoubleValue : public CellValue
{
private:
    double value;
    size_t minimalWidth;

public:
    DoubleValue(const std::string &);

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
    size_t getMinimalWidth() const override;
};
#endif
