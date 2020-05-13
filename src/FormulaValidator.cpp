#include "FormulaValidator.h"

bool FormulaValidator::isValidFormula(const std::string & str) {
    if (str.front() == '=' && str.size() > 1)
    {
        for (size_t i = 1; i < str.size(); i++)
        {
            if (!isNumber(str[i]) && !isOperation(str[i]) && str[i] != 'R' && str[i] != 'C')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}