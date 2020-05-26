#include "ReferenceCell.h"

ReferenceCell::ReferenceCell(const std::string &str) : Cell(str)
{
    const std::pair<int, int> coordinates = parseFromString(str);
    row = coordinates.first;
    col = coordinates.second;
}

double ReferenceCell::getDoubleValue() const
{
    return this->value.value();
}

void ReferenceCell::calculateValue(const Table &table)
{
    if (!this->value.has_value())
    {
        this->value = table[this->row][this->col]->getDoubleValue();
    } 
}

std::pair<int, int> ReferenceCell::parseFromString(const std::string &str)
{
    const size_t posOfC = str.find('C');
    const int rowNum = std::stoi(str.substr(1, posOfC));
    const int colNum = std::stoi(str.substr(posOfC + 1));
    return std::pair<int, int>(rowNum - 1, colNum - 1);
}