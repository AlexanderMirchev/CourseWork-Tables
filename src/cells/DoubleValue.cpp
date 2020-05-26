#include "DoubleValue.h"
#include <iostream>

DoubleValue::DoubleValue(const std::string &string)
    : value{std::stod(string)} {}

void DoubleValue::print() const
{
    std::cout << value;
}
double DoubleValue::getDoubleValue() const
{
    return value;
}
void DoubleValue::calculateValue(const Table &) { return; }