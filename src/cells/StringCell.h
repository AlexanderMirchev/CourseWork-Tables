#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{
private:
    std::string value;
    double formulaValue;

public:
    StringCell(const std::string &);
    ~StringCell() = default;

    void print() const override;
    double getDoubleValue() const override;
};
#endif
