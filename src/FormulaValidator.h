#ifndef FORMULAVALIDATOR_H
#define FORMULAVALIDATOR_H

#include <string>

class FormulaValidator
{
public:
    static bool isValidFormula(const std::string &);
private:
    static bool isValidReferrenceToCell(const std::string &);
};
#endif
