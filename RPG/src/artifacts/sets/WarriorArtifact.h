#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_ARTIFACTWARRIOR_H
#define RPG_ARTIFACTWARRIOR_H
namespace WarriorArtifact{
    ArtifactClass helmet = ArtifactClass("Шлем воина",Artifact::HELMET,50,0,0,0,20,0,40);
    ArtifactClass armor = ArtifactClass("Броня воина",Artifact::ARMOR,80,0,15,0,35,0,80);
    ArtifactClass hands = ArtifactClass("Наручи воина",Artifact::HANDS,20,0,20,0,10,0,20);
    ArtifactClass legs = ArtifactClass("Поножи воина",Artifact::LEGS,20,0,0,0,30,0,20);
}
#endif //RPG_ARTIFACTWARRIOR_H
