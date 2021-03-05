#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_ARCHERARTIFACT_H
#define RPG_ARCHERARTIFACT_H
namespace ArcherArtifact{
    ArtifactClass helmet = ArtifactClass("Шлем лучника",Artifact::HELMET,10,0,20,0,15,0,15);
    ArtifactClass armor = ArtifactClass("Броня лучника",Artifact::ARMOR,20,0,5,0,35,0,35);
    ArtifactClass hands = ArtifactClass("Наручи лучника",Artifact::HANDS,0,0,20,0,15,0,25);
    ArtifactClass legs = ArtifactClass("Поножи лучника",Artifact::LEGS,0,0,15,0,0,20,20);
}
#endif //RPG_ARCHERARTIFACT_H
