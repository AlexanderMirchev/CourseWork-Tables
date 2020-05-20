#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{
private:
    std::string value;
    double value;

public:
    StringCell(const std::string &);
    ~StringCell();

    void print() const override;
    double getDoubleValue() const override;
};
#endif
