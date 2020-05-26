#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "CellValue.h"
#include <optional>

class StringValue : public CellValue
{
private:
    std::string value;
    std::optional<double> formulaValue;

public:
    StringValue(const std::string &);
    ~StringValue() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table &) override;
};
#endif
