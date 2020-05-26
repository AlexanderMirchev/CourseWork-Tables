#include "IntegerCell.h"
#include <iostream>

IntegerCell::IntegerCell(const std::string &str)
    : Cell(str), value{std::stoi(str)} {}

void IntegerCell::print() const
{
    std::cout << value;
}
double IntegerCell::getDoubleValue() const
{
    return value;
}
void IntegerCell::calculateValue(const Table &) { return; }