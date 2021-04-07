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
        this->maxMana = 100;
        this->damage = 10;
        this->defense = 25;
        this->ArtifactHelmet = WarriorArtifact::helmet;
        this->ArtifactArmor = WarriorArtifact::armor;
        this->ArtifactHands = WarriorArtifact::hands;
        this->ArtifactLegs = WarriorArtifact::legs;
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