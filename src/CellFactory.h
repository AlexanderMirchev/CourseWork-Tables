#ifndef CELLFACTORY_H
#define CELLFACTORY_H

#include "Cell.h"
#include <vector>

class CellFactory
{
public:
    static Cell *make(const std::string &value);

private:
    enum Type
    {
        INTEGER,
        DOUBLE,
        STRING,
        FORMULA,
        EMPTY,
        ERROR
    };

    static const Type &resolveType(const std::string &value);

    static bool isValidInteger(const std::string&);
    static bool isValidDouble(const std::string&);
    static bool isValidFormula(const std::string&);
    static bool isValidString(const std::string&);

    static bool isNumber(const char&);
    static bool isOperation(const char&);
    
};
#endif
