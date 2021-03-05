#include "src/skills/SkillClass.h"
#ifndef RPG_WARRIORSKILLS_H
#define RPG_WARRIORSKILLS_H
namespace WarriorSkills{
    SkillClass strongBlow = SkillClass("Сильный удар", 1, 100, 10, SkillElement::NON_ELEMENT, false);
    SkillClass torsionalImpact = SkillClass("Крутящий удар", 1, 100, 10, SkillElement::NON_ELEMENT, true);
    SkillClass lightStrike = SkillClass("Удар света", 1, 200, 50, SkillElement::NON_ELEMENT, false);
    SkillClass heavenStrike = SkillClass("Удар небес", 2, 400, 50, SkillElement::NON_ELEMENT, false);
}
#endif //RPG_WARRIORSKILLS_H
