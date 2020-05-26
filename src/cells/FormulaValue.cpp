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
        try
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
            /* code */
        }
        catch (const std::exception &e)
        {
            this->value = std::nullopt;
        }
    }
}
void FormulaValue::print() const
{
    if (this->value.has_value())
    {
        std::cout << value.value();
    }
    else
    {
        std::cout << "ERROR";
    }
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