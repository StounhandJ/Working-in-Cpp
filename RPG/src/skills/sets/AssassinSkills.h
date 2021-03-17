#include "src/skills/SkillClass.h"

#ifndef RPG_ASSASSINSKILLS_H
#define RPG_ASSASSINSKILLS_H
namespace AssassinSkills{
    SkillClass strongBlow = SkillClass("Сильный удар", 1, 100, 10, SkillElement::NON_ELEMENT, false);
    SkillClass HiddenImpact = SkillClass("Скрытый удар", 1, 100, 10, SkillElement::NON_ELEMENT, false);
    SkillClass shuriken = SkillClass("Сюрикен ", 1, 200, 50, SkillElement::NON_ELEMENT, false);
    SkillClass bomb = SkillClass("Бомбочка", 2, 400, 50, SkillElement::FIRE, true);
}
#endif //RPG_ASSASSINSKILLS_H
