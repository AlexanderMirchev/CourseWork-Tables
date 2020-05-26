#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "CellValue.h"
#include <optional>

class StringValue : public CellValue
{
private:
    std::string value;
    double formulaValue;

public:
    StringValue(const std::string &);
    ~StringValue() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
};
#endif
