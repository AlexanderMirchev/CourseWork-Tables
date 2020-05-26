#ifndef CELLVALUE_H
#define CELLVALUE_H

#include "../table/Table.h"

class Table;
class CellValue
{
public:
    virtual ~CellValue() = default;

    virtual void print() const = 0;
    virtual double getDoubleValue() const = 0;
    virtual void calculateValue(const Table &) = 0;
};
#endif
