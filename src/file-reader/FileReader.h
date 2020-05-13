#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

#include "../Table.h"

class FileReader
{
private:
    std::string filename;

public:
    FileReader(const std::string &filename);

    void serializeTable(Table &) const;

    void deserializeTable(const Table &) const;
};
#endif
