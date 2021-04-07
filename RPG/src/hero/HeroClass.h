#include <vector>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

#include "src/skills/SkillClass.h"
#include "src/artifacts/ArtifactClass.h"
#include "src/army/ArmyClass.h"

#ifndef RPG_HERO_H
#define RPG_HERO_H
#include "Headers/ManagementSave.h"
using json = nlohmann::json;
// Parent Class
// При инецализации нужно указать GradeName и HeroName
// Остальные параметры на усматрения
// Virtual function:
//
// virtual void up_level()


class HeroClass {
public:
    std::string getHeroName() const{return this->HeroName;}
    std::string getGradeName() const{return this->GradeName;}
    std::vector <SkillClass> getSkills() {return this->skills;}
    std::vector <SkillClass> getAllSkillsGrade() const{return this->allSkillsGrade;}
    std::vector <ArmyClass> getArmies() {return this->armies;}
    int getHP() {return this->HP;}
    int getLevel() {return this->level;}
    int getExperience() {return this->experience;}
    int getExperienceNextLevel() {return level*(100+(level*15));}
    int getDamage() {return this->damage;}
    int getDefense() {return this->defense;}
    double getDefensePercentage() {return 100 / (100 + (double)this->getDefenseAll());}
    double getKnowledgePercentage() {return 1-(100 /(100 + (double)this->getKnowledgeAll()));}
    int getKnowledge() {return this->knowledge;}
    int getMagic_power() {return this->magic_power;}
    int getMana() {return this->mana;}
    int getGold() {return this->gold;}
    std::vector<ArtifactClass> getInventory() {return this->inventory;}
    std::vector<ArtifactClass> getWornBy() {
        return std::vector<ArtifactClass>{this->ArtifactHelmet,this->ArtifactArmor,this->ArtifactHands,this->ArtifactLegs};}
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
    int getMaxManaAll()  {return this->maxMana + this->getManaArtifact();}

    bool IsDeath(){return this->dead;}

    void addGold(int addGold){
        this->gold+=addGold;
        this->save();
    }

    void spendGold(int spendGold)
    {
        this->gold-=spendGold;
        this->save();
    }

    void addExperience(int addExperience){
        this->experience+=addExperience;
        this->check_level();
        this->save();
    }

    void death(){
        this->dead = true;
    }

    void spawn(){
        if (this->dead) {
            this->gold = 100;
            this->HP = this->getMaxHPAll();
            this->mana = this->getMaxManaAll();
            this->dead = false;
        }
        this->save();
    }

    void dealt_damage(int dealtDamage, int elementAttacks=0)
    {
        if (!this->armies.empty()){
            this->armies[this->randInt(0, this->armies.size()-1)].dealt_damage(int(dealtDamage*0.3),elementAttacks);
            dealtDamage = int(dealtDamage*0.7);
        }
        dealtDamage=int(dealtDamage*this->getDefensePercentage());
        dealtDamage = elementAttacks==this->vulnerabilityElement?int(dealtDamage*1.5):dealtDamage;
        this->HP-=dealtDamage;
        this->check_death();
        this->save();
    }

    void check_IsDeathArmies(){
        int number = 0;
        std::vector<int> numbers;
        for(auto army : this->armies){
            if(army.IsDeath()){
                this->armies.erase(this->armies.begin()+number);
                number-=1;
            }
            number+=1;
        }
    }

    void useHeal(int heal_HP)
    {
        this->HP += heal_HP;
        if (this->HP > this->getMaxHPAll()){
            this->HP = this->getMaxHPAll();
        }
        this->save();
    }

    void healArmy()
    {
        for (auto army : this->armies) {
            army.useHeal();
        }
    }

    void newArmy(const ArmyClass& NewArmy){
        for (auto& army : this->armies) {
            if (army.getName()==NewArmy.getName()){
                army.addCount(NewArmy.getCount());
                return;
            }
        }
        this->armies.push_back(NewArmy);
        this->save();
    }

