#include <windows.h>
#include <iostream>
#include "src/dungeon/dungeons/LiteDungeon.h"
#include "HeaderFiles/function.h"
#include "HeaderFiles/battle.h"

#include "src/hero/HeroClass.h"
#include "src/skills/SkillClass.h"
#include "src/artifacts/ArtifactClass.h"
#include "src/dungeon/DungeonClass.h"
#include "src/enemy/EnemyClass.h"
#include "HeaderFiles/locations.h"
#include "HeaderFiles/function.h"

using namespace std;

HeroClass Hero = HeroClass();
namespace locations
{
    extern void city(HeroClass& hero);
    extern void forest();
    extern void tavern();
    extern void buys();
    extern void sales();
    extern void inventory();
    extern void listSkills();
    extern int menu();


    void close_game(){
        clear();
        std::cout << "Bye ; )" << std::endl;
        exit(11);
    }

    int input_dungeon(DungeonClass dungeon){
        string info;
        for (int level = 0; level < dungeon.getLevelCount(); level++) {
            clear();
            std::cout << "Вы на "+to_string(level+1)+" этаже" << std::endl;
            Sleep(1000);
            // Начало подуровня //
            for(int subLevel = 0; subLevel < randInt(1,5); subLevel++ ){
                clear();
                // С каким-то шансом будет враг //
                if (percentageChance(dungeon.getChanceMeetEnemies()))
                {
                    fight(Hero,dungeon.getEnemies(randInt(dungeon.getMinCountEnemyLevel(),dungeon.getMaxCountEnemyLevel())));
                    clear();
                    if(Hero.IsDeath()){
                        return 1; // Персонаж умер в сражение //
                    }
                    string text = "С мобов вам выпало:\n";
                    std::vector<ArtifactClass> listArtifacts = dungeon.getArtifacts(randInt(0,1));
                    for (const auto& artifact : listArtifacts){
                        Hero.newArtifactInventory(artifact);
                        text+=artifact.getArtifactName()+" на "+artifact.getTypeName()+"\n";
                    }
                    if (!listArtifacts.empty()){
                        std::cout << text << std::endl;
                        Sleep(3000);
                    }
                }

                // С шансом 10% будет сундук //
                list<string> typeSubLevel{"Идти вперед"};
                if (percentageChance(10)){
                    typeSubLevel.emplace_back("Сундук");
                }
                // Выбор действия //
                switch (choiceWhile("",typeSubLevel,true))
                {
                    case 0:
                        if (menu()==1){
                            close_game();
                            return 0;
                        }
                        break;
                    case 1:break;
                    case 2:
                        string text = "Из сундука вам выпало:\n";
                        std::vector<ArtifactClass> listArtifacts = dungeon.getArtifacts(randInt(1,3));
                        for (const auto& artifact : listArtifacts){
                            Hero.newArtifactInventory(artifact);
                            text+=artifact.getArtifactName()+" на "+artifact.getTypeName()+"\n";
                        }
                        std::cout << text << std::endl;
                        Sleep(3000);
                }
            }
        }
        clear();
        string text = "Вы прошли данж!\nВот ваш лут:\n";
        std::vector<ArtifactClass> listArtifacts = dungeon.getArtifacts(randInt(3,6));
        for (const auto& artifact : listArtifacts){
            Hero.newArtifactInventory(artifact);
            text+=artifact.getArtifactName()+" на "+artifact.getTypeName()+"\n";
        }
        std::cout << text << std::endl;
        Sleep(5000);
        return 0;
    }

    void forest(){
        while (true){
            clear();
            switch (choice("Центр города", list<string>{"Легкое подземелье","Пойти в город"})){
                case 0:
                    if (menu()==1){
                        close_game();
                        return;
                    } break;
                case 1:
                    if(input_dungeon(LiteDungeon)==1){
                        std::cout << "Персонаж умер!" << std::endl;
                        Sleep(2000);
                        Hero.spawn();
                        return;
                    }
                    break;
                case 2:return;
            }
        }
    }


    void city(HeroClass& hero)
    {
        Hero = hero;
        while (true){
            clear();
            switch (choice("Центр города", list<string>{"Пойти в таверну","Пойти в лес", "Привал(40% востоновления здоровья)"})){
                case 0:
                    if (menu()==1){
                        close_game();
                        return;
                    } break;
                case 1:tavern();break;
                case 2:forest();break;
                case 3:
                    Hero.useHeal(int(Hero.getMaxHPAll()*0.4));
                    clear();
                    std::cout << "Вы спите"<< std::endl;
                    Sleep(4000);
                    break;
            }
        }
    }

