#include <utility>

#ifndef RPG_ARMYCLASS_H
#define RPG_ARMYCLASS_H
class ArmyClass {
public:
    std::string getName() const{return this->name;}
    int getHP() {return this->HP;}
    int getDamageAll() {return int(this->damage*0.7*this->count);}
    int getDefense() const{return this->defense;}
    int getElement() {return this->element;}
    int getVulnerabilityElement() {return this->vulnerabilityElement;}
    int getSelfHealing() {return this->selfHealing;}
    int getCount() const{return this->count;}
    bool IsDeath(){return this->dead;}
    double getDefensePercentage() const{return 100 / (100 + (double)this->getDefense());}

    std::string getInfo() const {
        return "Юниты: "+ this->name+
        "\nКоличество: "+ std::to_string(this->count)+
        "\nЗдоровье одного: "+std::to_string(this->HP)+
        "\nСила: "+std::to_string(this->damage)+
        "\nЗащита: "+std::to_string(this->defense)+" в процентах "+std::to_string((int)(100-this->getDefensePercentage()*100))+"%"
        "\nЭлемент: "+SkillElement::getElementName(this->element)+
        "\nСлаб против: "+SkillElement::getElementName(this->vulnerabilityElement);
    }


    explicit ArmyClass(std::string name,int count ,int HP, int damage, int defense, int element, int vulnerabilityElement, int selfHealing):
    name(std::move(name)), count(count), HP(HP), damage(damage), defense(defense), element(element), vulnerabilityElement(vulnerabilityElement), selfHealing(selfHealing)
    {

    }

    int dealt_damage(int dealtDamage, int elementAttacks=0)
    {
        this->deadWarriors = 0;
        dealtDamage=int(dealtDamage*this->getDefensePercentage());
        dealtDamage = elementAttacks==this->vulnerabilityElement?int(dealtDamage*1.5):dealtDamage;
        this->count-=int(dealtDamage/this->HP);
        this->deadWarriors=int(dealtDamage/this->HP);
        this->check_death();
        if (this->count<0){
            return count*-1*int(dealtDamage/this->HP);
        }
        return 0;
    }

    void useHeal(){
        int healWarriors = int(this->selfHealing/this->HP);
        healWarriors = healWarriors>this->deadWarriors?this->deadWarriors:healWarriors;
        this->count+=healWarriors;
        this->deadWarriors = 0;
    }

    void addCount(int NewCount){
        this->count+=NewCount;
    }

private:
    std::string name;
    int HP,
        damage,
        defense,
        element,
        vulnerabilityElement,
        selfHealing,
        count,
        deadWarriors{};
    bool dead = false;

    void check_death(){
        if (count<=0){
            this->dead = true;
            this->count = 0;
        }
    }

};
#endif //RPG_ARMYCLASS_H
