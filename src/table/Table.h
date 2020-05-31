#ifndef TABLE_H
#define TABLE_H

#include <cassert>
#include <memory>
#include <vector>
#include "../cells/Cell.h"
#include "Row.h"

/**
 * Class for table
*/
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

    /**
     * Sets a bigger field width for column if size is 
     * bigger than current max for column
    */
    void considerWidth(const size_t &, const size_t &col);

    /**
     * Sets width to size
    */
    void setWidth(const size_t &, const size_t &col);

    /**
     * Returns modifiable reference to row and adds
     * empty rows if out of range 
    */
    Row &operator[](const size_t &row);

    /**
     * Returns row with index row
     * Returns empty row if out of range
    */
    const Row operator[](const size_t &row) const;

    /**
     * Print whole table
    */
    void print() const;

    /**
     * Calculates all cells that are not calculated yet
     * (when everything is initialized)
    */
    void makeAllCalculations();
};
#endif
