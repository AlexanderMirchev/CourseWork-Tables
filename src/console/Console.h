#ifndef CONSOLE_H
#define CONSOLE_H

#include <optional>
#include <utility>

/*
    Class for insertion of commands from console
*/
class Console
{
public:
    /*
        A command representing first and possibly second word
    */
    using Command = std::pair<std::string, std::optional<std::string>>;
    /*
        Method for producing pair of words from user input
    */
    static Command readCommand();
};
#endif
