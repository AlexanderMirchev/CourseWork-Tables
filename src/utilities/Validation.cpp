#include "Validation.h"
using namespace validation;

bool validation::isValidInteger(const std::string &str)
{
    if (isValidFirstCharInNumber(str.front()))
    {
        if (!isNumber(str.front()) && str.size() == 1)
        {
            return false;
        }
        unsigned int iter = 1;
        while (iter < str.size())
        {
            if (!isNumber(str[iter]))
            {
                return false;
            }
            ++iter;
        }
        return true;
    }
    return false;
}

bool validation::isValidDouble(const std::string &str)
{
    if (isValidFirstCharInNumber(str.front()))
    {
        if (!isNumber(str.front()) && str.size() == 1)
        {
            return false;
        }
        unsigned int iter = 1;
        int numberOfPoints = 0;
        while (iter < str.size())
        {
            if (numberOfPoints >= 2)
            {
                return false;
            }
            if (str[iter] == '.')
            {
                ++numberOfPoints;
            }
            else if (!isNumber(str[iter]))
            {
                return false;
            }
            
            ++iter;
        }
        return true;
    }
    return false;
}

bool validation::isValidString(const std::string &str)
{
    return str.front() == '"' && str.back() == '"' && str.size() > 1;
}

bool validation::isValidReference(const std::string &str)
{
    if (str.front() == 'R')
    {
        unsigned int iter = 1;
        bool canBeC = false;
        while (iter < str.size())
        {
            if (!isNumber(str[iter]))
            {
                if (str[iter] == 'C' && canBeC)
                {
                    canBeC = false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (iter == 1)
                    canBeC = true;
            }
            ++iter;
        }
        return true;
    }
    return false;
}
bool validation::isValidFormula(const std::string &str)
{
    return str.front() == '=' && str.size() > 1;
}
bool validation::isNumber(const char &c)
{
    return c >= '0' && c <= '9';
}
bool validation::isOperation(const char &c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
bool validation::isValidFirstCharInNumber(const char &c)
{
    return isNumber(c) || c == '+' || c == '-';
}