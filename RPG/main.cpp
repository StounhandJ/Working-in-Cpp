#include <windows.h>
#include <iostream>
#include "src/hero/grade/WarriorClass.h"
#include "src/hero/grade/ArcherClass.h"
#include "src/hero/grade/MagClass.h"

#include "src/hero/HeroClass.h"

#include "HeaderFiles/locations.h"
#include "HeaderFiles/function.h"
HeroClass Hero2 = HeroClass();


using namespace std;

void registration(){
    string name = input_str("имя персонажа");
    bool set_grade = true;
    while (set_grade){
        clear();
        switch (choice("Выбирите класс", list<string>{"Воин", "Лучник", "Маг"})) {
            case 1: Hero2 = WarriorClass(name);set_grade=false;break;
            case 2: Hero2 = ArcherClass(name);set_grade=false;break;
            case 3: Hero2 = MagClass(name);set_grade=false;break;
        }
    }
    bool set_skill = true;
    while (set_skill){
        clear();
        list<string> skills{
                Hero2.getAllSkillsGrade()[0].getName(),
                Hero2.getAllSkillsGrade()[1].getName(),
                Hero2.getAllSkillsGrade()[2].getName()
        };
        switch (choice("Выбирите один скилл", skills)) {
            case 1: Hero2.setSkill(Hero2.getAllSkillsGrade()[0]);set_skill=false;break;
            case 2: Hero2.setSkill(Hero2.getAllSkillsGrade()[1]);set_skill=false;break;
            case 3: Hero2.setSkill(Hero2.getAllSkillsGrade()[2]);set_skill=false;break;
        }
    }
}
int main() {
    clear();
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    registration();
    clear();
    Hero2.spawn();
    locations::city(Hero2);
    std::cout << Hero2.getHeroName() << std::endl;
    std::cout << Hero2.getHP() << std::endl;
    return 0;
}
