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
    */
    static std::shared_ptr<Cell> make(const std::string &);

    /*
        Creates a shared pointer to a cell content value
    */
    static std::shared_ptr<CellValue> makeValue(const std::string &);

private:
    static std::shared_ptr<CellValue> createFormula(const std::string &);
};
#endif