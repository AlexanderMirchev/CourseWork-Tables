#ifndef TABLE_H
#define TABLE_H

#include <cassert>
#include <vector>
#include "Cell.h"

class Table
{
private:
    std::vector<std::vector<Cell *>> table;

public:
    Table(/* args */);
    ~Table();

    std::vector<Cell *> &operator[](const size_t &row)
    {
        while (row > table.size() - 1)
        {
            table.push_back(std::vector<Cell *>());
        }

        return table[row];
    }

    const std::vector<Cell *> &operator[](const size_t &row) const
    {
        assert(row < table.size());
        return table[row];
    }
};
#endif
