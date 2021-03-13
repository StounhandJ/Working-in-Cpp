#include "src/enemy/EnemyClass.h"
#include "src/skills/SkillClass.h"
#include "src/army/ArmyClass.h"

using namespace std;
extern SkillClass listSkills();
extern ArmyClass listArmies();

void fight(HeroClass& hero, vector<EnemyClass> enemies){
    bool battle = true;
    bool IsGoal = false;
    bool menuChoice = true;
    bool attack = true;
    int damage = 0;
    int element = SkillElement::NON_ELEMENT;
    int enemyAttack = 0;
    SkillClass skill = SkillClass("", 0, 0, 0, 0, false);
    ArmyClass army = ArmyClass("", 0, 0, 0, 0, 0, 0, 0);
    string info;
    while (battle){
        menuChoice = true;
        attack = true;
        // Информация и выбор действия //
        info = "Атакует "+to_string(enemyAttack+1)+"\nПротивники:\n";
        for(auto enemy : enemies){
            info+=enemy.getName()+" HP "+to_string(int(100.0/enemy.getMaxHP()*enemy.getHP()))+"%\n";
        }
        info+="\nВы:\nHP: "+to_string(hero.getHP()) + "/" + to_string(hero.getMaxHPAll())+
                "; Мана: "+to_string(hero.getMana())+ "/" + to_string(hero.getMaxManaAll());
        while (menuChoice) {
            switch (choiceWhile(info, list<string>{"Армия" ,"Скилы", "Автоатака"})) {
                case 1:
                    if(hero.getArmies().empty()){
                        clear();
                        std::cout << "Нет войск"<< std::endl;
                        Sleep(1000);
                        break;
                    }
                    army = listArmies();
                    IsGoal = false;
                    damage = army.getDamageAll();
                    element = army.getElement();
                    menuChoice = false;
                    break;
                case 2:
                    skill = listSkills();
                    if (skill.getCost()>hero.getMana()){
                        clear();
                        std::cout << "Недостаточно маны"<< std::endl;
                        Sleep(1000);
                        break;
                    }
                    IsGoal = !skill.IsAreaDamage();
                    damage = hero.useSkill(skill);
                    element = skill.getElement();
                    menuChoice = false;
                    break;
                case 3:
                    damage = hero.getDamageAll();
                    element = SkillElement::NON_ELEMENT;
                    IsGoal = true;
                    menuChoice = false;
                    break;
            }
        }

        // Нанесение урона //
        if (IsGoal){
            list<string> enemiesInfo;
            for(auto enemy : enemies){
                enemiesInfo.push_back(enemy.getName()+" HP "+to_string(int(100.0/enemy.getMaxHP()*enemy.getHP()))+"%");
            }
            enemies[choiceWhile("Выбирите противника ", enemiesInfo)-1].dealt_damage(damage,element);
        }
        else{
            for(auto& enemy : enemies){
                enemy.dealt_damage(damage,element);
            }
        }

        // Удаление противников//
        int number = 0;
        vector<int> numbers;
        for(auto enemy : enemies){
            if(enemy.IsDeath()){
                hero.addExperience(enemy.getExperience());
                enemies.erase(enemies.begin()+number);
                number-=1;
            }
            number+=1;
        }
        // Ход противника //
        if (!enemies.empty()) {
            while (attack) {
                if (enemyAttack < enemies.size()) {
                    hero.dealt_damage(enemies[enemyAttack].getDamage(),enemies[enemyAttack].getElement());
                    attack = false;
                }
                enemyAttack = enemyAttack < enemies.size()?enemyAttack+1:0;
            }
        }

        // Проверка кона боя //
        battle=!(enemies.empty() or hero.IsDeath());

        // Лечение армий //
        hero.healArmy();
        hero.check_IsDeathArmies();
    }
    hero.useRegenMana(999999);
}

int fight_Boss(HeroClass& hero, HeroClass boss){
    bool battle = true;
    bool menuChoice = true;
    bool attack = true;
    int damage = 0;
    int element = SkillElement::NON_ELEMENT;
    int damageBoss = 0;
    int elementBoss = SkillElement::NON_ELEMENT;
    SkillClass skill = SkillClass("", 0, 0, 0, 0, false);
    ArmyClass army = ArmyClass("", 0, 0, 0, 0, 0, 0, 0);
    string info;
    while (battle) {
        menuChoice = true;
        attack = true;
        // Информация и выбор действия //
        info = "Босс: "+boss.getHeroName()+"\nHP: "+to_string(boss.getHP())+" \n";
        info += "\nВы:\nHP: " + to_string(hero.getHP()) + "/" + to_string(hero.getMaxHPAll()) +
                "; Мана: " + to_string(hero.getMana()) + "/" + to_string(hero.getMaxManaAll());
        while (menuChoice) {
            switch (choiceWhile(info, list<string>{"Армия", "Скилы", "Автоатака"})) {
                case 1:
                    if (hero.getArmies().empty()) {
                        clear();
                        std::cout << "Нет войск" << std::endl;
                        Sleep(1000);
                        break;
                    }
                    army = listArmies();
                    damage = army.getDamageAll();
                    element = army.getElement();
                    menuChoice = false;
                    break;
                case 2:
                    skill = listSkills();
                    if (skill.getCost() > hero.getMana()) {
                        clear();
                        std::cout << "Недостаточно маны" << std::endl;
                        Sleep(1000);
                        break;
                    }
                    damage = hero.useSkill(skill);
                    element = skill.getElement();
                    menuChoice = false;
                    break;
                case 3:
                    damage = hero.getDamageAll();
                    element = SkillElement::NON_ELEMENT;
                    menuChoice = false;
                    break;
            }
        }
        // Нанесение урона //
        boss.dealt_damage(damage, element);
        // Проверка //
        if (boss.IsDeath()){
            battle = false;
            return 1;
        }
        // Атака босса //
        int number = 0;
        for (const auto& skillBoss : boss.getSkills()){
            if(boss.getMana()<skillBoss.getCost()){
                number+=1;
            }
        }
        if(number>0){
            while (attack){
                auto skillBoss = boss.getSkills()[randInt(0,boss.getSkills().size()-1)];
                if (skillBoss.getCost()<boss.getMana()){
                    damageBoss = boss.useSkill(skillBoss);
                    elementBoss = skillBoss.getElement();
                    info = skillBoss.getName();
                    attack = false;
                }
            }
        }
        else{
            info = "Автоатака";
            damageBoss = boss.getDamageAll();
            elementBoss = SkillElement::NON_ELEMENT;
        }
        clear();
        std::cout << "Босс атаковал "+info << std::endl;
        Sleep(1000);
        hero.dealt_damage(damageBoss, elementBoss);

        // Проверка //
        if (hero.IsDeath()){
            battle = false;
            return 0;
        }
    }
    return 1;
}

ArmyClass listArmies(){
    list<string> armies;
    for (const auto& army : Hero.getArmies()) {
        armies.push_back(army.getInfo());
    }
    return Hero.getArmies()[choiceWhile("Армии", armies) - 1];
}

SkillClass listSkills(){
    list<string> worn_by_skill;
    for (const auto& skill : Hero.getSkills()) {
        worn_by_skill.push_back(skill.getInfo());
    }
    return Hero.getSkills()[choiceWhile("Скилы", worn_by_skill) - 1];
}