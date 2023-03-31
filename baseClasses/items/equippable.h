#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H

#include "../item.h"

class Equippable : public Item
{
protected:
    int durability; //-1 if item is indestructible.
public:
    Equippable(std::string n, int v, unsigned int id, int d) : Item(n, v, id) , durability(d) {}
    bool useItem(int = 1) override;
};

#endif // EQUIPPABLE_H
