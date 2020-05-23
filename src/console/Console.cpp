#include "Console.h"
#include <iostream>

Console::Command Console::readCommand()
{
    std::string command;
    std::getline(std::cin, command);

    const size_t firstSpaceIndex = command.find(' ');
    if (firstSpaceIndex == std::string::npos ||
        firstSpaceIndex == command.size() - 1 ||
        firstSpaceIndex == 0)
    {
        return Command(command, std::nullopt);
    }
    else
    {
        return Command(command.substr(0, firstSpaceIndex),
                       command.substr(firstSpaceIndex + 1));
    }
}
