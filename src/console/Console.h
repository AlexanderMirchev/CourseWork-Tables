#ifndef CONSOLE_H
#define CONSOLE_H

#include <optional>
#include <utility>

/**
 * Class for insertion of commands from console
*/
class Console
{
public:
    /**
     * Alias for command(could have 1 word or 2 words)
    */
    using Command = std::pair<std::string, std::optional<std::string>>;
    
    /**
     * Method for producing pair of words from user input
    */
    static Command readCommand();
};
#endif
