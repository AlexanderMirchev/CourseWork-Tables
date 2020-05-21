#ifndef FORMULACELL_H
#define FORMULACELL_H

#include "Cell.h"

class FormulaCell : public Cell
{
private:
    double value;
    std::vector<std::shared_ptr<Cell>> cellContents;
    std::vector<char> operations;

public:
    FormulaCell(const std::string &,
                std::vector<std::shared_ptr<Cell>> &&, std::vector<char> &&);

    // void print() const override;
    double getDoubleValue() const override;
};
#endif
