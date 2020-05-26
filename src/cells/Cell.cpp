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
        try
        {
            this->value->print();
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR";
        }
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

void Cell::updateCell(Table &table)
{
    if (this->value != nullptr)
    {
        this->value->nullify();
        this->value->calculateValue(table);
        this->value->setDependantCell(std::make_shared<Cell>(*this), table);
    }
    for (std::shared_ptr<Cell> cell : dependantCells)
    {
        cell->updateCell(table);
    }
}

void Cell::setValue(const std::string &str, const std::shared_ptr<CellValue> &newValue)
{
    this->baseValue = str;
    this->value = newValue;
}
