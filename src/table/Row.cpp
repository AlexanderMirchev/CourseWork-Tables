#include "Row.h"

const std::shared_ptr<Cell> Row::operator[](const size_t &col) const
{
    if (col >= this->cells.size())
    {
        return nullptr;
    }
    return this->cells[col];
}
std::shared_ptr<Cell> &Row::operator[](const size_t &col)
{
    while (col >= this->cells.size())
    {
        this->cells.push_back(nullptr);
    }
    return this->cells[col];
}

size_t Row::size() const
{
    return this->cells.size();
}
void Row::push_back(const std::shared_ptr<Cell> &cell)
{
    return this->cells.push_back(cell);
}