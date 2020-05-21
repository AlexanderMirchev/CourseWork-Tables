#include "StringCell.h"
#include <iostream>

StringCell::StringCell(const std::string &str) : Cell(str) {std::cout << "string cell made"<<std::endl;}

double StringCell::getDoubleValue() const
{
    return 0;
}