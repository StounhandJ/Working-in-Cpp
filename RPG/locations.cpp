#include <iostream>
#include <string>
#include <utility>

using namespace std;

namespace locations
{
    extern void city();
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

    void city()
    {
        while (true){
            clear();
            switch (choice("Центр города", list<string>{"Пойти в таверну","Пойти в лес"})){
                case 0:
                    if (menu()==1){
                        close_game();
                        return;
                    } break;
                case 1:tavern();break;
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
                worn_by+=artifact.getTypeName()+": "+artifact.getArtifactName()+" за "+to_string(artifact.getGold())+" золотых\n";
            }
            for (const auto& artifact : Hero.getInventory()) {
                inventor.push_back(artifact.getArtifactName()+" на "+artifact.getTypeName());
            }
            std::cout << "Сейчас на персонаже:\n"+ worn_by+"\n"<< std::endl;
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
                worn_by_skill+="Название:"+artifact.getName()+
                        "\nСтихия:"+artifact.getElementName()+
                        "\nУровень: "+to_string(artifact.getLevel())+
                        "\nСила:"+to_string(artifact.getPower())+
                        "\nМана:"+to_string(artifact.getCost())+
                        "\n-----------------\n";
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