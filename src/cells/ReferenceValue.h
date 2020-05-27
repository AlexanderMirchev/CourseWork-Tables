#ifndef REFERENCEVALUE_H
#define REFERENCEVALUE_H

#include "CellValue.h"
#include <optional>
#include <utility>

class ReferenceValue : public CellValue
{
private:
    std::optional<double> value;
    size_t row;
    size_t col;

public:
    ReferenceValue(const std::string &);

    void print() const override;
    double getDoubleValue() const override;
    void calculateValue(const Table &) override;
    void setDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void removeDependantCell(const std::shared_ptr<Cell> &, Table &) const override;
    void nullify() override;

    static std::pair<size_t, size_t> parseFromString(const std::string &);
};
#endif
