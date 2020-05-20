#include "FormulaCell.h"

FormulaCell::FormulaCell(const std::string &str,
                         std::vector<std::shared_ptr<Cell>> &&contents,
                         std::vector<char> &&operations)
    : Cell(str), cellContents{contents}, operations{operations} {}

void FormulaCell::print() const {}
double FormulaCell::getDoubleValue() const {}