#include "Session.h"
#include <iostream>

#include "exceptions/Exceptions.cpp"
#include "utilities/Validation.h"
#include "cells/ReferenceValue.h"

void Session::execute(const char *commandLabel,
                      const std::function<void()> &commandBody) const
{
    try
    {
        commandBody();
        std::cout << commandLabel << " successful.\n";
    }
    catch (const CustomException &e)
    {
        std::cout << commandLabel << " unsuccessful.\nCause: "
                  << e.what() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << commandLabel << " unsuccessful.\nCause: "
                  << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << commandLabel << " unsuccessful.\nUnknown cause.\n";
    }
}
void Session::execute(const char *commandLabel,
                      const std::function<void()> &commandBody)
{
    std::as_const(*this).execute(commandLabel, commandBody);
}

void Session::open(const std::string &str)
{
    execute("Open", [this, str]() -> void {
        Table newTable;
        this->fileController.open(str, newTable);
        this->tableController.setTable(newTable);
    });
}

void Session::close()
{
    execute("Close", [this]() -> void {
        this->fileController.close();
        this->tableController.removeTable();
    });
}

void Session::save() const
{
    execute("Save", [this]() -> void {
        this->fileController.save(
            this->tableController.getTable());
    });
}

void Session::saveas(const std::string &str)
{
    execute("Save as", [this, str]() -> void {
        this->fileController.saveas(
            str, this->tableController.getTable());
    });
}

void Session::print() const
{
    execute("Print", [this]() -> void {
        this->tableController.printTable();
    });
}
void Session::edit(const std::string &str)
{
    execute("Edit", [this, str]() -> void {
        if (validation::isValidReference(str))
        {
            const std::pair<int, int> reference =
                ReferenceValue::parseFromString(str);

            if (this->tableController
                        .getTable()[reference.first][reference.second] != nullptr &&
                !this->tableController
                     .getTable()[reference.first][reference.second]
                     ->getBaseValue()
                     .empty())
            {
                std::cout << "Current value: " << this->tableController.getTable()[reference.first][reference.second]->getBaseValue();
            }
            else
            {
                std::cout << "Cell is empty";
            }

            bool haveOpenDialogue = true;
            while (haveOpenDialogue)
            {
                std::cout << std::endl
                          << "Do you want to change it? (y/n) ";
                char answer;
                std::cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    std::cout << "New Value: ";
                    std::string newValue;
                    std::cin.ignore();
                    std::getline(std::cin, newValue);
                    this->tableController.editCell(
                        reference.first, reference.second, newValue);
                    haveOpenDialogue = false;
                }
                else if (answer == 'N' || answer == 'n')
                {
                    haveOpenDialogue = false;
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else
        {
            throw InvalidReference();
        }
    });
}