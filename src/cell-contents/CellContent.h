#ifndef CELLCONTENT_H
#define CELLCONTENT_H

class CellContent
{
public:
    virtual ~CellContent() = default;

    virtual int getMinimalWidth() const = 0;

    virtual void printValue() const = 0;

    virtual double getDoubleValue() const = 0;
};
#endif
