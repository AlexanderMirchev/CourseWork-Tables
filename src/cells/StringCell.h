#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"
#include <optional>

class StringCell : public Cell
{
private:
    std::string value;
    std::optional<double> formulaValue;

public:
    StringCell(const std::string &);
    ~StringCell() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table &) override;
};
#endif
