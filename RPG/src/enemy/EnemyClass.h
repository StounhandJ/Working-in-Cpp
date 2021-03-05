#include <iostream>
#include <string>
#include <utility>
#ifndef RPG_ENEMYCLASS_H
#define RPG_ENEMYCLASS_H
// EnemyClass(Имя, HP, Урон, Защита, ПолучаемыйОпыт)


class EnemyClass{
public:
    std::string getName() {return this->name;}
    int getHP() {return this->HP;}
    int getMaxHP() {return this->maxHP;}
    int getDamage() {return this->damage;}
    int getDefense() {return this->defense;}
    int getExperience() {return this->experience;}
    bool IsDeath(){return this->dead;}
    double getDefensePercentage() {return 100 / (100 + (double)this->getDefense());}

    void death(){
        this->dead = true;
    }

    void dealt_damage(int dealtDamage)
    {
        this->HP-=int(dealtDamage*this->getDefensePercentage());
        this->check_death();
    }

    explicit EnemyClass(std::string name, int HP, int damage, int defense, int experience):
            name(std::move(name)), maxHP(HP), damage(damage), defense(defense), experience(experience)
    {
        this->HP=maxHP;
    }

protected:
    std::string name;
    int HP{},
        maxHP{},
        damage{},
        defense{},
        experience{};
    bool dead=false;

    void check_death(){
        if (HP<1){
            this->HP = 0;
            this->death();
        }
    }
};
#endif //RPG_ENEMYCLASS_H
