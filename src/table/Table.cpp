#include "Table.h"
#include <iostream>
#include <iomanip>

void Table::considerWidth(const size_t &width, const unsigned int &col)
{
    while (columnWidths.size() <= col)
    {
        columnWidths.push_back(1);
    }
    if (width > columnWidths[col])
    {
        columnWidths[col] = width;
    }
}

size_t Table::numberOfRows() const
{
    return table.size();
}

Row &Table::operator[](const size_t &row)
{
    while (row >= table.size())
    {
        table.push_back(Row());
    }

    return table[row];
}

const Row Table::operator[](const size_t &row) const
{
    if (row >= table.size())
    {
        return Row();
    }
    return table[row];
}
void Table::print() const
{
    std::cout << table.size() << std::endl;
    for (size_t row = 0; row < table.size(); row++)
    {
        std::cout << "|";
        for (size_t col = 0; col < columnWidths.size(); col++)
        {
            std::cout << std::setw(columnWidths[col]);
            if (col < table[row].size() && table[row][col] != nullptr)
            {
                table[row][col]->print();
            }
            else
            {
                std::cout << " ";
            }
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}
void Table::makeAllCalculations()
{
    for (Row &row : table)
    {
        for (size_t i = 0; i < row.size(); i++)
        {
            if (row[i] != nullptr)
            {
                row[i]->readyCell(*this);
            }
        }
    }
}