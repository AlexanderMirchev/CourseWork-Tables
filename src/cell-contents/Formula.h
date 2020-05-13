#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <functional>
#include "CellContent.h"

class Formula: public CellContent
{
private:
    int value;
    int minimalWidth;

    CellContent* firstArgument;
    CellContent* secondArgument;
    char operation;
public:
    Formula(const std::string&);
    ~Formula();

    int getMinimalWidth() const override;

    void printValue() const override;

    double getDoubleValue() const override;
private:
    using Operation = std::function<double(double, double)>;
    static const Operation& resolveOperation(const char&);
};
#endif
