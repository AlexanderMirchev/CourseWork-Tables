#ifndef SESSION_H
#define SESSION_H

#include "file-controller/FileController.h"
#include "table-controller/TableController.h"
#include "console/Console.h"
#include <functional>

/**
 * Class that connects controllers and console 
*/
class Session
{
private:
    FileController fileController;
    TableController tableController;

public:
    Session() = default;
    ~Session() = default;

    /**
     * Start reading user input and executing commands if available
    */
    void start();

private:
    void open(const std::string &);
    void close();
    void save() const;
    void saveas(const std::string &);
    void print() const;
    void edit(const std::string &);

    /**
     * Executing and absorbing exceptions
    */
    void execute(const char *commandLabel,
                 const std::function<void()> &commandBody);
    void execute(const char *commandLabel,
                 const std::function<void()> &commandBody) const;

    static const std::string HELP_MESSAGE;
};
#endif
