#include "weapon.h"

//Will return -1 if the item broke. Will return
bool Weapon::useItem(int i){
    if(durability>=i) durability -= i;
    else durability = 0;
    return durability;
}
