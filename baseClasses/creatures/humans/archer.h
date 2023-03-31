#ifndef ARCHER_H
#define ARCHER_H

#include "../human.h"

class Archer : public Human
{
protected:
    unsigned int ammo;
    int ammoKind;   //0 for bow, 1 for crossbow. Simple but effective. Can be extended in case I want to add more ranged weapons.
    void useBundle(Bundle*) override;
    void equipItem(Item*) override;
    void equipArmor(Item*) override;
public:
    Archer(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
    void attack(Creature* target) const override;
    void receiveAttack(Attack a) override;
};

#endif // ARCHER_H
