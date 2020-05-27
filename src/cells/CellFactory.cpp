#include "CellFactory.h"

#include "../utilities/Validation.h"
#include "../utilities/Utility.h"

#include "DoubleValue.h"
#include "FormulaValue.h"
#include "IntegerValue.h"
#include "ReferenceValue.h"
#include "StringValue.h"
#include <iostream>

std::shared_ptr<Cell> CellFactory::make(
    const std::string &input, const size_t &row, const size_t &col)
{
    const std::string str = utility::trim(input);
    if (str.empty())
    {
        return std::shared_ptr<Cell>(nullptr);
    }
    else
    {
        return std::shared_ptr<Cell>(new Cell(str, makeValue(str), row, col));
    }

    throw 20;
}

std::shared_ptr<CellValue> CellFactory::makeValue(const std::string &str)
{
    if (str.empty())
    {
        return nullptr;
    }

    if (validation::isValidFormula(str))
    {
        return createFormula(str);
    }
    if (validation::isValidString(str))
    {
        return std::shared_ptr<CellValue>(new StringValue(str));
    }
    if (validation::isValidReference(str))
    {
        return std::shared_ptr<CellValue>(new ReferenceValue(str));
    }
    if (validation::isValidInteger(str))
    {
        return std::shared_ptr<CellValue>(new IntegerValue(str));
    }
    if (validation::isValidDouble(str))
    {
        return std::shared_ptr<CellValue>(new DoubleValue(str));
    }
    throw 20;
}

std::shared_ptr<CellValue> CellFactory::createFormula(const std::string &fullStr)
{
    const std::string str = (fullStr.front() == '=') ? fullStr.substr(1) : fullStr;
    unsigned int iter = 0;

    int indexOfOperation = -1;
    bool isPower = true;
    while (iter < str.size())
    {
        if (validation::isOperation(str[iter]) && iter != str.size() - 1)
        {
            if (str[iter] == '+' || str[iter] == '-')
            {
                return std::shared_ptr<CellValue>(
                    new FormulaValue(
                        createFormula(utility::trim(str.substr(0, iter))),
                        createFormula(utility::trim(str.substr(iter + 1))),
                        str[iter]));
            }
            if ((str[iter] == '*' || str[iter] == '/') && isPower)
            {
                indexOfOperation = iter;
                isPower = false;
            }
            else
            {
                indexOfOperation = iter;
            }
        }
        ++iter;
    }
    if (indexOfOperation >= 0)
    {
        return std::shared_ptr<CellValue>(
            new FormulaValue(
                createFormula(utility::trim(str.substr(0, indexOfOperation))),
                createFormula(utility::trim(str.substr(indexOfOperation + 1))),
                str[indexOfOperation]));
    }
    else
    {
        return makeValue(utility::trim(str));
    }
}
