#include "ReferenceValue.h"
#include <iostream>

ReferenceValue::ReferenceValue(const std::string &str)
{
    const std::pair<size_t, size_t> coordinates = parseFromString(str);
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
            try
            {
                this->value = table[this->row][this->col]->getDoubleValue();
            }
            catch (const std::exception &e)
            {
                this->value = std::nullopt;
            }
        }
    }
}

void ReferenceValue::setDependantCell(
    const std::shared_ptr<Cell> &cell, Table &table) const
{
    if (table[this->row][this->col] == nullptr)
    {
        table[this->row][this->col] = std::shared_ptr<Cell>(new Cell("", nullptr, this->row, this->col));
    }
    table[this->row][this->col]->addDependantCell(cell);
}

void ReferenceValue::removeDependantCell(const std::shared_ptr<Cell> &cell, Table &table) const
{
    if (table[this->row][this->col] != nullptr)
    {
        table[this->row][this->col]->removeDependantCell(cell);
    }
}

void ReferenceValue::print() const
{
    if (this->value.has_value())
    {
        std::cout << value.value();
    }
    else
    {
        std::cout << "ERROR";
    }
}

void ReferenceValue::nullify()
{
    this->value = std::nullopt;
}

std::pair<size_t, size_t> ReferenceValue::parseFromString(const std::string &str)
{
    const size_t posOfC = str.find('C');
    const size_t rowNum = std::stoi(str.substr(1, posOfC));
    const size_t colNum = std::stoi(str.substr(posOfC + 1));
    return std::pair<size_t, size_t>(rowNum - 1, colNum - 1);
}