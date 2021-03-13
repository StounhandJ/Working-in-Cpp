#include "src/hero/HeroClass.h"
#include "src/artifacts/sets/MagArtifact.h"
#include "src/skills/sets/MagSkills.h"
#ifndef RPG_MAGCLASS_H
#define RPG_MAGCLASS_H

class MagClass : public HeroClass {
public:

    explicit MagClass(std::string name)
    {
        this->GradeName = "Маг";
        this->HeroName = std::move(name);
        this->maxHP = 100;
        this->HP = 100;
        this->damage = 10;
        this->defense = 15;
        this->maxMana = 100;
        this->mana = 100;
        this->magic_power = 30;
        this->setArtifactHelmet(MagArtifact::helmet);
        this->setArtifactArmor(MagArtifact::armor);
        this->setArtifactHands(MagArtifact::hands);
        this->setArtifactLegs(MagArtifact::legs);
        this->allSkillsGrade={
                MagSkills::flashlightLight,
                MagSkills::staffStrike,
                MagSkills::waterJet,
                MagSkills::miniFireball,
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
#endif //RPG_MAGCLASS_H
