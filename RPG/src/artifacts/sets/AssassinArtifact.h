#include "src/artifacts/ArtifactClass.h"

#ifndef RPG_ASSASSINARTIFACT_H
#define RPG_ASSASSINARTIFACT_H
namespace AssassinArtifact{
    ArtifactClass helmet = ArtifactClass("Повязка ассасина",Artifact::HELMET,10,0,20,0,15,0,15);
    ArtifactClass armor = ArtifactClass("Броня ассасина",Artifact::ARMOR,20,0,5,0,35,0,35);
    ArtifactClass hands = ArtifactClass("Наручи ассасина",Artifact::HANDS,0,0,20,0,15,0,25);
    ArtifactClass legs = ArtifactClass("Поножи ассасина",Artifact::LEGS,0,0,15,0,0,20,20);
}
#endif //RPG_ASSASSINARTIFACT_H
