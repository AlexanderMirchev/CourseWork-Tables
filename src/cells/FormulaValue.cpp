#include "FormulaValue.h"
#include <math.h>
#include <iostream>

FormulaValue::FormulaValue(const std::shared_ptr<CellValue> &firstPart,
                           const std::shared_ptr<CellValue> &secondPart,
                           const char &operation)
    : firstPart{firstPart}, secondPart{secondPart}, operation{operation} {}
double FormulaValue::getDoubleValue() const { return value.value(); }
void FormulaValue::calculateValue(const Table &table)
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
            value = pow(this->value.value(), this->secondPart->getDoubleValue());
        }
    }
}
void FormulaValue::print() const
{
    std::cout << this->value.value();
}
void FormulaValue::setDependantCell(const std::shared_ptr<Cell> &cell, Table &table) const
{
    this->firstPart->setDependantCell(cell, table);
    this->secondPart->setDependantCell(cell, table);
}
void FormulaValue::nullify()
{
    this->value = std::nullopt;
    this->firstPart->nullify();
    this->secondPart->nullify();
}