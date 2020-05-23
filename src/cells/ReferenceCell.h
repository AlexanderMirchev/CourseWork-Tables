#ifndef REFERENCECELL_H
#define REFERENCECELL_H

#include "Cell.h"
#include <utility>

class ReferenceCell : public Cell
{
private:
    int row;
    int col;

public:
    ReferenceCell(const std::string&);

    double getDoubleValue() const;

    static std::pair<int, int> parseFromString(const std::string &);
};
#endif
