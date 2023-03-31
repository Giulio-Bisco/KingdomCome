#ifndef BUFF_H
#define BUFF_H

#include <string>

enum buffType { Health, Mana, Fire, Ice, Water, Wind, Earth };

class Buff {
private:
    std::string name;
    buffType type;
    double effectiveness;       //effectiveness% is the damage multiplier.
    int duration;               //-1 if infinite.
public:
    Buff(std::string n, buffType b, double e, int d) : name(n), type(b), effectiveness(e), duration(d) {}
    void reduceDuration(int i = 1) { duration -= i; }

    //SETTERS, GETTERS//
    std::string getName() const { return name; }
    buffType getType() const { return type; }
    double getEffectiveness() const { return effectiveness; }
    int getDuration() const { return duration; }
    void setName(std::string n) { name = n; }
    void setType(buffType b) { type = b; }
    void setEffectiveness(double e) { effectiveness = e; }
    void setDuration(int d) { duration = d; }
    //END//
};
#endif // BUFF_H
