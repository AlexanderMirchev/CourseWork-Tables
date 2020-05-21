#ifndef SESSION_H
#define SESSION_H

#include "file-controller/FileController.h"
#include "table-controller/TableController.h"
#include "console/Console.h"

class Session
{
private:
    std::unique_ptr<FileController> fileController;
    std::unique_ptr<TableController> tableController;

public:
    Session() = default;
    ~Session() = default;

    void start();
};
#endif
