#include "table/Table.h"
#include "file-controller/TableSerializer.h"
#include <iostream>

int main()
{
    // CellContent* content = CellContentFactory::make("\"kur\"");

    // // double number = std::stoi("10.3.3.3.3");
    // // std::cout << number << std::endl;
    Table table;
    TableSerializer ts("data.txt");

    ts.deserializeTable(table);
    table.print();
    TableSerializer ts2("data2.txt");

    ts2.serializeTable(table);    
    return 0;
}