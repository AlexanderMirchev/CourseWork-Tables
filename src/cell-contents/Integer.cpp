#include "Integer.h"

Integer::Integer(const std::string & str):minimalWidth{str.size()} {
    this->value = std::stoi(str);
}

int Integer::getMinimalWidth() const {
    return this->minimalWidth;
}

void Integer::printValue() const {

}

double Integer::getDoubleValue() const {
    return this->value;
}