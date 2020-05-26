#include "ReferenceValue.h"
#include <iostream>

ReferenceValue::ReferenceValue(const std::string &str)
{
    const std::pair<int, int> coordinates = parseFromString(str);
    row = coordinates.first;
    col = coordinates.second;
}

double ReferenceValue::getDoubleValue() const
{
    return this->value.value();
}

void ReferenceValue::calculateValue(const Table &table)
{
    if (!this->value.has_value())
    {
        if (table[this->row][this->col] == nullptr)
        {
            this->value = 0;
        }
        else
        {
            this->value = table[this->row][this->col]->getDoubleValue();
        }
    }
}

void ReferenceValue::setDependantCell(
    const std::shared_ptr<Cell> &cell, Table &table) const
{
    if (table[this->row][this->col] == nullptr)
    {
        table[this->row][this->col] = std::shared_ptr<Cell>(new Cell("", nullptr));
    }
    table[this->row][this->col]->addDependantCell(cell);
}

void ReferenceValue::print() const
{
    std::cout << value.value();
}
void ReferenceValue::nullify()
{
    this->value = std::nullopt;
}

std::pair<int, int> ReferenceValue::parseFromString(const std::string &str)
{
    const size_t posOfC = str.find('C');
    const int rowNum = std::stoi(str.substr(1, posOfC));
    const int colNum = std::stoi(str.substr(posOfC + 1));
    return std::pair<int, int>(rowNum - 1, colNum - 1);
}