    void useRegenMana(int regen_mana)
    {
        this->mana += regen_mana;
        if (this->mana > this->getMaxManaAll()){
            this->mana = this->getMaxManaAll();
        }
    }

    int useSkill(int numberSkill){
        if (numberSkill<=this->skills.size()){
            SkillClass skill = this->skills[numberSkill];
            if (this->mana>=skill.getCost()){
                this->mana-=skill.getCost();
                return int(skill.getPower()+(skill.getPower()*this->getKnowledgePercentage())+(this->magic_power*0.6));
            }
        }
        return 0;
    }

    int useSkill(const SkillClass& skill){
        this->mana-=skill.getCost();
        return int(skill.getPower()+(skill.getPower()*this->getKnowledgePercentage())+(this->magic_power*0.6));
    }

    void newArtifactInventory(const ArtifactClass NewArtifact){
        this->inventory.push_back(NewArtifact);
        this->save();
    }

    void setArtifactHelmet(const ArtifactClass& NewArtifactHelmet){
        if (NewArtifactHelmet.getType()==Artifact::HELMET){
            if (this->ArtifactHelmet.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactHelmet);
            }

            this->ArtifactHelmet= NewArtifactHelmet;
        }
        this->save();
    }

    void setArtifactArmor(const ArtifactClass& NewArtifactArmor){
        if (NewArtifactArmor.getType()==Artifact::ARMOR){
            if (this->ArtifactArmor.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactArmor);
            }
            removeByArtifact(NewArtifactArmor);
            this->ArtifactArmor= NewArtifactArmor;
        }
        this->save();
    }

    void setArtifactHands(const ArtifactClass& NewArtifactHands){
        if (NewArtifactHands.getType()==Artifact::HANDS){
            if (this->ArtifactHands.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactHands);
            }
            this->ArtifactHands= NewArtifactHands;
        }
        this->save();
    }

    void setArtifactLegs(const ArtifactClass& NewArtifactLegs){
        if (NewArtifactLegs.getType()==Artifact::LEGS){
            if (this->ArtifactLegs.getArtifactName()!="Пусто"){
                this->inventory.push_back(this->ArtifactLegs);
            }
            this->ArtifactLegs= NewArtifactLegs;
        }
        this->save();
    }

    void setSkill(const SkillClass& newSkill){
        if (newSkill.getLevel()<=this->getLevel()){
            this->skills.push_back(newSkill);
        }
    }

    void removeByArtifact(const ArtifactClass & val)
    {
        int number = 0;
        for(const auto& atr : this->inventory)
        {
            if( atr.getArtifactName()==val.getArtifactName() && atr.getGold()==val.getGold())
            {
                this->inventory.erase(this->inventory.begin() + number);
                break;
            }
            number+=1;
        }
        this->save();
    }

    explicit HeroClass()
    {
        this->HeroName = "None";
        this->GradeName = "None";
        this->HP = 100;
        this->mana = 100;
        this->level = 1;
        this->experience = 0;
        this->damage = 10;
        this->magic_power = 10;
        this->defense = 30;
        this->knowledge = 0;
        this->gold = 100;
    }

    void save()
    {
        json infoJSON = json{
                {"HP", HP},
                {"level", level},
                {"maxHP", maxHP},
                {"experience", experience},
                {"damage", damage},
                {"defense", defense},
                {"knowledge", knowledge},
                {"magic_power", magic_power},
                {"mana", mana},
                {"maxMana", maxMana},
                {"gold", gold},
                {"vulnerabilityElement", vulnerabilityElement},
        };



        json sethJSON = json{
               {"ArtifactHelmet", ArtifactHelmet.getSave()},
               {"ArtifactArmor", ArtifactArmor.getSave()},
               {"ArtifactHands", ArtifactHands.getSave()},
               {"ArtifactLegs", ArtifactLegs.getSave()},
        };

        std::vector<json> inventoryToJSON;
        for(ArtifactClass& arti : this->inventory)
        {
            inventoryToJSON.push_back(arti.getSave());
        }

        std::vector<json> armiesToJSON;
        for(ArmyClass& army : this->armies)
        {
            armiesToJSON.push_back(army.getSave());
        }

        json first_skill;
        if (!skills.empty()){
            first_skill = skills[0].getSave();
        }

        json main = json{
                {"HeroName", HeroName},
                {"GradeName", GradeName},
                {"info", infoJSON},
                {"seth", sethJSON},
                {"inventory", inventoryToJSON},
                {"armies", armiesToJSON},
                {"first_skill", first_skill}
        };
        ManagementSave::saveJSON(HeroName, main);
    }

    void load(json data){
        HP = data["info"]["HP"].get<int>();
        level = data["info"]["level"].get<int>();
        maxHP = data["info"]["maxHP"].get<int>();
        experience = data["info"]["experience"].get<int>();
        damage = data["info"]["damage"].get<int>();
        defense = data["info"]["defense"].get<int>();
        knowledge = data["info"]["knowledge"].get<int>();
        magic_power = data["info"]["magic_power"].get<int>();
        mana = data["info"]["mana"].get<int>();
        maxMana = data["info"]["maxMana"].get<int>();
        gold = data["info"]["gold"].get<int>();
        vulnerabilityElement= data["info"]["vulnerabilityElement"].get<int>();

        inventory.clear();
        for(auto& arti : data["inventory"].get<std::vector<json>>())
        {
            this->newArtifactInventory(ArtifactClass::Load(arti));
        }

        armies.clear();
        for(auto& army : data["armies"].get<std::vector<json>>())
        {
            this->newArmy(ArmyClass::Load(army));
        }

        ArtifactHelmet = ArtifactClass::Load(data["seth"]["ArtifactHelmet"]);
        ArtifactArmor = ArtifactClass::Load(data["seth"]["ArtifactArmor"]);
        ArtifactHands = ArtifactClass::Load(data["seth"]["ArtifactHands"]);
        ArtifactLegs = ArtifactClass::Load(data["seth"]["ArtifactLegs"]);

        this->setSkill(SkillClass::Load(data["first_skill"]));
        if(level>1){this->up_new_skill();};
    }


