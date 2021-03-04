#include "src/skills/SkillClass.h"
#ifndef RPG_MAGSKILLS_H
#define RPG_MAGSKILLS_H
namespace MagSkills{
    SkillClass waterJet = SkillClass("Струя воды", 1, 200, 60, NON_ELEMENT);
    SkillClass staffStrike = SkillClass("Удар посохом", 1, 100, 0, NON_ELEMENT);
    SkillClass flashlightLight = SkillClass("Свет фонарика", 1, 150, 50, NON_ELEMENT);
    SkillClass miniFireball = SkillClass("Мини фаербол", 2, 450, 100, NON_ELEMENT);
}
#endif //RPG_MAGSKILLS_H
