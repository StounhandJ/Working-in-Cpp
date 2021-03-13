#include "src/army/ArmyClass.h"
#include "src/skills/SkillClass.h"

#ifndef RPG_ELVES_H
#define RPG_ELVES_H
namespace Elves{
    ArmyClass warElves = ArmyClass("Воины эльфы", 30 ,10 ,20,15,SkillElement::NON_ELEMENT,SkillElement::FIRE, 20);
}

#endif //RPG_ELVES_H
