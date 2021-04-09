#include <iostream>
#include <string>
#include <utility>
#include "src/dungeon/dungeons/LiteDungeon.h"
#include "src/dungeon/dungeons/AverageDungeon.h"
#include "src/dungeon/dungeons/HardDungeon.h"
#include "src/army/armies/Elves.h"
#include "battle.cpp"

using namespace std;

namespace locations
{
    extern void city();
    extern void forest();
    extern void tavern();
    extern void buys();
    extern void sales();
    extern void inventory();
    extern void listArmies();
    extern void listSkills();
    extern int menu();


    void close_game(){
        clear();
        Hero.save();
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
        int res =  fight_Boss(Hero, dungeon.getBoss());
        if (res==0){return 1;}
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
            switch (choice("Центр города", list<string>{"Легкое подземелье","Среднее подземелье","Сложное подземелье","Пойти в город"})){
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
                case 2:
                    if(input_dungeon(AverageDungeon)==1){
                        std::cout << "Персонаж умер!" << std::endl;
                        Sleep(2000);
                        Hero.spawn();
                        return;
                    }
                    break;
                case 3:
                    if(input_dungeon(HardDungeon)==1){
                        std::cout << "Персонаж умер!" << std::endl;
                        Sleep(2000);
                        Hero.spawn();
                        return;
                    }
                    break;
                case 4:return;
            }
        }
    }


    void city()
    {
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
        int price = 0;
        ArmyClass army = ArmyClass("", 0 ,0 ,0,0,0,0, 0);
        while (true) {
            clear();
            switch (choice("Покупка", list<string>{"Воины эльфы 350 золотых","Лучники эльфы 400 золотых","Маги эльфы 300 золотых","Асасины эльфы 320 золотых"})){
                case 0:return;
                case 1:
                    price = 350;
                    army = Elves::warElves;
                    break;
                case 2:
                    price = 400;
                    army = Elves::archerElves;
                    break;
                case 3:
                    price = 300;
                    army = Elves::magElves;
                    break;
                case 4:
                    price = 320;
                    army = Elves::assassinElves;
                    break;
            }

            if(price>0) {
                if (Hero.getGold() >= price) {
                    Hero.newArmy(army);
                    Hero.spendGold(price);
                    clear();
                    std::cout << "Куплено" << std::endl;
                    Sleep(1000);
                    break;
                } else {
                    clear();
                    std::cout << "Недостаточно золота" << std::endl;
                    Sleep(1000);
                }
            }
            price = 0;
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

    void listArmies(){
        while (true) {
            clear();
            string armies;
            for (const auto& army : Hero.getArmies()) {
                armies+=army.getInfo()+"\n-----------------\n";
            }
            std::cout << "Армии\n\n"+ armies+"\n"<< std::endl;
            switch (choice("", list<string>{})) {
                case 0:
                    return;
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

    void records(){
        bool IsSort = false;
        while (true) {
            clear();
            vector<vector<string>> sortRecord;
            json data = ManagementSave::gerRecords();
            for (auto val : data.items())
            {
                 if(val.value().contains("level") && val.value().contains("gold")) {
                     vector<string> vrem;
                     vrem.push_back(val.key());
                     vrem.push_back(to_string(val.value()["level"].get<int>()));
                     vrem.push_back(to_string(val.value()["gold"].get<int>()));
                     sortRecord.push_back(vrem);
                 }
            }
            if(IsSort){
                sort(sortRecord.begin(), sortRecord.end(), sortGold);
            }
            else
            {
                sort(sortRecord.begin(), sortRecord.end(), sortLevel);
            }
            json records =  ManagementSave::gerRecords();
            json sortRecords;
            printf("-----------------------------\n");
            printf("|%15s|%5s|%7s|\n", "Ник", "Уровень", "Золото");
            printf("-----------------------------\n");
            for (auto val : sortRecord)
            {
                printf("|%12s|%7s|%6s|\n", val[0].c_str(), val[1].c_str(), val[2].c_str());
            };
            printf("-----------------------------\n");
            switch (choice("", list<string>{"Сортировать по уровню", "Сортировка по золоту"})) {
                case 1:IsSort=false;break;
                case 2:IsSort=true;break;
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
            switch (choice("", list<string>{"Инвентарь" ,"Список скилов","Армии","Таблица рекордов","Выход из игры"})){
                case 0:return 0;break;
                case 1:inventory();break;
                case 2:listSkills();break;
                case 3:listArmies();break;
                case 4:records();break;
                case 5:return 1;break;
            }
        }
    }
}