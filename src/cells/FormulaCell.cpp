#include "FormulaCell.h"
#include <math.h>

FormulaCell::FormulaCell(const std::string &str,
                         const std::shared_ptr<Cell> &firstPart,
                         const std::shared_ptr<Cell> &secondPart, const char &operation)
    : Cell(str), firstPart{firstPart}, secondPart{secondPart}, operation{operation} {}
double FormulaCell::getDoubleValue() const { return value.value(); }
void FormulaCell::calculateValue(const Table &table)
{
    this->firstPart->calculateValue(table);
    this->secondPart->calculateValue(table);
    if (!this->value.has_value())
    {
        this->value = this->firstPart->getDoubleValue();
        if (this->operation == '+')
        {
            this->value.value() += this->secondPart->getDoubleValue();
        }
        else if (this->operation == '-')
        {
            this->value.value() -= this->secondPart->getDoubleValue();
        }
        else if (this->operation == '*')
        {
            this->value.value() *= this->secondPart->getDoubleValue();
        }
        else if (this->operation == '/')
        {
            this->value.value() /= this->secondPart->getDoubleValue();
        }
        else
        {
            pow(this->value.value(), this->secondPart->getDoubleValue());
        }
    }
}