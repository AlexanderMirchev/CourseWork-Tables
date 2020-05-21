#ifndef TABLE_H
#define TABLE_H

#include <cassert>
#include <memory>
#include <vector>
#include "../cells/Cell.h"

class Table
{
private:
    std::vector<std::vector<std::shared_ptr<Cell>>> table;
    std::vector<size_t> columnWidths;

public:
    Table() = default;
    ~Table() = default;

    size_t numberOfRows() const;

    void considerWidth(const size_t &, const unsigned int &col);

    std::vector<std::shared_ptr<Cell>> &operator[](const size_t &row);

    const std::vector<std::shared_ptr<Cell>> &operator[](const size_t &row) const;

    void print() const;
};
#endif
