#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <vector>

#include "src/skills/SkillClass.h"
#include "src/artifacts/ArtifactClass.h"

#ifndef RPG_HERO_H
#define RPG_HERO_H

class HeroClass {
public:
    std::string getHeroName() const{return this->HeroName;}
    std::string getGradeName() const{return this->GradeName;}
    std::list <SkillClass> getSkills() const{return this->skills;}
    int getHP() {return this->HP;}
    int getLevel() {return this->level;}
    int getExperience() {return this->experience;}
    int getExperienceNextLevel() {return level*(100+(level*15));}
    int getDamage() {return this->damage;}
    int getDefense() {return this->defense;}
    double getDefensePercentage() {return 100 / (100 + (double)this->getDefenseAll());}
    int getKnowledge() {return this->knowledge;}
    int getMagic_power() {return this->magic_power;}
    int getMana() {return this->mana;}
    int getGold() {return this->gold;}
    std::vector<ArtifactClass> getInventory() {return this->inventory;}
    std::vector<ArtifactClass> getWornBy() {
        return std::vector<ArtifactClass>{this->ArtifactHands,this->ArtifactArmor,this->ArtifactHands,this->ArtifactLegs};}
    int getHPArtifact(){
        int finalHP=ArtifactHelmet.getHP();
        finalHP+=ArtifactArmor.getHP();
        finalHP+=ArtifactHands.getHP();
        finalHP+=ArtifactLegs.getHP();
        return finalHP;
    }
    int getMaxHPAll() {return this->maxHP + this->getHPArtifact();}

    int getDamageArtifact(){
        int finalDamage=ArtifactHelmet.getDamage();
        finalDamage+=ArtifactArmor.getDamage();
        finalDamage+=ArtifactHands.getDamage();
        finalDamage+=ArtifactLegs.getDamage();
        return finalDamage;
    }
    int getDamageAll() {return this->damage + this->getDamageArtifact();}

    int getDefenseArtifact(){
        int finalDefense=ArtifactHelmet.getDefense();
        finalDefense+=ArtifactArmor.getDefense();
        finalDefense+=ArtifactHands.getDefense();
        finalDefense+=ArtifactLegs.getDefense();
        return finalDefense;
    }
    int getDefenseAll() {return this->defense + this->getDefenseArtifact();}

    int getKnowledgeArtifact(){
        int finalKnowledge=ArtifactHelmet.getKnowledge();
        finalKnowledge+=ArtifactArmor.getKnowledge();
        finalKnowledge+=ArtifactHands.getKnowledge();
        finalKnowledge+=ArtifactLegs.getKnowledge();
        return finalKnowledge;
    }
    int getKnowledgeAll() {return this->knowledge + this->getKnowledgeArtifact();}

    int getMagicPowerArtifact(){
        int finalMagicPower=ArtifactHelmet.getMagicPower();
        finalMagicPower+=ArtifactArmor.getMagicPower();
        finalMagicPower+=ArtifactHands.getMagicPower();
        finalMagicPower+=ArtifactLegs.getMagicPower();
        return finalMagicPower;
    }
    int getMagicPowerAll() {return this->magic_power + this->getMagicPowerArtifact();}

    int getManaArtifact(){
        int finalMana=ArtifactHelmet.getMana();
        finalMana+=ArtifactArmor.getMana();
        finalMana+=ArtifactHands.getMana();
        finalMana+=ArtifactLegs.getMana();
        return finalMana;
    }
    int getManaAll() {return this->mana + this->getManaArtifact();}

    void addGold(int gold){
        this->gold+=gold;
    }

    void death(){
        std::cout << "Персонаж умер" << std::endl;
    }

    void dealt_damage(int damage)
    {
        this->HP-=damage*this->getDefensePercentage();
        this->check_death();
    }

    void heal(int heal_HP)
    {
        this->HP = heal_HP;
        if (this->HP > this->getMaxHPAll()){
            this->HP = this->getMaxHPAll();
        }
    }

    void setArtifactHelmet(const ArtifactClass& NewArtifactHelmet){
        if (NewArtifactHelmet.getType()==Artifact::HELMET){
            if (this->ArtifactHelmet.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactHelmet);
            }

            this->ArtifactHelmet= NewArtifactHelmet;
        }
    }

    void setArtifactArmor(const ArtifactClass& NewArtifactArmor){
        if (NewArtifactArmor.getType()==Artifact::ARMOR){
            if (this->ArtifactArmor.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactArmor);
            }
            removeByArtifact(NewArtifactArmor);
            this->ArtifactArmor= NewArtifactArmor;
        }
    }

    void setArtifactHands(const ArtifactClass& NewArtifactHands){
        if (NewArtifactHands.getType()==Artifact::HANDS){
            if (this->ArtifactHands.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactHands);
            }
            this->ArtifactHands= NewArtifactHands;
        }
    }

    void setArtifactLegs(const ArtifactClass& NewArtifactLegs){
        if (NewArtifactLegs.getType()==Artifact::LEGS){
            if (this->ArtifactLegs.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactLegs);
            }
            this->ArtifactLegs= NewArtifactLegs;
        }
    }

    void setSkill(const SkillClass& newSkill){
        if (newSkill.getLevel()<=this->getLevel()){
            this->skills.push_back(newSkill);
        }
    }

    void removeByArtifact(const ArtifactClass & val)
    {
        int number = 0;
        for(auto atr : this->inventory)
        {
            if( atr.getArtifactName()==val.getArtifactName() && atr.getGold()==val.getGold())
            {
                this->inventory.erase(this->inventory.begin() + number);
                break;
            }
            number+=1;
        }
    }

    explicit HeroClass(int HP=100,int maxHP=100, int level=1, int experience=0, int damage=0, int defense=0, int knowledge=0, int magic_power=0, int mana=0, int gold=100) :
            HP(HP), maxHP(maxHP), level(level),experience(experience),damage(damage),defense(defense),knowledge(knowledge),magic_power(magic_power),mana(mana),gold(gold){
        this->inventory.emplace_back("Тряпки",Artifact::ARMOR,35,0,10,5,0,0,0);
    }

protected:

    std::string HeroName,
                GradeName;
    ArtifactClass ArtifactHelmet = ArtifactClass("Пусто", Artifact::HELMET),
            ArtifactArmor = ArtifactClass("Пусто", Artifact::ARMOR),
            ArtifactHands = ArtifactClass("Пусто", Artifact::HANDS),
            ArtifactLegs = ArtifactClass("Пусто", Artifact::LEGS);
    std::vector<ArtifactClass> inventory;
    int HP{},
        maxHP{},
        level{},
        experience{},
        damage{},
        defense{},
        knowledge{},
        magic_power{},
        mana{},
        gold{};
    std::list <SkillClass> skills{};

    void check_death(){
        if (HP<1){
            this->death();
        }
    }

    void check_level()
    {
        if (this->getExperienceNextLevel()){
            experience-=this->getExperienceNextLevel();
            this->up_level();
            this->check_level();
        }
    }

    virtual void up_level()
    {
        level+=1;
    }

};


#endif //RPG_HERO_H
