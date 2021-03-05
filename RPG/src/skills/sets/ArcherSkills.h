#include "src/skills/SkillClass.h"
#ifndef RPG_ARCHERSKILLS_H
#define RPG_ARCHERSKILLS_H
namespace ArcherSkills{
    SkillClass sharpArrow = SkillClass("Острая стрела", 1, 150, 10, SkillElement::NON_ELEMENT, false);
    SkillClass daggerStrike = SkillClass("Удар кинжалом", 1, 100, 10, SkillElement::NON_ELEMENT, false);
    SkillClass lightArrow = SkillClass("Стрела света", 1, 250, 80, SkillElement::NON_ELEMENT, true);

}

#endif //RPG_ARCHERSKILLS_H
