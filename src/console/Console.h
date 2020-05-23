#ifndef CONSOLE_H
#define CONSOLE_H

#include <optional>
#include <utility>

class Console
{
public:
    using Command = std::pair<std::string, std::optional<std::string>>;
    static Command readCommand();
};
#endif
