#include "src/hero/HeroClass.h"
#include "src/hero/grade/WarriorClass.h"
#include "src/hero/grade/ArcherClass.h"
#include "src/hero/grade/MagClass.h"
HeroClass Hero = HeroClass();


#include <iostream>
#include <windows.h>
#include <string>
#include "function.cpp"
#include "locations.cpp"
#include "src/artifacts/ArtifactClass.h"
#include "src/skills/SkillClass.h"
using namespace std;

void registration(){
    string name = input_str("имя персонажа");
    bool set_grade = true;
    while (set_grade){
        clear();
        switch (choice("Выбирите класс", list<string>{"Воин", "Лучник", "Маг"})) {
            case 1: Hero = WarriorClass(name);set_grade=false;break;
            case 2: Hero = ArcherClass(name);set_grade=false;break;
            case 3: Hero = MagClass(name);set_grade=false;break;
        }
    }
    bool set_skill = true;
    while (set_skill){
        clear();
        list<string> skills{
                Hero.getAllSkillsGrade()[0].getName(),
                Hero.getAllSkillsGrade()[1].getName(),
                Hero.getAllSkillsGrade()[2].getName()
        };
        switch (choice("Выбирите один скилл", skills)) {
            case 1: Hero.setSkill(Hero.getAllSkillsGrade()[0]);set_skill=false;break;
            case 2: Hero.setSkill(Hero.getAllSkillsGrade()[1]);set_skill=false;break;
            case 3: Hero.setSkill(Hero.getAllSkillsGrade()[2]);set_skill=false;break;
        }
    }
}
int main() {
    clear();
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    registration();
    clear();
    Hero.spawn();
    locations::city();
    std::cout << Hero.getHeroName() << std::endl;
    std::cout << Hero.getHP() << std::endl;
    return 0;
}
