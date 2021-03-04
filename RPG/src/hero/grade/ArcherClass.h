#include <iostream>
#include <string>
#include <utility>
#include <map>
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
        this->HP = 100;
        this->damage = 20;
        this->defense = 15;
        this->setArtifactHelmet(ArcherArtifact::helmet);
        this->setArtifactArmor(ArcherArtifact::armor);
        this->setArtifactHands(ArcherArtifact::hands);
        this->setArtifactLegs(ArcherArtifact::legs);
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
