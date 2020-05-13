#ifndef INTEGERCELL_H
#define INTEGERCELL_H

#include "Cell.h"

class IntegerCell: public Cell
{
private:
    int value;
public:
    void print(const int cellWidth) const override;

    double getDoubleValue() override;
};
#endif
