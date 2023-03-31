#ifndef MONSTER_H
#define MONSTER_H

#include "../creature.h"

class Monster : public Creature
{
protected:
    unsigned int souls;
public:
    Monster();
};

#endif // MONSTER_H
