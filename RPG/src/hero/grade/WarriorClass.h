#include <iostream>
#include <string>
#include <utility>
#include <map>
#include "src/hero/HeroClass.h"
#include "src/artifacts/sets/WarriorArtifact.h"
#include "src/skills/sets/WarriorSkills.h"
#ifndef RPG_HEROGRADE_H
#define RPG_HEROGRADE_H


class WarriorClass : public HeroClass {
public:

    explicit WarriorClass(std::string name)
    {
        this->GradeName = "Воин";
        this->HeroName = std::move(name);
        this->maxHP = 200;
        this->HP = 200;
        this->damage = 10;
        this->defense = 25;
        this->setArtifactHelmet(WarriorArtifact::helmet);
        this->setArtifactArmor(WarriorArtifact::armor);
        this->setArtifactHands(WarriorArtifact::hands);
        this->setArtifactLegs(WarriorArtifact::legs);
        this->allSkillsGrade={
                WarriorSkills::lightStrike,
                WarriorSkills::strongBlow,
                WarriorSkills::torsionalImpact,
                WarriorSkills::heavenStrike
        };
    }

protected:

    void up_level() override
    {
        this->level+=1;
        this->damage+=5;
        this->maxHP+=20;
        this->defense+=5;
        this->HP = this->HP < this->getMaxHPAll() / 100 * 70 ? this->getMaxHPAll() / 100 * 70 : this->getMaxHPAll();
    }

};
#endif //RPG_HEROGRADE_H