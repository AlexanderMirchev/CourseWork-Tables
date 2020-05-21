#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H
#include "../table/Table.h"
#include <optional>

using namespace std;

class TableController
{
private:
    optional<Table> table;

public:
    TableController() = default;
    ~TableController() = default;

    void setTable(const Table &);
    void removeTable();

    void printTable() const;
    void editCell(const size_t &row, const size_t &col,
                  const std::string &newValue);
};
#endif
