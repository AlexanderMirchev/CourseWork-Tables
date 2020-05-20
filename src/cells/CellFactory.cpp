#include "CellFactory.h"

#include "Validation.h"

#include "DoubleCell.h"
#include "IntegerCell.h"
#include "FormulaCell.h"
#include "StringCell.h"

std::shared_ptr<Cell> CellFactory::make(const std::string &str, const Table &table)
{
    if (validation::isValidFormula(str))
    {
        return createFormula(str, table);
    }
    if (validation::isValidString(str))
    {
        return std::shared_ptr<Cell>(new StringCell(str));
    }
    if (validation::isValidReference(str))
    {
        return createReference(str, table);
    }
    if(validation::isValidInteger(str)) {
        return std::shared_ptr<Cell>(new IntegerCell(str));
    }
    if(validation::isValidDouble(str)) {
        return std::shared_ptr<Cell>(new IntegerCell(str));
    }
}

std::shared_ptr<Cell> CellFactory::createFormula(
    const std::string &str, const Table &table)
{
    std::vector<std::shared_ptr<Cell>> contents;
    std::vector<char> operations;

    std::string tempWord;
    unsigned int iter = 1;
    while (iter < str.size())
    {
        if (validation::isOperation(str[iter]))
        {
            contents.push_back(CellFactory::make(tempWord, table));
            operations.push_back(str[iter]);
            tempWord.clear();
        }
        else if (str[iter] != ' ')
        {
            tempWord.push_back(str[iter]);
        }
        ++iter;
    }
    contents.push_back(CellFactory::make(tempWord, table));
    return std::shared_ptr<Cell>(
        new FormulaCell(str, std::move(contents), std::move(operations)));
}

std::shared_ptr<Cell> CellFactory::createReference(
    const std::string &str, const Table &table)
{
    size_t posOfC = str.find('C');
    int rowNum = std::stoi(str.substr(1, posOfC - 1));
    int colNum = std::stoi(str.substr(posOfC + 1));

    return table[rowNum][colNum];
}