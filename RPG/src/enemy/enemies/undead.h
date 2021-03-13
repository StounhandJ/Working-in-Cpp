#include "src/enemy/EnemyClass.h"
#include "src/skills/SkillClass.h"
#ifndef RPG_SKELETON_H
#define RPG_SKELETON_H

namespace UndeadEnemies{
    EnemyClass skeleton = EnemyClass("Скелет", 200, 20, 40, 120,SkillElement::NON_ELEMENT);
    EnemyClass ghoul = EnemyClass("Упырь", 300, 25, 15, 130,SkillElement::SPOILAGE);
    EnemyClass zombies = EnemyClass("Зомби", 500, 30, 20, 150,SkillElement::SPOILAGE, SkillElement::LIGHT);
    EnemyClass mummy = EnemyClass("Мумия", 400, 35, 25, 200,SkillElement::FIRE, SkillElement::WATER);
    EnemyClass vampire = EnemyClass("Вампир", 1000, 50, 50,400,SkillElement::NON_ELEMENT, SkillElement::LIGHT);
}
#endif //RPG_SKELETON_H
