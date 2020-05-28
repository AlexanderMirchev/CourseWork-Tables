#include "DoubleValue.h"
#include <iostream>

DoubleValue::DoubleValue(const std::string &string)
    : value{std::stod(string)}, minimalWidth{string.size()} {}

void DoubleValue::print() const
{
    std::cout << value;
}
double DoubleValue::getDoubleValue() const
{
    return value;
}
void DoubleValue::calculateValue(Table &) { return; }
void DoubleValue::setDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }
void DoubleValue::removeDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }
void DoubleValue::nullify() { return; }
size_t DoubleValue::getMinimalWidth() const { return minimalWidth; }