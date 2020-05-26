#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include "TableSerializer.h"
#include "../table/Table.h"

/*
    Controller class for interraction with files
*/
class FileController
{
private:
    TableSerializer *serializer;

public:
    FileController();
    ~FileController();

    /*
        Opens file and deserializes table form it
    */
    void open(const std::string &filename, Table &);

    /*
        Closes file 
    */
    void close();

    /*
        Saves table to current open file
    */
    void save(const Table &) const;

    /*
        Opens new file(newFileName) and serializes table
    */
    void saveas(const std::string &newFileName, const Table &);

private:
    /*
        Sets current source file to be file with filename
    */
    void setSource(const std::string &filename);

    /*
        Deserializes table from already set source file
    */
    void fetch(Table &) const;
};
#endif
