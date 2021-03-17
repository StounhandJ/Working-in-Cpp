#include "src/dungeon/DungeonClass.h"
#include "src/bosses/LichClass.h"
#include "src/enemy/enemies/undead.h"

#ifndef RPG_AVERAGEDUNGEON_H
#define RPG_AVERAGEDUNGEON_H
DungeonClass AverageDungeon = DungeonClass("Среднее подземелье", 4, 1,2,70,
                                        std::vector{
                                                AverageUndeadEnemies::skeleton,
                                                AverageUndeadEnemies::skeleton,
                                                AverageUndeadEnemies::skeleton,
                                                AverageUndeadEnemies::ghoul,
                                                AverageUndeadEnemies::ghoul,
                                                AverageUndeadEnemies::ghoul,
                                                AverageUndeadEnemies::zombies,
                                                AverageUndeadEnemies::zombies,
                                                AverageUndeadEnemies::mummy,
                                                AverageUndeadEnemies::mummy,
                                                AverageUndeadEnemies::vampire
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
#endif //RPG_AVERAGEDUNGEON_H