protected:

    bool dead = true;
    std::string HeroName,
                GradeName;
    ArtifactClass ArtifactHelmet = ArtifactClass("Пусто", Artifact::HELMET),
            ArtifactArmor = ArtifactClass("Пусто", Artifact::ARMOR),
            ArtifactHands = ArtifactClass("Пусто", Artifact::HANDS),
            ArtifactLegs = ArtifactClass("Пусто", Artifact::LEGS);
    std::vector<ArtifactClass> inventory{};
    std::vector <SkillClass> skills{};
    std::vector <ArmyClass> armies{};
    std::vector <SkillClass> allSkillsGrade{};

    int HP{},
        maxHP{},
        level{},
        experience{},
        damage{},
        defense{},
        knowledge{},
        magic_power{},
        mana{},
        maxMana{},
        gold{},
        vulnerabilityElement=-1;

    void check_death(){
        if (HP<1){
            this->death();
        }
    }

    void check_level()
    {
        if (experience>=this->getExperienceNextLevel()){
            experience-=this->getExperienceNextLevel();
            this->up_level();
            this->up_new_skill();
            this->check_level();
        }
        this->save();
    }

    void up_new_skill()
    {
        for(const auto& atr : this->allSkillsGrade)
        {
            if( atr.getLevel()==level)
            {
                this->setSkill(atr);
                break;
            }
        }
    }

    virtual void up_level()
    {
        level+=1;
    }

    int randInt(int from, int before){
        int number = std::rand()%(before+1);
        if(number<from){
            number+=from;
        }
    return number;
}
};


#endif //RPG_HERO_H
