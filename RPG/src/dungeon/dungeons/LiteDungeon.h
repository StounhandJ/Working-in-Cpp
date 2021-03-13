#include "src/dungeon/DungeonClass.h"

#include "src/enemy/enemies/undead.h"

#include "src/artifacts/sets/UndeadArtifact.h"
#ifndef RPG_LITEDUNGEON_H
#define RPG_LITEDUNGEON_H

DungeonClass LiteDungeon = DungeonClass("Легкое подземелье", 4, 1,2,70,
                                        std::vector{
                                        UndeadEnemies::skeleton,
                                        UndeadEnemies::skeleton,
                                        UndeadEnemies::skeleton,
                                        UndeadEnemies::ghoul,
                                        UndeadEnemies::ghoul,
                                        UndeadEnemies::ghoul,
                                        UndeadEnemies::zombies,
                                        UndeadEnemies::zombies,
                                        UndeadEnemies::mummy,
                                        UndeadEnemies::mummy,
                                        UndeadEnemies::vampire
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
                                        } // Выпадающие предметы
                                        );

#endif //RPG_LITEDUNGEON_H
