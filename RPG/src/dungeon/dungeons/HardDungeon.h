#include "src/dungeon/DungeonClass.h"
#include "src/bosses/LichClass.h"
#include "src/enemy/enemies/undead.h"

#ifndef RPG_HARDDUNGEON_H
#define RPG_HARDDUNGEON_H
DungeonClass HardDungeon = DungeonClass("Сложное подземелье", 4, 1,2,70,
                                        std::vector{
                                                HardUndeadEnemies::skeleton,
                                                HardUndeadEnemies::skeleton,
                                                HardUndeadEnemies::skeleton,
                                                HardUndeadEnemies::ghoul,
                                                HardUndeadEnemies::ghoul,
                                                HardUndeadEnemies::ghoul,
                                                HardUndeadEnemies::zombies,
                                                HardUndeadEnemies::zombies,
                                                HardUndeadEnemies::mummy,
                                                HardUndeadEnemies::mummy,
                                                HardUndeadEnemies::vampire
                                        }, // Противники в данже
                                        std::vector{
                                                SkeletonArtifact::helmet,
                                                SkeletonArtifact::armor,
                                                SkeletonArtifact::hands,
                                                SkeletonArtifact::legs,

                                                VampireArtifact::helmet,
                                                VampireArtifact::armor,
                                                VampireArtifact::hands,
                                                VampireArtifact::legs,

                                                MummyArtifact::helmet,
                                                MummyArtifact::armor,
                                                MummyArtifact::hands,
                                                MummyArtifact::legs,
                                        }, // Выпадающие предметы
                                        Lich
);
#endif //RPG_HARDDUNGEON_H
