#include "CellFactory.h"

Cell *CellFactory::make(const std::string &value)
{
}

const CellFactory::Type &CellFactory::resolveType(const std::string &value)
{

    if (isValidFormula(value))
    {
        return FORMULA;
    }
    if (isValidString(value))
    {
        return STRING;
    }
}

bool CellFactory::isValidFormula(const std::string &value)
{
    if (value.front() == '=' && value.size() > 1)
    {
        for (size_t i = 1; i < value.size(); i++)
        {
            if (!isNumber(value[i]) && !isOperation(value[i]) && value[i] != 'R' && value[i] != 'C')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool CellFactory::isValidString(const std::string &value)
{
    return value.front() == '"' && value.back() == '"';
}

bool CellFactory::isValidInteger(const std::string &value)
{
    if (value.front() == '+' || value.front() == '-' || isNumber(value.front()))
    {
        for (size_t i = 1; i < value.size(); i++)
        {
            if(!isNumber(value[i])) {
                return false;
            }
        }
        return true;
    }
    return true;
}
bool CellFactory::isValidDouble(const std::string &)
{
}

bool CellFactory::isNumber(const char & c) {
    return c >= '0' && c <= '9';
}
bool CellFactory::isOperation(const char & c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}