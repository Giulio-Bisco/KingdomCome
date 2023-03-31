#include "human.h"

Human::Human(std::string n, unsigned int h, unsigned int m, dList<Item*> i, dList<Buff> b)
    : Creature(n, h, m, i, b) {
    for(int i = 0; i < ARMOR_PIECES; i++) equippedArmor[i] = 0;
    equippedWeapon = 0;
}

void Human::useItem(Item* i){
    Consumable* c = dynamic_cast<Consumable*>(i);
    if(c){
        //USE CONSUMABLE
    } else {
        equipItem(i);
    }
}

void Human::useBundle(Bundle* b){
    if(b->getKind() == Gold){
        gold += b->getNum();
        delete b;
        inventory.removeElement(b);
    }
}

void Human::equipItem(Item* i){
    if (dynamic_cast<Armor*>(i)) {
        equipArmor(i);
        return;
    }
}

void Human::equipArmor(Item* i) {
    Armor* a = dynamic_cast<Armor*>(i);
    if(a){
        if(equippedArmor[a->getType()]){
            inventory.insertBack(equippedArmor[a->getType()]);
        }
        removeItemFromInventory(a->getID());
        equippedArmor[a->getType()] = a;
    } else {
        throw std::string("Not an armor, can't equip");
    }
}

void Human::attack(Creature* target) const {
    Attack a;
    a.attacker = this;
    a.damage = equippedWeapon->getDamage();
    a.type = equippedWeapon->getType();
    foreach(Buff* buff in buffList){

    }
}
