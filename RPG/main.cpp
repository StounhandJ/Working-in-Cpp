#include "src/hero/HeroClass.h"
#include "src/hero/grade/WarriorClass.h"
#include "src/hero/grade/ArcherClass.h"
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
    while (true){
        clear();
        switch (choice("Выбирите класс", list<string>{"Воин", "Лучник"})) {
            case 1: Hero = WarriorClass(name);return;
            case 2: Hero = ArcherClass(name);return;
        }
    }
}
int main() {
    clear();
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    registration();
    clear();
    locations::city();
    std::cout << Hero.getHeroName() << std::endl;
    std::cout << Hero.getHP() << std::endl;
    return 0;
}
