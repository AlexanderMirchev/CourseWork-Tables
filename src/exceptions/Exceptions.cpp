#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <cstring>

struct CustomException : public std::exception
{
    virtual const char *what() const noexcept = 0;
};

class UnknownDataType : public CustomException
{
private:
    char message[50];

public:
    UnknownDataType() = delete;
    UnknownDataType(
        const size_t &row, const size_t &col, const char *value)
    {
        sprintf(
            message, "Row %d, Col %d, %s is of unknown type.",
            row, col, value);
    }
    const char *what() const noexcept override
    {
        return this->message;
    }
};

class CannotCreateTable : public CustomException
{
private:
    char message[75];

public:
    CannotCreateTable() = delete;
    CannotCreateTable(const char *file, const UnknownDataType &e)
    {
        sprintf(
            message, "Error occured while creating table from %s:\n %s",
            file, e.what());
    }
    const char *what() const noexcept override
    {
        return this->message;
    }
};

struct SourceAlreadyExists : public CustomException
{
    const char *what() const throw() override
    {
        return "There is an existing source already.";
    }
};

struct NoSource : public CustomException
{
    const char *what() const throw() override
    {
        return "No source could be found.";
    }
};

struct InvalidReference : public CustomException
{
    const char *what() const throw() override
    {
        return "Reference is invalid.";
    }
};

#endif