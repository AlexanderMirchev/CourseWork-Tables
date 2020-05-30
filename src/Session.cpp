#include "Session.h"
#include <iostream>

void Session::start()
{
    bool shouldContinue = true;
    while (shouldContinue)
    {
        Console::Command command = Console::readCommand();
        bool inputIsValid = true;
        if (command.second.has_value())
        {
            if (command.first == "open")
            {
                open(command.second.value());
            }
            else if (command.first == "saveas")
            {
                saveas(command.second.value());
            }
            else if (command.first == "edit")
            {
                edit(command.second.value());
            }
            else
            {
                inputIsValid = false;
            }
        }
        else
        {
            if (command.first == "exit")
            {
                shouldContinue = false;
            }
            else if (command.first == "help")
            {
                std::cout << HELP_MESSAGE;
            }
            else if (command.first == "close")
            {
                close();
            }
            else if (command.first == "save")
            {
                save();
            }
            else if (command.first == "print")
            {
                print();
            }
            else
            {
                inputIsValid = false;
            }
        }
        if (!inputIsValid)
        {
            std::cout << "Invalid input.\n";
        }
    }
}
const std::string Session::HELP_MESSAGE =
    std::string("Help:\n open <filename> - opens file to read from\n ") +
    std::string("close - closes opened file\n save - saves current changes to file\n ") +
    std::string("saveas <filename> - saves current changes to given file\n ") +
    std::string("exit - exits the program\n print - prints opened table\n edit R<M>C<N> - edits the cell at row M and col N\n");