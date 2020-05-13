#ifndef CELL_H
#define CELL_H

#include <string>

class Cell
{
public:
    virtual void edit(const std::string& newValue) = 0;

    virtual void const print(const int cellWidth) = 0;

    virtual double getDoubleValue() = 0;
};
#endif
