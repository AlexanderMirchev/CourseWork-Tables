#include "../cell-contents/CellContentFactory.h"

#include "Cell.h"
Cell::Cell(const std::string &str) : stringContent{str}
{
    content = CellContentFactory::make(str);
}
Cell::~Cell()
{
    if (content != nullptr)
    {
        delete content;
    }
}