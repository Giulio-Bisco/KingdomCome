#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "../item.h"

class Consumable : public Item
{
protected:
    //Image image
    unsigned int uses;
public:
    Consumable();
    bool useItem(int = 1) override;
};

#endif // CONSUMABLE_H
