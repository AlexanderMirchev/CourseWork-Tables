#ifndef FORMULAVALUE_H
#define FORMULAVALUE_H

#include "CellValue.h"
#include <optional>

class FormulaValue : public CellValue
{
private:
    // double value;
    // std::vector<std::shared_ptr<Cell>> cellContents;
    // std::vector<char> operations;

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
