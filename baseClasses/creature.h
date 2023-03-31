#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "dlist.h"
#include "buff.h"
#include "items/equippables/weapon.h"
//#include "items/consumables/potion.h"
//#include "items/consumables/bundle.h"


class Creature
{
protected:
    //Image image
    std::string name;
    unsigned int hp;
    unsigned int maxHp;
    unsigned int mana;
    unsigned int maxMana;
    dList<Item*> inventory;
    dList<Buff> buffList;
    struct Attack {
        const Creature* attacker;
        int damage;
        damageType type;
        dList<Buff> modifiers;
        void addBuff(dList<Buff> l);
    };
    virtual void equipItem(Item*) = 0;  //Used in useItem() if item is equippable. Different races behave differently.
public:
    Creature(std::string n, unsigned int h, unsigned int m, dList<Item*> i = dList<Item*>(), dList<Buff> b = dList<Buff>() )
        : name(n), hp(h), maxHp(h), mana(m), maxMana(m), inventory(i), buffList(b) {}
    virtual ~Creature();
    virtual void useItem(Item*);    //Maybe implement a function that works in case I forget to implement in subclass? idk
    Item* removeItemFromInventory(unsigned int ID); //Remove an item from inventory without deleting the object itself by passing its ID.
    void removeItemGarbageCollected(unsigned int ID);  //Removes the item definitely from the inventory of the carachter.
    virtual void attack(Creature* target) const;
    virtual void receiveAttack(Attack a);
    virtual void unequipItem(Item* i) = 0;

    //Getters and setters
    std::string getName() const { return name; };
    unsigned int getHp() const { return hp; };
    unsigned int getMaxHp() const { return maxHp; };
    unsigned int getMana() const { return mana; };
    unsigned int getMaxMana() const { return maxMana; };
    void setName(std::string n) { name = n;};
    void setHp(unsigned int h) { hp = h; };
    void setMaxHp(unsigned int mh) { maxHp = mh; };
    void setMana(unsigned int m) { mana = m; };
    void setMaxMan(unsigned int mm) { maxMana = mm; };
    //get and set END
};



#endif // CREATURE_H
