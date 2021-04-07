#include "src/hero/HeroClass.h"
#include "src/artifacts/sets/ArcherArtifact.h"
#include "src/skills/sets/ArcherSkills.h"
#ifndef RPG_ARCHERCLASS_H
#define RPG_ARCHERCLASS_H


class ArcherClass : public HeroClass {
public:

    explicit ArcherClass(std::string name)
    {
        this->GradeName = "Лучник";
        this->HeroName = std::move(name);
        this->maxHP = 100;
        this->maxMana = 150;
        this->damage = 20;
        this->defense = 15;
        this->ArtifactHelmet = ArcherArtifact::helmet;
        this->ArtifactArmor = ArcherArtifact::armor;
        this->ArtifactHands = ArcherArtifact::hands;
        this->ArtifactLegs = ArcherArtifact::legs;
        this->allSkillsGrade={
                ArcherSkills::daggerStrike,
                ArcherSkills::lightArrow,
                ArcherSkills::sharpArrow
        };
    }

protected:
    void up_level() override
    {
        this->level+=1;
        this->damage+=10;
        this->maxHP+=5;
        this->defense+=2;
        this->HP = this->HP< this->getMaxHPAll() / 100 * 70 ? this->getMaxHPAll() / 100 * 70 : this->getMaxHPAll();
    }

};
#endif //RPG_ARCHERCLASS_H
