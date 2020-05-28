#include "Cell.h"
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
    for (const std::shared_ptr<Cell> &cell : this->dependantCells)
    {
        if (cell == newCell)
        {
            return;
        }
    }
    this->dependantCells.push_back(newCell);
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

void Cell::removeDependencies(Table &table)
{
    if (this->value != nullptr)
    {
        this->value->removeDependantCell(table[this->row][this->col], table);
    }
}

void Cell::updateCell(Table &table, const std::shared_ptr<Cell> &startCell)
{
    std::cout << "Updating :" << row << " " << col << std::endl;
    if (this->value != nullptr)
    {
        this->value->nullify();
        this->value->calculateValue(table);
        this->value->setDependantCell(table[this->row][this->col], table);
    }
    bool hasCircularDependency = false;
    for (std::shared_ptr<Cell> cell : dependantCells)
    {
        if (cell != startCell)
        {
            try
            {
                cell->updateCell(table, startCell);
            }
            catch (const std::exception &e)
            {
                hasCircularDependency = true;
            }
        }
        else
        {
            hasCircularDependency = true;
        }
    }
    if (hasCircularDependency)
    {
        this->value->nullify();
        throw std::exception();
    }
    size_t minimumColumnWidth = 1;
    for (size_t i = 0; i < table.numberOfRows(); i++)
    {
        if (table[i][col] != nullptr &&
            table[i][col]->value != nullptr &&
            table[i][col]->value->getMinimalWidth() > minimumColumnWidth)
        {
            minimumColumnWidth = table[i][col]->value->getMinimalWidth();
        }
    }

    table.setWidth(minimumColumnWidth, col);
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