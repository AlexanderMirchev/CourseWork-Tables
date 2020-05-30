#include "TableSerializer.h"

#include <fstream>
#include "../cells/CellFactory.h"
#include "../exceptions/Exceptions.cpp"

TableSerializer::TableSerializer(const std::string &filename) : filename{filename} {}

void TableSerializer::deserializeTable(Table &table) const
{
    std::ifstream file;
    file.open(this->filename);
    if (file.is_open())
    {
        std::string line;
        size_t rowIndex = 0;
        
        while (std::getline(file, line))
        {
            unsigned int symbolIterator = 0;
            size_t wordNumber = 0;
            std::string word;
            while (symbolIterator <= line.size())
            {
                if (line[symbolIterator] == ',' || symbolIterator == line.size())
                {
                    try
                    {
                        table[rowIndex].push_back(
                            CellFactory::make(word, rowIndex, wordNumber++));
                    }
                    catch (const UnknownDataType &e)
                    {
                        throw CannotCreateTable(filename.c_str(), e);
                    }
                    word.clear();
                }
                else
                {
                    word.push_back(line[symbolIterator]);
                }
                symbolIterator++;
            }
            rowIndex++;
        }
    }
}

void TableSerializer::serializeTable(const Table &table) const
{
    std::ofstream file;
    file.open(this->filename, std::ios::trunc);

    for (size_t i = 0; i < table.numberOfRows(); i++)
    {
        for (size_t j = 0; j < table[i].size(); j++)
        {
            if (table[i][j] != nullptr)
            {
                file << table[i][j]->getBaseValue();
            }
            if (j != table[i].size() - 1)
            {
                file << ',';
            }
        }
        file << '\n';
    }
    file.close();
}