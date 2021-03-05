#include "src/enemy/EnemyClass.h"
#ifndef RPG_SKELETON_H
#define RPG_SKELETON_H

namespace UndeadEnemies{
    EnemyClass skeleton = EnemyClass("Скелет", 200, 20, 40, 120);
    EnemyClass ghoul = EnemyClass("Упырь", 300, 25, 15, 130);
    EnemyClass zombies = EnemyClass("Зомби", 500, 30, 20, 150);
    EnemyClass mummy = EnemyClass("Мумия", 400, 35, 25, 200);
    EnemyClass vampire = EnemyClass("Вампир", 1000, 50, 50,400);
}
#endif //RPG_SKELETON_H
