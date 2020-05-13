#ifndef CHARACTERFLAGS_H
#define CHARACTERFLAGS_H

/*
    Namespace for boolean functions on char values
*/
namespace charFlags
{
    bool isNumber(const char&);
    bool isOperation(const char&);

    bool isValidFirstCharInNumber(const char&);
} // namespace charFlags


#endif