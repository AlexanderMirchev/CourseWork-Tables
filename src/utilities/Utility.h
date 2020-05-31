#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

/**
 * Utility namespace
*/
namespace utility
{
    /**
     * Removes all leading and trailing spaces from string
    */
    std::string trim(const std::string &);

    /**
     * Returns the number of characters in double value
     * (counts up to 6 characters after the decimal point)
    */
    size_t getNumberOfCharactersInDouble(const double &);

    /**
     * Adds unique element to array
    */
    template <class T>
    void uniquePushBack(std::vector<T> &list, const T &newObj)
    {
        for (const T &obj : list)
        {
            if (obj == newObj)
            {
                return;
            }
        }
        list.push_back(newObj);
    }

} // namespace utility
#endif