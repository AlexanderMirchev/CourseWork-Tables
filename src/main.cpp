#include "cell-contents/CellContentFactory.h"
#include "cell-contents/CellContent.h"

#include <iostream>

int main()
{
    CellContent* content = CellContentFactory::make("\"kur\"");

    // double number = std::stoi("10.3.3.3.3");
    // std::cout << number << std::endl;
    return 0;
}