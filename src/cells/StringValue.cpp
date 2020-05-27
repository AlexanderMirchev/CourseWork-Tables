#include "StringValue.h"
#include <iostream>
#include "../utilities/Validation.h"

StringValue::StringValue(const std::string &str)
{
    this->value = str.substr(1, str.size() - 2);

    if (validation::isValidInteger(value))
    {
        this->formulaValue = std::stoi(value);
    }
    else if (validation::isValidDouble(value))
    {
        this->formulaValue = std::stod(value);
    }
    else
    {
        this->formulaValue = 0;
    }
}

void StringValue::print() const
{
    std::cout << value;
}

double StringValue::getDoubleValue() const
{
    return formulaValue;
}
void StringValue::calculateValue(const Table &) { return; }

void StringValue::setDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }
void StringValue::removeDependantCell(
    const std::shared_ptr<Cell> &, Table &) const { return; }

void StringValue::nullify() { return; }