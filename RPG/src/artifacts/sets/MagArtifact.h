#include "src/artifacts/ArtifactClass.h"
#ifndef RPG_MAGARTIFACT_H
#define RPG_MAGARTIFACT_H
namespace MagArtifact{
    ArtifactClass helmet = ArtifactClass("Шляпа мага",Artifact::HELMET,40,0,10,3,30,10,10);
    ArtifactClass armor = ArtifactClass("Мантия мага",Artifact::ARMOR,80,0,30,10,10,0,50);
    ArtifactClass hands = ArtifactClass("Перчатки мага",Artifact::HANDS,20,0,3,5,0,20,20);
    ArtifactClass legs = ArtifactClass("Ботинки мага",Artifact::LEGS,20,0,20,0,0,5,30);
}
#endif //RPG_MAGARTIFACT_H
