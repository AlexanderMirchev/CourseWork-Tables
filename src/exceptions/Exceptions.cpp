#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <cstring>

/**
 * Custom exception class
*/
struct CustomException : public std::exception
{
    virtual const char *what() const noexcept = 0;
};

/**
 * Exception for notifying about unsupported data types
*/
class UnknownDataType : public CustomException
{
private:
    char message[80];

public:
    UnknownDataType() = delete;
    UnknownDataType(
        const size_t &row, const size_t &col, const char *value)
    {
        sprintf(
            message, "Row %d, Col %d, %s is of unknown type.",
            row + 1, col + 1, value);
    }
    const char *what() const noexcept override
    {
        return this->message;
    }
};

/**
 * Exception for when an error has occured while creating table
*/
class CannotCreateTable : public CustomException
{
private:
    char message[180];

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

/**
 * Exception for notifying that a source cannot be set if is present
*/
struct SourceAlreadyExists : public CustomException
{
    const char *what() const throw() override
    {
        return "There is an existing source already.";
    }
};

/**
 * Exception for notifying missing source
*/
struct NoSource : public CustomException
{
    const char *what() const throw() override
    {
        return "No source could be found.";
    }
};

/**
 * Exception for when a reference does not have valid syntax
*/
struct InvalidReference : public CustomException
{
    const char *what() const throw() override
    {
        return "Reference is invalid.";
    }
};

/**
 * Exception for notifying the creation of circular dependency between cells
*/
struct CreatedCircularDependency : public CustomException
{
    const char *what() const throw() override
    {
        return "Formula has created circular dependency.";
    }
};
#endif
