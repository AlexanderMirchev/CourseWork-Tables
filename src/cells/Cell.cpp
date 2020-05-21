#include "Cell.h"
#include <iostream>

Cell::Cell(const std::string &str) : baseValue{str}
{
}

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
void Cell::print() const {
    std::cout << baseValue;
}
