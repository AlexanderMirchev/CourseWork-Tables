#ifndef CELL_H
#define CELL_H

#include <memory>
#include <string>
#include <vector>

class Cell
{
private:
    std::string baseValue;
    std::vector<std::shared_ptr<Cell>> dependantCells;

public:
    Cell(const std::string &);

    const std::string& getBaseValue() const;

    void addDependantCell(const std::shared_ptr<Cell> &);
    void removeDependantCell(const std::shared_ptr<Cell> &);

    virtual void print() const;
    virtual double getDoubleValue() const = 0;
};
#endif
