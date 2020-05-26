#ifndef CELLFACTORY_H
#define CELLFACTORY_H

#include "Cell.h"
#include "CellValue.h"
#include <string>
#include <memory>


class CellFactory
{
public:
    static std::shared_ptr<Cell> make(const std::string&);
private:
    static std::shared_ptr<CellValue> makeValue(const std::string&);
    static std::shared_ptr<CellValue> createFormula(const std::string&);
};
#endif