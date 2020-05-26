#include "Session.h"
#include <iostream>
#include "utilities/Validation.h"
#include "cells/ReferenceValue.h"

void Session::start()
{
    bool shouldContinue = true;
    while (shouldContinue)
    {
        Console::Command command = Console::readCommand();
        if (command.second.has_value())
        {
            if (command.first == "open")
            {
                Table newTable;
                this->fileController.open(command.second.value(), newTable);
                this->tableController.setTable(newTable);
            }
            else if (command.first == "saveas")
            {
                this->fileController.saveas(
                    command.second.value(), this->tableController.getTable());
            }
            else if (command.first == "edit")
            {
                if (validation::isValidReference(command.second.value()))
                {
                    const std::pair<int, int> reference =
                        ReferenceValue::parseFromString(command.second.value());
                    std::cout << reference.first <<","<<reference.second << std::endl;
                    std::cout << "Current value: ";
                    if (this->tableController
                            .getTable()[reference.first][reference.second] != nullptr)
                    {
                        std::cout << this->tableController
                                         .getTable()[reference.first][reference.second]
                                         ->getBaseValue();
                    }
                    std::cout << std::endl;
                    std::cout << "New Value: ";
                    std::string newValue;
                    std::getline(std::cin, newValue);
                    this->tableController.editCell(reference.first, reference.second, newValue);
                }
                else
                {
                    std::cout << "Invalid reference";
                }
            }
            else
            {
                std::cout << "Invalid input\n";
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
                this->fileController.close();
                this->tableController.removeTable();
            }
            else if (command.first == "save")
            {
                this->fileController.save(this->tableController.getTable());
            }
            else if (command.first == "print")
            {
                this->tableController.printTable();
            }
            else
            {
                std::cout << "Invalid input\n";
            }
        }
    }
}
const std::string Session::HELP_MESSAGE =
    std::string("Help:\n open <filename> - opens file to read from\n ") +
    std::string("close - closes opened file\n save - saves current changes to file\n ") +
    std::string("saveas <filename> - saves current changes to given file\n ") +
    std::string("exit - exits the program\n print - prints opened table\n edit R<M>C<N> - edits the cell at row M and col N\n");