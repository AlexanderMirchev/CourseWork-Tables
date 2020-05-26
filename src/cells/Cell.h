#ifndef CELL_H
#define CELL_H

#include "CellValue.h"
#include "../table/Table.h"

#include <memory>
#include <string>
#include <vector>

/*
    Class for cell and it's contents and dependencies
*/
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

    /*
        Returns the value from which it's been created
    */
    const std::string &getBaseValue() const;
    /*
        Adds a cell to the list of cells that contain a reference 
        to this cell(and therefore should change when this cell is edited)
    */
    void addDependantCell(const std::shared_ptr<Cell> &);

    /*
        Removes a cell from the list of dependant cells
    */
    void removeDependantCell(const std::shared_ptr<Cell> &);

    /*
        Sets the value of the cell
    */
    void setValue(const std::string &, const std::shared_ptr<CellValue> &);

    /*
        Outputs the value of the cell
    */
    void print() const;

    /*
        Returns the double value of the content in the cell
    */
    double getDoubleValue() const;

    /*
        Updates the cell and it's dependant cells
    */
    void updateCell(Table &);
};
#endif
