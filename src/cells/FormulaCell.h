#ifndef FORMULACELL_H
#define FORMULACELL_H

#include "Cell.h"
#include <optional>

class FormulaCell : public Cell
{
private:
    // double value;
    // std::vector<std::shared_ptr<Cell>> cellContents;
    // std::vector<char> operations;

    std::optional<double> value;
    std::shared_ptr<Cell> firstPart;
    std::shared_ptr<Cell> secondPart;
    char operation;

public:
    FormulaCell(const std::string &,
                const std::shared_ptr<Cell> &firstPart,
                const std::shared_ptr<Cell> &secondPart,
                const char &operation);

    // void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table&) override;
};
#endif
