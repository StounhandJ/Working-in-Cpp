#include "src/army/ArmyClass.h"
#include "src/skills/SkillClass.h"

#ifndef RPG_ELVES_H
#define RPG_ELVES_H
namespace Elves{
    ArmyClass warElves = ArmyClass("Воины эльфы", 30 ,15 ,20,15,SkillElement::NON_ELEMENT,SkillElement::FIRE, 20);
    ArmyClass archerElves = ArmyClass("Лучники эльфы", 30 ,10 ,20,15,SkillElement::NON_ELEMENT,SkillElement::FIRE, 20);
    ArmyClass magElves = ArmyClass("Маги эльфы", 30 ,8 ,35,15,SkillElement::NON_ELEMENT,SkillElement::FIRE, 20);
    ArmyClass assassinElves = ArmyClass("Асасины эльфы", 30 ,12 ,25,15,SkillElement::NON_ELEMENT,SkillElement::FIRE, 20);
}

#endif //RPG_ELVES_H
