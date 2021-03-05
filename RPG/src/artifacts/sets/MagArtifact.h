#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_MAGARTIFACT_H
#define RPG_MAGARTIFACT_H
namespace MagArtifact{
    ArtifactClass helmet = ArtifactClass("Шляпа мага",Artifact::HELMET,0,10,0,25,0,15,40);
    ArtifactClass armor = ArtifactClass("Мантия мага",Artifact::ARMOR,80,25,0,10,10,25,100);
    ArtifactClass hands = ArtifactClass("Перчатки мага",Artifact::HANDS,0,25,5,25,0,10,20);
    ArtifactClass legs = ArtifactClass("Ботинки мага",Artifact::LEGS,25,0,0,15,10,0,20);
}
#endif //RPG_MAGARTIFACT_H
