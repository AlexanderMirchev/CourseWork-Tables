#ifndef CELLFACTORY_H
#define CELLFACTORY_H

#include "Cell.h"
#include "../table/Table.h"
#include <string>
#include <memory>


class CellFactory
{
public:
    static std::shared_ptr<Cell> make(const std::string&);
private:
    static std::shared_ptr<Cell> createFormula(const std::string&);
};
#endif