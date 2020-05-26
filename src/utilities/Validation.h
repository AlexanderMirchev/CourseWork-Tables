#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

/*
    Namespace for validation methods
*/
namespace validation
{
    /*
        +/-/number - first character
        number - other characters
    */
    bool isValidInteger(const std::string&);
    
    /*
        +/-/number - first character
        number/'.' - other characters
        no more than 1 '.'
    */
    bool isValidDouble(const std::string&);

    /*
        R<positive integer>C<positive integer>
    */
    bool isValidReference(const std::string&);

    /*
        '"' - first and last characters
    */
    bool isValidString(const std::string&);

    /*
        '=' - first character
    */
    bool isValidFormula(const std::string&);

    bool isNumber(const char&);

    /*
        +,-,*,/,^
    */
    bool isOperation(const char&);

    /*
        +,-,number
    */
    bool isValidFirstCharInNumber(const char&);
}
#endif
