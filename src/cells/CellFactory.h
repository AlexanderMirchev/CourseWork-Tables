#ifndef CELLFACTORY_H
#define CELLFACTORY_H

#include "Cell.h"
#include "CellValue.h"
#include <string>
#include <memory>

/*
    Factory class for cells
*/
class CellFactory
{
public:
    /*
        Creates a shared pointer to a cell

        If string is empty will produce nullptr

        Throws UnknownDataType if data cannot be converted to any type
    */
    static std::shared_ptr<Cell> make(
        const std::string &, const size_t &row, const size_t &col);

    /*
        Creates a shared pointer to a cell content value

        If string is empty will produce nullptr

        Throws std::invalid_argument if string cannot be converted to value
    */
    static std::shared_ptr<CellValue> makeValue(const std::string &);

private:
    static std::shared_ptr<CellValue> createFormula(const std::string &);
};
#endif