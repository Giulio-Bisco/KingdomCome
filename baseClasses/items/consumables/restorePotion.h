#ifndef RESTOREPOTION_H
#define RESTOREPOTION_H

#include "../consumable.h"

class RestorePotion : public Consumable
{
protected:
    //Image image
    unsigned int uses;
public:
    RestorePotion();
};

#endif // RESTOREPOTION_H
