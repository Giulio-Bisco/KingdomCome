#ifndef BUNDLE_H
#define BUNDLE_H

#include "../consumable.h"

enum content { Arrow, Bolt, Gold };

class Bundle : public Consumable
{
protected:
    //Image imageù
    unsigned int num;
    content kind;
public:
    Bundle(unsigned int n, content k) : num(n), kind(k) {}

    unsigned int getNum() { return num; }
    int getKind() { return kind; }
};

#endif // BUNDLE_H
