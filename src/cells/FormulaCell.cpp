#include "FormulaCell.h"
#include <iostream>

FormulaCell::FormulaCell(const std::string &str,
                         const std::shared_ptr<Cell> &firstPart,
                         const std::shared_ptr<Cell> &secondPart,
                         const char &operation)
    : Cell(str), firstPart{firstPart},
      secondPart{secondPart}, operation{operation} {}
double FormulaCell::getDoubleValue() const
{
    return 0;
}