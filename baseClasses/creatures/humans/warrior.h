#ifndef WARRIOR_H
#define WARRIOR_H

#include "../human.h"

class Warrior : public Human
{
protected:
    void equipItem(Item*) override;
    void equipArmor(Item*) override;
public:
    Warrior(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
};

#endif // WARRIOR_H
