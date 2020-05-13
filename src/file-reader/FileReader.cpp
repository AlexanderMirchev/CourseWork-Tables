#include "FileReader.h"

#include <fstream>
#include "../CellFactory.h"

FileReader::FileReader(const std::string &filename) : filename{filename} {}

void FileReader::serializeTable(Table &table) const
{
    std::ifstream file;
    file.open(this->filename);

    if(file.is_open()) {
        std::string line;
        int rowIndex = 0;
        while (std::getline(file, line))
        {
            int symbolIterator = 0;
            std::string word;
            while (symbolIterator < line.size())
            {
                if(line[symbolIterator] == ',') {
                    table[rowIndex].push_back(CellFactory::make(word));
                    word.clear();
                }
                else
                {
                    word.push_back(line[symbolIterator]);
                }
            }
            table[rowIndex++].push_back(CellFactory::make(word));
        }    
    }
}

void FileReader::deserializeTable(const Table &) const
{
}