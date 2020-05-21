#include "DoubleCell.h"
#include <iostream>

DoubleCell::DoubleCell(const std::string &string)
    : Cell(string), value{std::stod(string)} {std::cout << "double cell made"<<std::endl;}

void DoubleCell::print() const
{
    std::cout << value;
}
double DoubleCell::getDoubleValue() const
{
    return value;
}