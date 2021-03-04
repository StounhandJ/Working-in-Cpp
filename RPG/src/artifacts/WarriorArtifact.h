#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_ARTIFACTWARRIOR_H
#define RPG_ARTIFACTWARRIOR_H
namespace WarriorArtifact{
    ArtifactClass helmet = ArtifactClass("Шлем воина",Artifact::HELMET,40,0,10,5,0,0,0);
    ArtifactClass armor = ArtifactClass("Броня воина",Artifact::ARMOR,80,0,30,15,0,0,0);
    ArtifactClass hands = ArtifactClass("Наручи воина",Artifact::HANDS,20,10,5,5,0,0,0);
    ArtifactClass legs = ArtifactClass("Поножи воина",Artifact::LEGS,20,0,20,3,0,0,0);
}
#endif //RPG_ARTIFACTWARRIOR_H