    void tavern()
    {
        while (true){
            clear();
            switch (choice("Таверна", list<string>{"Пойти в центр города","Купить","Продать"})){
                case 0:
                    if (menu()==1){
                        close_game();
                        return;
                    } break;
                case 1:return;
                case 2:buys();break;
                case 3:sales();break;
            }
        }
    }

    void buys(){
        while (true) {
            clear();
            switch (choice("Покупка !ТУТ ПУСТО!", list<string>{})){
                case 0:return;
            }
        }
    }

    void sales(){
        while (true) {
            clear();
            list<string> inventor;
            for (const auto& artifact : Hero.getInventory()) {
                inventor.push_back(artifact.getArtifactName()+" на "+artifact.getTypeName()+" за "+to_string(artifact.getGold())+" золотых");
            }
            int result = choice("Продажа", inventor);
            if (result==0){
                return;
            }
            else if (result<=Hero.getInventory().size()) {
                auto artifact = Hero.getInventory()[result-1];
                Hero.addGold(artifact.getGold());
                Hero.removeByArtifact(artifact);
            }
            }
        }

    void inventory()
    {
        while (true){
            clear();
            list<string> inventor;
            string worn_by;
            for (const auto& artifact : Hero.getWornBy()) {
                worn_by+="\n"+artifact.getTypeName()+"|"+artifact.getInfo()+"\n";
            }
            for (const auto& artifact : Hero.getInventory()) {
                inventor.push_back(artifact.getArtifactName()+" на "+artifact.getTypeName());
            }
            std::cout << "Сейчас на персонаже:\n"+ worn_by<< std::endl;
            int result = choice("", inventor);
            if (result==0){
                return;
            }
            else if (result<=Hero.getInventory().size())
            {
                auto artifact = Hero.getInventory()[result-1];
                switch (artifact.getType()) {
                    case Artifact::HELMET:
                        Hero.setArtifactHelmet(artifact);
                        break;
                    case Artifact::ARMOR:
                        Hero.setArtifactArmor(artifact);
                        break;
                    case Artifact::HANDS:
                        Hero.setArtifactHands(artifact);
                        break;
                    case Artifact::LEGS:
                        Hero.setArtifactLegs(artifact);
                        break;
                }
            }
        }
    }

    void listSkills(){
        while (true) {
            clear();
            string worn_by_skill;
            for (const auto& artifact : Hero.getSkills()) {
                worn_by_skill+=artifact.getInfo()+"\n-----------------\n";
            }
            std::cout << "Скилы\n\n"+ worn_by_skill+"\n"<< std::endl;
            switch (choice("", list<string>{})) {
                case 0:
                    return;
            }
        }
    }

    int menu()
    {
        while (true){
            clear();
            string statistics="Информация\n";
            string text;
            statistics+="Имя персонажа: "+Hero.getHeroName()+"\n";
            statistics+="Имя класса: "+Hero.getGradeName()+"\n";
            statistics+="Уроень: "+to_string(Hero.getLevel())+"\n";
            statistics+="Опыт: "+to_string(Hero.getExperience())+"/"+to_string(Hero.getExperienceNextLevel())+"\n";
            statistics+= "HP: " + to_string(Hero.getHP()) + "/" + to_string(Hero.getMaxHPAll())+" +"+to_string(Hero.getHPArtifact()) + "\n";
            statistics+="Мана: "+to_string(Hero.getMana())+ "/" + to_string(Hero.getMaxManaAll())+" +"+to_string(Hero.getManaArtifact())+"\n";
            statistics+="Сила: "+to_string(Hero.getDamageAll())+" +"+to_string(Hero.getDamageArtifact())+"\n";
            statistics+="Магическая сила: "+to_string(Hero.getMagicPowerAll())+" +"+to_string(Hero.getMagicPowerArtifact())+"\n";
            statistics+="Защита: "+to_string(Hero.getDefenseAll())+" +"+to_string(Hero.getDefenseArtifact())+" в процентах "+to_string((int)(100-Hero.getDefensePercentage()*100))+"%"+"\n";
            statistics+="Знания: "+to_string(Hero.getKnowledgeAll())+" +"+to_string(Hero.getKnowledgeArtifact())+" доп.маг.урон "+to_string((int)(Hero.getKnowledgePercentage()*100))+"%"+"\n";
            statistics+="Золото: "+to_string(Hero.getGold())+"\n";
            std::cout << statistics << std::endl;
            switch (choice("", list<string>{"Инвентарь" ,"Список скилов", "Выход из игры"})){
                case 0:return 0;break;
                case 1:
                    inventory();
                    break;
                case 2:listSkills();break;
                case 3:return 1;break;
            }
        }
    }
}