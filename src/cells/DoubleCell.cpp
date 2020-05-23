#include "DoubleCell.h"
#include <iostream>

DoubleCell::DoubleCell(const std::string &string)
    : Cell(string), value{std::stod(string)} {}

void DoubleCell::print() const
{
    std::cout << value;
}
double DoubleCell::getDoubleValue() const
{
    return value;
}