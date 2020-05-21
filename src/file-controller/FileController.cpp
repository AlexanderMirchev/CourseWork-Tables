#include "FileController.h"

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
    }
    setSource(filename);
    fetch(table);
}
void FileController::close()
{
    if (serializer == nullptr)
    {
    }
    delete serializer;
    serializer = nullptr;
}
void FileController::save(const Table &table) const
{
    if (serializer == nullptr)
    {
    }
    serializer->serializeTable(table);
}
void FileController::saveas(const std::string &newFileName, const Table &table)
{
    if (serializer == nullptr)
    {
    }
    close();
    setSource(newFileName);
    save(table);
}

void FileController::setSource(const std::string &filename)
{
    if (serializer != nullptr)
    {
    }
    serializer = new TableSerializer(filename);
}
void FileController::fetch(Table &table) const
{
    if (serializer == nullptr)
    {
    }
    serializer->deserializeTable(table);
}