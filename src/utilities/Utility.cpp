#include "Utility.h"
using namespace utility;

std::string utility::trim(const std::string &str)
{
    const size_t firstNotSpace = str.find_first_not_of(' ');
    const size_t lastNotSpace = str.find_last_not_of(' ');
    if (firstNotSpace == std::string::npos)
    {
        return std::string();
    }
    else
    {
        return str.substr(firstNotSpace, lastNotSpace - firstNotSpace + 1);
    }
}
