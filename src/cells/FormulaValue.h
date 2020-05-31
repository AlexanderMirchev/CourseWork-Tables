#ifndef FORMULAVALUE_H
#define FORMULAVALUE_H

#include "CellValue.h"
#include <optional>

/**
 * Dynamic cell containing formula
*/
class FormulaValue : public CellValue
{
private:
    std::optional<double> value;
    std::shared_ptr<CellValue> firstPart;
    std::shared_ptr<CellValue> secondPart;
    char operation;
    size_t minimalWidth;
    bool isCalculated;

public:
    FormulaValue(const std::shared_ptr<CellValue> &firstPart,
                 const std::shared_ptr<CellValue> &secondPart,
                 const char &operation);

    void print() const override;
    double getDoubleValue() const override;

    void calculateValue(Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
    size_t getMinimalWidth() const override;
};
#endif
