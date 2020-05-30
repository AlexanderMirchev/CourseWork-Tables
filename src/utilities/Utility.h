#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

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

    */
    size_t getNumberOfCharactersInDouble(const double &);

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