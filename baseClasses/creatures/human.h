#ifndef HUMAN_H
#define HUMAN_H

#include "../creature.h"
#include "../items/equippables/armor.h"
#include "baseClasses/items/consumables/bundle.h"

class Human : public Creature
{
protected:

    Weapon* equippedWeapon;
    Armor* equippedArmor[ARMOR_PIECES];    //One slot for each armor type. The enum piece will identify the slot in the array.
    unsigned int gold;

    virtual void useBundle(Bundle*);
    void equipItem(Item*) override;
    virtual void equipArmor(Item*);
public:
    Human(std::string n, unsigned int h, unsigned int m, dList<Item*> i = dList<Item*>(), dList<Buff> b = dList<Buff>());
    void useItem(Item*) override;
    void attack(Creature* target) const override;
    void receiveAttack(Attack a) override;
};

#endif // HUMAN_H
