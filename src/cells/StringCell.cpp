#include "StringCell.h"
#include <iostream>
#include "Validation.h"

StringCell::StringCell(const std::string &str) : Cell(str)
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

void StringCell::print() const
{
    std::cout << value;
}

double StringCell::getDoubleValue() const
{
    return formulaValue;
}