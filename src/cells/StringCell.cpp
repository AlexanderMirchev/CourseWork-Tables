#include "StringCell.h"
#include <iostream>
#include "../utilities/Validation.h"

StringCell::StringCell(const std::string &str) : Cell(str)
{
    this->value = str.substr(1, str.size() - 2);
}

void StringCell::print() const
{
    std::cout << value;
}

double StringCell::getDoubleValue() const
{
    return formulaValue.value();
}
void StringCell::calculateValue(const Table &)
{
    if (this->formulaValue.has_value())
    {
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
}