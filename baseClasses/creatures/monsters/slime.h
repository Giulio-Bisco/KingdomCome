#ifndef SLIME_H
#define SLIME_H

#include "../Monster.h"

class Slime : public Monster
{
protected:
public:
    Slime(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
};

#endif // SLIME_H
