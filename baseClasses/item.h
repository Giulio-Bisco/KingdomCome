#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
protected:
    //Image image
    std::string name;
    int value;
    unsigned int ID;
public:
    Item(std::string n, int v, unsigned int id) : name(n), value(v), ID(id) {}
    virtual ~Item() = default;
    virtual bool useItem(int = 1) = 0;  //It's a bool. There is a chance when used it will be destroyed, when that happens returned value = true.

    std::string getName() const { return name; }
    int getValue() const { return value; }
    unsigned int getID() const { return ID; }
    void setName(std::string n) { name = n; }
    void setValue(int v) { value = v; }
    void setID(unsigned int id) { ID = id; }    //Only to use when item is entering differnet inventory.
};

#endif // ITEM_H
