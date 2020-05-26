#include "IntegerValue.h"
#include <iostream>

IntegerValue::IntegerValue(const std::string &str)
    : value{std::stoi(str)} {}

void IntegerValue::print() const
{
    std::cout << value;
}
double IntegerValue::getDoubleValue() const
{
    return value;
}
void IntegerValue::calculateValue(const Table &) { return; }