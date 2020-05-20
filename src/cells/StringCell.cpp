#include "StringCell.h"
#include <iostream>

StringCell::StringCell(const std::string &str) : Cell(str) {}

void StringCell::print() const {
    std::cout << value;
}
double StringCell::getDoubleValue() const
{
}