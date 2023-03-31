#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "../equippable.h"

enum weaponFamily { Longsword, Shortsword, Polearm, Mace, Bow, Crossbow, Staff, Book };
enum damageType { slash, pierce, blunt, magic };

class Weapon : public Equippable
{
protected:
    //Image image
    weaponFamily family;
    damageType type;
    int damage;
public:
    Weapon(std::string n, int v, unsigned int id, int d, weaponFamily f, damageType t, int dmg)
        : Equippable(n, v, id, d), family(f), type(t), damage(dmg) {}
    bool useItem(int = 1) override;

    damageType getType() const { return type; }
    weaponFamily getFamily() const { return family; }
    int getDamage() const { return damage; }

};

#endif // WEAPON_H
