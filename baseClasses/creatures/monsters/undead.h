#ifndef UNDEAD_H
#define UNDEAD_H

#include "../Monster.h"

class Undead : public Monster
{
protected:
public:
    Undead(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
};

#endif // UNDEAD_H
