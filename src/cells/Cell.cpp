#include "Cell.h"
#include "../utilities/Utility.h"
#include <iostream>

Cell::Cell(const std::string &str, const std::shared_ptr<CellValue> &value,
           const size_t &row, const size_t &col)
    : row{row}, col{col}, baseValue{str}, value{value}, isPrepared{false} {}

const std::string &Cell::getBaseValue() const
{
    return this->baseValue;
}

void Cell::addDependantCell(const std::shared_ptr<Cell> &newCell)
{
    utility::uniquePushBack(dependantCells, newCell);
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
    // std::cout << dependantCells.size();
}

double Cell::getDoubleValue() const
{
    if (this->value == nullptr)
    {
        return 0;
    }
    return this->value->getDoubleValue();
}

void Cell::removeDependencies(Table &table)
{
    if (this->value != nullptr)
    {
        this->value->removeDependantCell(table[this->row][this->col], table);
    }
}

void Cell::updateCell(Table &table,
                      const std::shared_ptr<Cell> &startCell,
                      std::vector<size_t> &updatedColumns)
{
    std::cout << "Updating cell:" << row << " " << col;
    if (this->value != nullptr)
    {
        this->value->nullify();
        this->value->calculateValue(table);
        this->value->print();
        std::cout << std::endl;
        this->value->setDependantCell(table[this->row][this->col], table);
    }
    utility::uniquePushBack(updatedColumns, this->col);
    bool hasCircularDependency = false;
    for (std::shared_ptr<Cell> cell : dependantCells)
    {
        if (cell != startCell)
        {
            try
            {
                cell->updateCell(table, startCell, updatedColumns);
            }
            catch (const std::exception &e)
            {
                hasCircularDependency = true;
                this->value->nullify();
            }
        }
        else
        {
            hasCircularDependency = true;
            this->value->nullify();
        }
    }
    if (hasCircularDependency)
    {
        throw std::exception();
    }
}

void Cell::setValue(const std::string &str, const std::shared_ptr<CellValue> &newValue)
{
    this->baseValue = str;
    this->value = newValue;
}

void Cell::prepareCell(Table &table)
{
    if (!isPrepared)
    {
        if (this->value != nullptr)
        {
            this->value->setDependantCell(table[this->row][this->col], table);
        }
        isPrepared = true;
        if (this->value != nullptr)
        {
            this->value->calculateValue(table);
            table.considerWidth(this->value->getMinimalWidth(), col);
        }
    }
}

size_t Cell::getContentWidth() const
{
    if (this->value == nullptr)
    {
        return 0;
    }
    return this->value->getMinimalWidth();
}