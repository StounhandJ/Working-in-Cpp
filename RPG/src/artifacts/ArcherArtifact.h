#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_ARCHERARTIFACT_H
#define RPG_ARCHERARTIFACT_H
namespace ArcherArtifact{
    ArtifactClass helmet = ArtifactClass("Шлем лучника",Artifact::HELMET,40,0,20,3,0,0,0);
    ArtifactClass armor = ArtifactClass("Броня лучника",Artifact::ARMOR,65,5,10,5,0,0,0);
    ArtifactClass hands = ArtifactClass("Наручи лучника",Artifact::HANDS,20,15,5,0,0,0,0);
    ArtifactClass legs = ArtifactClass("Поножи лучника",Artifact::LEGS,20,5,10,3,0,0,0);
}
#endif //RPG_ARCHERARTIFACT_H
