#include "FormulaValue.h"
#include <math.h>
#include <iostream>
#include "../utilities/Utility.h"

FormulaValue::FormulaValue(const std::shared_ptr<CellValue> &firstPart,
                           const std::shared_ptr<CellValue> &secondPart,
                           const char &operation)
    : firstPart{firstPart}, secondPart{secondPart}, operation{operation} {}
double FormulaValue::getDoubleValue() const { return value.value(); }
void FormulaValue::calculateValue(Table &table)
{
    if (!isCalculated)
    {
        this->firstPart->calculateValue(table);
        this->secondPart->calculateValue(table);
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
                if (this->secondPart->getDoubleValue() == 0)
                {
                    this->value = std::nullopt;
                }
                else
                {
                    this->value.value() /= this->secondPart->getDoubleValue();
                }
            }
            else
            {
                value = pow(this->value.value(), this->secondPart->getDoubleValue());
            }
        }
        catch (const std::exception &e)
        {
            this->value = std::nullopt;
        }
        if (this->value.has_value())
        {
            this->minimalWidth = utility::getNumberOfCharactersInDouble(this->value.value());
        }
        else
        {
            /*
                Size of ERROR
            */
            // std::cout << "ERROR" << std::endl;
            this->minimalWidth = 5;
        }
        isCalculated = true;
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
void FormulaValue::setDependantCell(
    const std::shared_ptr<Cell> &cell, Table &table) const
{
    this->firstPart->setDependantCell(cell, table);
    this->secondPart->setDependantCell(cell, table);
}

void FormulaValue::removeDependantCell(
    const std::shared_ptr<Cell> &cell, Table &table) const
{
    this->firstPart->removeDependantCell(cell, table);
    this->secondPart->removeDependantCell(cell, table);
}
void FormulaValue::nullify()
{
    this->isCalculated = false;
    this->value = std::nullopt;
    this->firstPart->nullify();
    this->secondPart->nullify();
}
size_t FormulaValue::getMinimalWidth() const { return minimalWidth; }