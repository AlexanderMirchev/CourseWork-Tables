#ifndef REFERENCECELL_H
#define REFERENCECELL_H

#include "Cell.h"
#include <optional>
#include <utility>

class ReferenceCell : public Cell
{
private:
    std::optional<double> value;
    int row;
    int col;

public:
    ReferenceCell(const std::string&);

    double getDoubleValue() const;
    void calculateValue(const Table&) override;

    static std::pair<int, int> parseFromString(const std::string &);
};
#endif
