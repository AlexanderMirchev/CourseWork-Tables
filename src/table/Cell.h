#ifndef CELL_H
#define CELL_H

#include <string>
#include "../cell-contents/CellContent.h"

class Cell
{
private:
    std::string stringContent;
    CellContent *content;

public:
    Cell(const std::string &);
    // Cell();
    // Cell(const Cell &);
    // Cell &operator=(const Cell &);
    // Cell(Cell &&);
    // Cell &operator=(Cell &&);
    ~Cell();
};
#endif
