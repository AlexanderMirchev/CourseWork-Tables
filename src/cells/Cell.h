#ifndef CELL_H
#define CELL_H

#include "CellValue.h"
#include "../table/Table.h"

#include <memory>
#include <string>
#include <vector>

class CellValue;
class Table;
class Cell
{
private:
    std::string baseValue;
    std::shared_ptr<CellValue> value;
    std::vector<std::shared_ptr<Cell>> dependantCells;

public:
    Cell(const std::string &, const std::shared_ptr<CellValue> &);

    const std::string &getBaseValue() const;

    void addDependantCell(const std::shared_ptr<Cell> &);
    void removeDependantCell(const std::shared_ptr<Cell> &);

    void setValue(const std::shared_ptr<CellValue> &);
    void print() const;
    double getDoubleValue() const;
    void readyCell(Table &);
};
#endif
