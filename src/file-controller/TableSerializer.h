#ifndef TABLESERIALIZER_H
#define TABLESERIALIZER_H

#include <string>

#include "../table/Table.h"

/*
    Class for serialization/deserialization
*/
class TableSerializer
{
private:
    std::string filename;

public:
    TableSerializer(const std::string &filename);

    /*
        Throws CannotCreateTable
    */
    void deserializeTable(Table &) const;

    void serializeTable(const Table &) const;
};
#endif
