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
                    menuChoice = false;
                    break;
                case 3:
                    damage = hero.getDamageAll();
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
            enemies[choiceWhile("Выбирите противника ", enemiesInfo)-1].dealt_damage(damage);
        }
        else{
            for(auto& enemy : enemies){
                enemy.dealt_damage(damage);
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