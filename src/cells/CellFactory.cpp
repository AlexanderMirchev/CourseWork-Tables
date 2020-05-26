#include "CellFactory.h"

#include "Validation.h"

#include "DoubleCell.h"
#include "IntegerCell.h"
#include "FormulaCell.h"
#include "ReferenceCell.h"
#include "StringCell.h"
#include <iostream>

std::shared_ptr<Cell> CellFactory::make(const std::string &input, const Table &table)
{
    const std::string str = trim(input);
    if (str.empty())
    {
        return std::shared_ptr<Cell>(nullptr);
    }
    if (validation::isValidFormula(str))
    {
        return createFormula(str.substr(1), table);
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

std::shared_ptr<Cell> CellFactory::createFormula(
    const std::string &str, const Table &table)
{
    std::cout << str << std::endl;
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
                        str, createFormula(str.substr(0, iter), table),
                        createFormula(str.substr(iter + 1), table),
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
                str, createFormula(str.substr(0, indexOfOperation), table),
                createFormula(str.substr(indexOfOperation + 1), table),
                str[indexOfOperation]));
    }
    else
    {
        return make(str, table);
    }
}

std::shared_ptr<Cell> CellFactory::createReference(
    const std::string &str, const Table &table)
{
    size_t posOfC = str.find('C');
    int rowNum = std::stoi(str.substr(1, posOfC));
    int colNum = std::stoi(str.substr(posOfC + 1));
    // std::cout << rowNum << "," << colNum << std::endl;

    return table[rowNum - 1][colNum - 1];
}

std::string CellFactory::trim(const std::string & str)
{
    const size_t firstNotSpace = str.find_first_not_of(' ');
    const size_t lastNotSpace = str.find_last_not_of(' ');
    if(firstNotSpace == std::string::npos) {
        return std::string();
    }
    else {
        return str.substr(firstNotSpace, lastNotSpace - firstNotSpace + 1);
    }
}