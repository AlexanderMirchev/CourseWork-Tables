#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H
#include "../table/Table.h"
#include <optional>

/**
 * Controller class for interractions with table
*/
class TableController
{
private:
    std::optional<Table> table;

public:
    TableController() = default;
    ~TableController() = default;

    const Table &getTable() const;
    void setTable(const Table &);
    void removeTable();

    void printTable() const;

    /**
     * Sets cell at coordinates to newValue and 
     * updates it and all dependant cells
    */
    void editCell(const size_t &row, const size_t &col,
                  const std::string &newValue);

private:
    void updateColumns(const std::vector<size_t> &columns);
};
#endif
