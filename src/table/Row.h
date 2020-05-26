#ifndef ROW_H
#define ROW_H

#include <vector>
#include <memory>
#include "../cells/Cell.h"

class Cell;
class Row
{
private:
    std::vector<std::shared_ptr<Cell>> cells;

public:
    Row() = default;
    ~Row() = default;
    size_t size() const;
    void push_back(const std::shared_ptr<Cell> &);

    const std::shared_ptr<Cell> operator[](const size_t &col) const;
    std::shared_ptr<Cell> &operator[](const size_t &col);
};
#endif
