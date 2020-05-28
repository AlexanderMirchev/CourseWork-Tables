#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "CellValue.h"
#include <optional>

class StringValue : public CellValue
{
private:
    std::string value;
    double formulaValue;
    size_t minimalWidth;

public:
    StringValue(const std::string &);
    ~StringValue() = default;

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;
    size_t getMinimalWidth()const override;
};
#endif
