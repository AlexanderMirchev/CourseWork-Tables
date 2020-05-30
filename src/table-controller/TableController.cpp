#include "TableController.h"
#include <iostream>
#include "../cells/CellFactory.h"
#include "../exceptions/Exceptions.cpp"

const Table &TableController::getTable() const
{
    if (!this->table.has_value())
    {
        throw NoSource();
    }
    return this->table.value();
}

void TableController::setTable(const Table &table)
{
    if (this->table.has_value())
    {
        throw SourceAlreadyExists();
    }
    this->table = table;
}

void TableController::removeTable()
{
    if (!this->table.has_value())
    {
        throw NoSource();
    }
    this->table = std::nullopt;
}

void TableController::printTable() const
{
    if (!this->table.has_value())
    {
        throw NoSource();
    }
    this->table.value().print();
}
void TableController::editCell(const size_t &row, const size_t &col,
                               const std::string &newValue)
{
    if (!this->table.has_value())
    {
        throw NoSource();
    }
    if (this->table.value()[row][col] == nullptr)
    {
        this->table.value()[row][col] = CellFactory::make(newValue, row, col);
    }
    else
    {
        this->table.value()[row][col]->removeDependencies(this->table.value());
        this->table.value()[row][col]->setValue(
            newValue, CellFactory::makeValue(newValue));
    }

    // table.value().considerWidth(newValue.size(), col);
    std::vector<size_t> columnsToUpdate;
    if (this->table.value()[row][col] != nullptr)
    {
        try
        {
            this->table.value()[row][col]->updateCell(
                this->table.value(), this->table.value()[row][col], columnsToUpdate);
        }
        catch (const std::exception &e)
        {
            std::cout << "Formula created a circular dependency" << '\n';
        }
    }
    updateColumns(columnsToUpdate);
}

void TableController::updateColumns(const std::vector<size_t> &columns)
{
    for (const size_t &col : columns)
    {
        std::cout << col << std::endl;
        size_t minimumColumnWidth = 1;
        for (size_t i = 0; i < this->table.value().numberOfRows(); i++)
        {
            if (table.value()[i][col] != nullptr &&
                table.value()[i][col]->getContentWidth() > minimumColumnWidth)
            {
                minimumColumnWidth = table.value()[i][col]->getContentWidth();
            }
        }
        table.value().setWidth(minimumColumnWidth, col);
    }
}