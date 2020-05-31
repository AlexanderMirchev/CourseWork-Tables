#ifndef ROW_H
#define ROW_H

#include <vector>
#include <memory>
#include "../cells/Cell.h"

/**
 * Class representing row in a table
*/
class Cell;
class Row
{
private:
    std::vector<std::shared_ptr<Cell>> cells;

public:
    Row() = default;
    ~Row() = default;

    /**
     * Returns size of row(from first cell to last non-empty)
    */
    size_t size() const;

    /**
     * Adds cell to end of row
    */
    void push_back(const std::shared_ptr<Cell> &);

    /**
     * Returns shared pointer to cell with index col
     * Returns nullptr if cell is empty(and has no dependencies) 
    */
    const std::shared_ptr<Cell> operator[](const size_t &col) const;

    /**
     *  Returns shared pointer to cell (modifiable) and 
        adds empty cells if not in range
    */
    std::shared_ptr<Cell> &operator[](const size_t &col);
};
#endif
