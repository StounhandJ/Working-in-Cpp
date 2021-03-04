#include <iostream>
#include <string>
#include <utility>
#include <map>
#include "src/skills/SkillClass.h"
#include "src/hero/HeroClass.h"
#ifndef RPG_ARCHERCLASS_H
#define RPG_ARCHERCLASS_H
std::map <std::string,SkillClass> ArcherListSkill = {
        {"StrongBlow", SkillClass("Сильный удар", 1, 100, 10, NON_ELEMENT)},
        {"TorsionalImpact", SkillClass("Крутящий удар", 1, 100, 10, NON_ELEMENT)},
        {"HeavenStrike", SkillClass("Удар небес", 1, 300, 50, NON_ELEMENT)},
};

class ArcherClass : public HeroClass {
public:

    explicit ArcherClass(std::string name)
    {
        this->GradeName = "Лучник";
        this->HeroName = std::move(name);
        this->maxHP = 100;
        this->HP = 100;
        this->damage = 20;
        this->defense = 15;
    }

protected:
    virtual void up_level()
    {
        this->level+=1;
        this->damage+=10;
        this->maxHP+=5;
        this->defense+=2;
        this->HP = this->HP< this->getMaxHPAll() / 100 * 70 ? this->getMaxHPAll() / 100 * 70 : this->getMaxHPAll();
    }

};
#endif //RPG_ARCHERCLASS_H
