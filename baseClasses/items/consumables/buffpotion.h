#ifndef BUFFPOTION_H
#define BUFFPOTION_H


#include "../consumable.h"
#include "../../buff.h"

class BuffPotion : public Consumable
{
protected:
    //Image image
    Buff* effect;
public:
    BuffPotion();
    bool useItem(int = 1) override;
    ~BuffPotion() override { delete effect; };
};

#endif // BUFFPOTION_H
