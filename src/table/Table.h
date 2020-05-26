#ifndef TABLE_H
#define TABLE_H

#include <cassert>
#include <memory>
#include <vector>
#include "../cells/Cell.h"
#include "Row.h"

class Row;
class Table
{
private:
    std::vector<Row> table;
    std::vector<size_t> columnWidths;

public:
    Table() = default;
    ~Table() = default;

    size_t numberOfRows() const;

    void considerWidth(const size_t &, const unsigned int &col);

    Row &operator[](const size_t &row);

    const Row operator[](const size_t &row) const;

    void print() const;

    void makeAllCalculations();
};
#endif
