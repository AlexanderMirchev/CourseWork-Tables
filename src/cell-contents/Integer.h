#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include "CellContent.h"

class Integer: public CellContent
{
private:
    int value;
    int minimalWidth;
public:
    Integer() = delete;
    Integer(const std::string&);

    int getMinimalWidth() const override;

    void printValue() const override;

    double getDoubleValue() const override;
};
#endif
