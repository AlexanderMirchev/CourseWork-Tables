#include "FormulaCell.h"
#include <iostream>

FormulaCell::FormulaCell(const std::string &str,
                         std::vector<std::shared_ptr<Cell>> &&contents,
                         std::vector<char> &&operations)
    : Cell(str), cellContents{contents}, operations{operations} {std::cout << "formula cell made"<<std::endl;}

double FormulaCell::getDoubleValue() const {
    return 0;
}