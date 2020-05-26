#ifndef INTEGERCELL_H
#define INTEGERCELL_H

#include "Cell.h"

class IntegerCell: public Cell
{
private:
    int value;
    
public:
    IntegerCell(const std::string&);
    ~IntegerCell() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table&) override;
};
#endif
