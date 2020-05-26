#include "Cell.h"
#include <iostream>

Cell::Cell(const std::string &str, const std::shared_ptr<CellValue> &value)
    : baseValue{str}, value{value} {}

const std::string &Cell::getBaseValue() const
{
    return this->baseValue;
}

void Cell::addDependantCell(const std::shared_ptr<Cell> &cell)
{
    this->dependantCells.push_back(cell);
}
void Cell::removeDependantCell(const std::shared_ptr<Cell> &cell)
{
    for (size_t i = 0; i < dependantCells.size(); i++)
    {
        if (cell == dependantCells[i])
        {
            dependantCells.erase(dependantCells.begin() + i);
        }
    }
}
void Cell::print() const
{
    this->value->print();
}
double Cell::getDoubleValue() const
{
    return this->value->getDoubleValue();
}
void Cell::calculateValue(const Table &table)
{
    this->value->calculateValue(table);
}
