#include "src/skills/SkillClass.h"
#ifndef RPG_MAGSKILLS_H
#define RPG_MAGSKILLS_H
namespace MagSkills{
    SkillClass waterJet = SkillClass("Струя воды", 1, 200, 60, SkillElement::NON_ELEMENT, false);
    SkillClass staffStrike = SkillClass("Удар посохом", 1, 100, 0, SkillElement::NON_ELEMENT, false);
    SkillClass flashlightLight = SkillClass("Свет фонарика", 1, 150, 50, SkillElement::NON_ELEMENT, true);
    SkillClass miniFireball = SkillClass("Мини фаербол", 2, 450, 100, SkillElement::NON_ELEMENT, false);
}
#endif //RPG_MAGSKILLS_H
