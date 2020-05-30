#include "Console.h"
#include <iostream>
#include "../utilities/Utility.h"

Console::Command Console::readCommand()
{
    std::string command;
    std::cout << "~ ";
    std::getline(std::cin, command);

    const size_t firstSpaceIndex = command.find(' ');
    if (firstSpaceIndex == std::string::npos ||
        firstSpaceIndex == command.size() - 1 ||
        firstSpaceIndex == 0)
    {
        return Command(utility::trim(command), std::nullopt);
    }
    else
    {
        return Command(utility::trim(command.substr(0, firstSpaceIndex)),
                       utility::trim(command.substr(firstSpaceIndex + 1)));
    }
}
