#ifndef ANIMAL_H
#define ANIMAL_H

#include "../Monster.h"

class Animal : public Monster
{
protected:
    void equipItem(Item*) override;
public:
    Animal(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
};

#endif // ANIMAL_H
