#ifndef SESSION_H
#define SESSION_H

#include "file-controller/FileController.h"
#include "table-controller/TableController.h"
#include "console/Console.h"

class Session
{
private:
    FileController fileController;
    TableController tableController;

public:
    Session() = default;
    ~Session() = default;

    void start();
private:
    static const std::string HELP_MESSAGE;
};
#endif
