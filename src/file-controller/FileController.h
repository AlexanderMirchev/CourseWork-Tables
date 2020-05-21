#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include "TableSerializer.h"
#include "../table/Table.h"

class FileController
{
private:
    TableSerializer *serializer;

public:
    FileController();
    ~FileController();

    void open(const std::string &filename, Table &);
    void close();
    void save(const Table &) const;
    void saveas(const std::string &newFileName, const Table &);

private:
    void setSource(const std::string &filename);
    void fetch(Table &) const;
};
#endif
