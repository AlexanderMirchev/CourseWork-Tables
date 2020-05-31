#ifndef TABLESERIALIZER_H
#define TABLESERIALIZER_H

#include <string>

#include "../table/Table.h"

/**
 * Class for serialization/deserialization of tables
*/
class TableSerializer
{
private:
    std::string filename;

public:
    TableSerializer(const std::string &filename);

    /**
     * Deserializes table from file
     * 
     * Throws CannotCreateTable
    */
    void deserializeTable(Table &) const;

    /**
     * Serializes table to file
    */
    void serializeTable(const Table &) const;
};
#endif
