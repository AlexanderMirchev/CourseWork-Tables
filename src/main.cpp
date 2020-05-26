#include "Session.h"
#include "cells/CellFactory.h"
#include <iostream>

int main()
{
    // CellContent* content = CellContentFactory::make("\"kur\"");

    // // double number = std::stoi("10.3.3.3.3");
    // // std::cout << number << std::endl;
    
    Session session;
    session.start();

    // std::string trimmed = CellFactory::trim("    kurvi belo23 ");
    // std::cout << "'" << trimmed <<"'\n";
    return 0;
}