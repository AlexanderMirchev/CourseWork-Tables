#ifndef UTILITY_H
#define UTILITY_H

#include <string>

/*
    Namespace for utility methods
*/
namespace utility
{
    /*
        Removes all leading and trailing spaces from string
    */
    std::string trim(const std::string &);

    /*
        Return
    */
    size_t getNumberOfCharactersInDouble(const double &);
} // namespace utility
#endif