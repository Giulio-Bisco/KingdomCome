#include "creature.h"

Creature::~Creature() {
    //The inventory, being a dList of POINTERS, must have a even deeper deconstructor than the already implemented deconstructor.
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        delete (*it);
    }
    //The rest of the attributes are deallocated without any memory leak by the program.
}

void Creature::useItem(Item* i){
    Equippable* e = dynamic_cast<Equippable*>(i);
    if(e) {
        equipItem(e);
    } else {
        //Use a consumable
        //DIFFERENT BEHAVIOURS FROM DIFFERNT RACES!
        //Probably this is going to be empty until I implement buffs for potion buffs.
        //All races will be able to use potions and if someone specific can't (Maybe slimes?) will be made sure in its code not here.
    }
    return;
}

/*void Creature::equipItem(Item* e) {
    //At creature level it could only be equipping a main weapon of some sort.
    //Will not be called by lower level functions most likely, put here as last resort in case something is forgotten.
    Weapon* n = dynamic_cast<Weapon*>(e);
    if(e){
        try {
            removeItemFromInventory(e->getID());
        } catch (...) {
            //Nothing happens
        }
        if(equippedWeapon) inventory.insertBack(equippedWeapon);
        equippedWeapon = n;
    }

    return;
}*/

Item* Creature::removeItemFromInventory(unsigned int i){
    Item* ret = 0;
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getID() == i){
            ret = inventory.unstableRemoveElement(it);
            break;
        }
    }
    if(ret)
        return ret;
    else
        throw std::string("Item not in inventory");
}

void Creature::removeItemGarbageCollected(unsigned int i){
    Item* del = 0;
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getID() == i){
            del = inventory.unstableRemoveElement(it);
            break;
        }
    }
    delete del;
    throw std::string("Item not in inventory");
}

void Creature::Attack::addBuff(dList<Buff> l) {
    //For each modifier in the passed list
    for(auto it = l.begin(); it != l.end(); it++){
        bool added = 0;
        //Check if the attack already has said modifier in it
        for(auto it2 = modifiers.begin(); it2 != modifiers.end(); it2++){
            if((*it).getType() == (*it2).getType()){
                //If it has, increase the effectiveness of the already present modifier
                (*it2).setEffectiveness((*it2).getEffectiveness() + (*it).getEffectiveness());
                added = true;
            }
        }
        //If it was not already in the attack, add it now.
        if(!added)
            modifiers.insertBack(*it);
    }
}

















































