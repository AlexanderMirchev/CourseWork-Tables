#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

namespace validation
{
    bool isValidInteger(const std::string&);
    bool isValidDouble(const std::string&);
    bool isValidReference(const std::string&);
    bool isValidString(const std::string&);
    bool isValidFormula(const std::string&);

    bool isNumber(const char&);
    bool isOperation(const char&);
    bool isValidFirstCharInNumber(const char&);
}
#endif
