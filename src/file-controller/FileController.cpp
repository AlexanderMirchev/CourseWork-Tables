#include "FileController.h"
#include "../exceptions/Exceptions.cpp"

FileController::FileController() : serializer{nullptr} {}
FileController::~FileController()
{
    if (serializer != nullptr)
    {
        delete serializer;
    }
}

void FileController::open(const std::string &filename, Table &table)
{
    if (serializer != nullptr)
    {
        throw SourceAlreadyExists();
    }
    setSource(filename);
    try
    {
        fetch(table);
    }
    catch (const CannotCreateTable &e)
    {
        this->serializer = nullptr;
        throw e;
    }
    table.makeAllCalculations();
}
void FileController::close()
{
    if (serializer == nullptr)
    {
        throw NoSource();
    }
    delete serializer;
    serializer = nullptr;
}
void FileController::save(const Table &table) const
{
    if (serializer == nullptr)
    {
        throw NoSource();
    }
    serializer->serializeTable(table);
}
void FileController::saveas(const std::string &newFileName, const Table &table)
{
    if (serializer == nullptr)
    {
        throw NoSource();
    }
    close();
    setSource(newFileName);
    save(table);
}

void FileController::setSource(const std::string &filename)
{
    if (serializer != nullptr)
    {
        throw SourceAlreadyExists();
    }
    serializer = new TableSerializer(filename);
}
void FileController::fetch(Table &table) const
{
    if (serializer == nullptr)
    {
        throw NoSource();
    }
    serializer->deserializeTable(table);
}