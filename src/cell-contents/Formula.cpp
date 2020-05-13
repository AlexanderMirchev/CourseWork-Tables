#include "Formula.h"
#include <cmath>

Formula::Formula(const std::string &str) {
    for (const char& c: str)
    {
        /* code */
    }
    
}
Formula::~Formula()
{
    if (this->firstArgument != nullptr)
    {
        delete this->firstArgument;
    }
    if (this->secondArgument != nullptr)
    {
        delete this->secondArgument;
    }
}

int Formula::getMinimalWidth() const
{
    return this->minimalWidth;
}

void Formula::printValue() const
{
}

double Formula::getDoubleValue() const
{
    return this->value;
}

const Formula::Operation &Formula::resolveOperation(const char &c)
{
    if (c == '+')
    {
        return [](double value1, double value2) { return value1 + value2; };
    }
    if (c == '-')
    {
        return [](double value1, double value2) { return value1 - value2; };
    }
    if (c == '*')
    {
        return [](double value1, double value2) { return value1 * value2; };
    }
    if (c == '/')
    {
        return [](double value1, double value2) { return value1 / value2; };
    }
    if (c == '^')
    {
        return [](double value1, double value2) { return pow(value1, value2); };
    }
}