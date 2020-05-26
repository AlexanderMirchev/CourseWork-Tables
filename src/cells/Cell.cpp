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
    if (this->value == nullptr)
    {
        std::cout << " ";
    }
    else
    {
        this->value->print();
    }
}
double Cell::getDoubleValue() const
{
    if (this->value == nullptr)
    {
        return 0;
    }
    return this->value->getDoubleValue();
}
void Cell::readyCell(Table &table)
{
    if (this->value != nullptr)
    {
        this->value->nullify();
        this->value->calculateValue(table);
        this->value->setDependantCell(std::make_shared<Cell>(*this), table);
    }
    for (std::shared_ptr<Cell> cell : dependantCells)
    {
        cell->readyCell(table);
    }
}
void Cell::setValue(const std::shared_ptr<CellValue> &newValue)
{
    this->value = newValue;
}
