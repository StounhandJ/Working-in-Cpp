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

namespace AverageUndeadEnemies{
    EnemyClass skeleton = EnemyClass("Скелет", 400, 40, 80, 240,SkillElement::NON_ELEMENT);
    EnemyClass ghoul = EnemyClass("Упырь", 600, 50, 30, 260,SkillElement::SPOILAGE);
    EnemyClass zombies = EnemyClass("Зомби", 1000, 60, 40, 300,SkillElement::SPOILAGE, SkillElement::LIGHT);
    EnemyClass mummy = EnemyClass("Мумия", 800, 70, 50, 400,SkillElement::FIRE, SkillElement::WATER);
    EnemyClass vampire = EnemyClass("Вампир", 2000, 100, 100,800,SkillElement::NON_ELEMENT, SkillElement::LIGHT);
}

namespace HardUndeadEnemies{
    EnemyClass skeleton = EnemyClass("Скелет", 800, 80, 160, 480,SkillElement::NON_ELEMENT);
    EnemyClass ghoul = EnemyClass("Упырь", 1200, 100, 60, 520,SkillElement::SPOILAGE);
    EnemyClass zombies = EnemyClass("Зомби", 2000, 120, 80, 600,SkillElement::SPOILAGE, SkillElement::LIGHT);
    EnemyClass mummy = EnemyClass("Мумия", 1600, 140, 100, 800,SkillElement::FIRE, SkillElement::WATER);
    EnemyClass vampire = EnemyClass("Вампир", 4000, 200, 200,1600,SkillElement::NON_ELEMENT, SkillElement::LIGHT);
}
#endif //RPG_SKELETON_H
