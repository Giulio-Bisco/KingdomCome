#include "archer.h"

void Archer::useItem(Item* i) {

}

void Archer::useBundle(Bundle* b){
    if(equippedWeapon)
        switch(b->getKind()){
        case Arrow:
            if(equippedWeapon->getFamily() == Bow) {
                ammoKind = 0;
                ammo += b->getNum();
                delete b;
                inventory.removeElement(b);
            }
            break;
        case Bolt:
            if(equippedWeapon->getFamily() == Crossbow) {
                ammoKind = 1;
                ammo += b->getNum();
                delete b;
                inventory.removeElement(b);
            }
            break;
        case Gold:
            Human::useBundle(b);
            break;
        }
}

void Archer::attack(Creature* target) const {

}
