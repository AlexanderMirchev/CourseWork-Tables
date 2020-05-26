#include "TableController.h"
#include "../cells/CellFactory.h"

const Table &TableController::getTable() const
{
    if (!this->table.has_value())
    {
    }
    return this->table.value();
}

void TableController::setTable(const Table &table)
{
    if (this->table.has_value())
    {
    }
    this->table = table;
}

void TableController::removeTable()
{
    if (!this->table.has_value())
    {
    }
    this->table = std::nullopt;
}

void TableController::printTable() const
{
    if (!this->table.has_value())
    {
    }
    this->table.value().print();
}
void TableController::editCell(const size_t &row, const size_t &col,
                               const std::string &newValue)
{
    if (!this->table.has_value())
    {
    }
    this->table.value()[row][col] = CellFactory::make(newValue);
    table.value().considerWidth(newValue.size(), col);
}