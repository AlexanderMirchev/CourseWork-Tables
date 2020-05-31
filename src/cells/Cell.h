#ifndef CELL_H
#define CELL_H

#include "CellValue.h"
#include "../table/Table.h"

#include <memory>
#include <string>
#include <vector>

/**
 * Class for cell and it's contents and dependencies
*/
class CellValue;
class Table;
class Cell
{
private:
    size_t row;
    size_t col;
    std::string baseValue;
    std::shared_ptr<CellValue> value;
    std::vector<std::shared_ptr<Cell>> dependantCells;
    bool isPrepared;

public:
    Cell(const std::string &, const std::shared_ptr<CellValue> &,
         const size_t &, const size_t &);

    /**
     * Returns the value from which it's been created
    */
    const std::string &getBaseValue() const;

    /**
     * Adds a cell to the list of cells that contain a reference 
     * to this cell(and therefore should change when this cell is edited)
     * 
     * Example:
     * Cell1 has Cell2 as dependant cell
     * Cell1 changes -> Cell2 changes
    */
    void addDependantCell(const std::shared_ptr<Cell> &);

    /**
     *  Removes a cell from the list of dependant cells
    */
    void removeDependantCell(const std::shared_ptr<Cell> &);

    /**
     * Sets the value of the cell
    */
    void setValue(const std::string &, const std::shared_ptr<CellValue> &);

    /**
     * Outputs the value of the cell 
    */
    void print() const;

    /**
     * Returns the double value of the content in the cell
    */
    double getDoubleValue() const;

    /**
     * Updates the cell and it's dependant cells
     * StartCell is for detecting whether a loop is caused in 
     * updating dependant cells
     * 
     * Throw CreatedCircularDependency
    */
    void updateCell(Table &, const std::shared_ptr<Cell> &startCell,
                    std::vector<size_t> &updatedColumns);

    /**
     * Calculates and links the cell
    */
    void prepareCell(Table &);

    /**
     * Remove this cell from all cells that have this cell as dependant
    */
    void removeDependencies(Table &);

    /**
     * Returns the width of the contents in the cell
    */
    size_t getContentWidth() const;
};
#endif
