#include "CellFactory.h"

#include "../utilities/Validation.h"
#include "../utilities/Utility.h"

#include "DoubleCell.h"
#include "IntegerCell.h"
#include "FormulaCell.h"
#include "ReferenceCell.h"
#include "StringCell.h"

std::shared_ptr<Cell> CellFactory::make(const std::string &input)
{
    const std::string str = utility::trim(input);
    if (str.empty())
    {
        return std::shared_ptr<Cell>(nullptr);
    }
    if (validation::isValidFormula(str))
    {
        return createFormula(str.substr(1));
    }
    if (validation::isValidString(str))
    {
        return std::shared_ptr<Cell>(new StringCell(str));
    }
    if (validation::isValidReference(str))
    {
        return std::shared_ptr<Cell>(new ReferenceCell(str));
    }
    if (validation::isValidInteger(str))
    {
        return std::shared_ptr<Cell>(new IntegerCell(str));
    }
    if (validation::isValidDouble(str))
    {
        return std::shared_ptr<Cell>(new DoubleCell(str));
    }
    throw 20;
}

std::shared_ptr<Cell> CellFactory::createFormula(const std::string &str)
{
    unsigned int iter = 0;

    int indexOfOperation = -1;
    bool isPower = true;
    while (iter < str.size())
    {
        if (validation::isOperation(str[iter]) && iter != str.size() - 1)
        {
            if (str[iter] == '+' || str[iter] == '-')
            {
                return std::shared_ptr<Cell>(
                    new FormulaCell(
                        str, createFormula(str.substr(0, iter)),
                        createFormula(str.substr(iter + 1)),
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
        return std::shared_ptr<Cell>(
            new FormulaCell(
                str, createFormula(str.substr(0, indexOfOperation)),
                createFormula(str.substr(indexOfOperation + 1)),
                str[indexOfOperation]));
    }
    else
    {
        return make(str);
    }
}
