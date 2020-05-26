#ifndef DOUBLECELL_H
#define DOUBLECELL_H

#include "Cell.h"

class DoubleCell: public Cell
{
private:
    double value;

public:
    DoubleCell(const std::string&);

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table&) override;
};
#endif
