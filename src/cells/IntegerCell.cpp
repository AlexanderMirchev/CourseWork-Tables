#include "IntegerCell.h"
#include <iostream>

IntegerCell::IntegerCell(const std::string &str)
    : Cell(str), value{std::stoi(str)} {std::cout << "integer cell made"<<std::endl;}

void IntegerCell::print() const
{
    std::cout << value;
}
double IntegerCell::getDoubleValue() const {
    return value;
}