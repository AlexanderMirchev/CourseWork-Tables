#ifndef CELLVALUE_H
#define CELLVALUE_H

#include "../table/Table.h"
#include "Cell.h"

/**
 * A class for cell content values
 * Dynamic contents can change on update of different cells
*/
class Cell;
class Table;
class CellValue
{
public:
    virtual ~CellValue() = default;

    /**
     * Prints the value of the cell
    */
    virtual void print() const = 0;

    /**
     * Returns the value of the cell used for formulas
     * 
     * Throws std::bad_optional_access (on dynamic cells)
    */
    virtual double getDoubleValue() const = 0;

    /**
     * Calculates the value of the cell 
     * (if there is anything to calculate)
    */
    virtual void calculateValue(Table &) = 0;

    /**
     * Sets a dependant cell to the cell value 
     * (if contains a reference to another cell)
    */
    virtual void setDependantCell(const std::shared_ptr<Cell> &, Table &) const = 0;

    /**
     * Removes dependant cell to the cell value 
     * (if contains reference)
    */
    virtual void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const = 0;

    /**
     * Resets the value without changing the syntax 
     * (if contains reference) 
    */
    virtual void nullify() = 0;

    /**
     * Returns the minimal width of the cell
    */
    virtual size_t getMinimalWidth() const = 0;
};
#endif
