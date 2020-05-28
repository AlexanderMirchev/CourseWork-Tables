#include "IntegerValue.h"
#include <iostream>

IntegerValue::IntegerValue(const std::string &str)
    : value{std::stoi(str)}, minimalWidth{str.size()} {}

void IntegerValue::print() const
{
    std::cout << value;
}
double IntegerValue::getDoubleValue() const
{
    return value;
}
void IntegerValue::calculateValue(Table &) { return; }
void IntegerValue::setDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }
void IntegerValue::removeDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }
void IntegerValue::nullify() { return; }
size_t IntegerValue::getMinimalWidth() const { return minimalWidth; }