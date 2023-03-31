#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "../equippable.h"

const int ARMOR_PIECES = 5;
enum piece { helmet, chestplate, pants, boots, necklace };

class Armor : public Equippable
{
protected:
    //Image image
    piece type;
    //dList<Buff*>?
public:
    Armor();
    bool useItem(int = 1);

    piece getType() { return type; }
};

#endif // ARMOR_H
