#include "Console.h"
#include <iostream>

void Console::start()
{
    bool shouldBeRunning = true;
    while (shouldBeRunning)
    {
        std::string command;
        std::getline(std::cin, command);

        unsigned int firstSpaceIndex = command.find(' ');
        if (firstSpaceIndex == std::string::npos)
        {
            if(command == "exit") return;
        }
    }
}