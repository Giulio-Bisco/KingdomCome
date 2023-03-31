#ifndef WIZARD_H
#define WIZARD_H

#include "../human.h"

class Wizard : public Human
{
protected:
    void equipItem(Item*) override;
    void equipArmor(Item*) override;
public:
    Wizard(std::string n, unsigned int h, unsigned int mh, unsigned int m, unsigned int mm, dList<Item*> i = dList<Item*>());
    void useItem(Item*) override;
};

#endif // WIZARD_H
