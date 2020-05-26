#ifndef CELL_H
#define CELL_H

#include "../table/Table.h"

#include <memory>
#include <string>
#include <vector>

class Table;
class Cell
{
private:
    std::string baseValue;
    std::vector<std::shared_ptr<Cell>> dependantCells;

public:
    Cell(const std::string &);

    const std::string &getBaseValue() const;

    void addDependantCell(const std::shared_ptr<Cell> &);
    void removeDependantCell(const std::shared_ptr<Cell> &);

    virtual void print() const;
    virtual double getDoubleValue() const = 0;
    virtual void calculateValue(const Table &) = 0;
};
#endif
