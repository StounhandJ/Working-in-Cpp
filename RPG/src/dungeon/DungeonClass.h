#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <list>

#include "src/artifacts/ArtifactClass.h"
#include "src/enemy/EnemyClass.h"
#ifndef RPG_DUNGEONCLASS_H
#define RPG_DUNGEONCLASS_H
// DungeonClass(Название, КоличествоУровней, МинКолВраговНаУровне, МакКолВраговНаУровне, ШансВстрВрагаПроцент, СписокВрагов, СписокАртефактов)


class DungeonClass{
public:

    std::string getDungeonName() const{return this->name;}
    std::vector<EnemyClass> getEnemiesAll() const{return this->enemies;}
    std::vector<ArtifactClass> getArtifactsAll() const{return this->artifacts;}
    int getLevelCount() const{return this->levelCount;}
    int getMaxCountEnemyLevel() const{return this->maxCountEnemyLevel;}
    int getMinCountEnemyLevel() const{return this->minCountEnemyLevel;}
    int getChanceMeetEnemies() const{return this->chanceMeetEnemies;}

    std::vector<EnemyClass> getEnemies(int count){
        std::vector<EnemyClass> listEnemies;
        for (int number = 0; number < count; number++){
            listEnemies.push_back(this->enemies[rand() % (this->enemies.size()-1)]);
        }
        return listEnemies;
    }

    std::vector<ArtifactClass> getArtifacts(int count){
        std::vector<ArtifactClass> listArtifacts;
        for (int number = 0; number < count; number++){
            listArtifacts.push_back(this->artifacts[rand() % (this->artifacts.size()-1)]);
        }
        return listArtifacts;
    }

    explicit DungeonClass(std::string name, int levelCount, int minCountEnemyLevel, int maxCountEnemyLevel,int chanceMeetEnemies,vector<EnemyClass> enemies, vector<ArtifactClass> artifacts):
    name(std::move(name)),levelCount(levelCount), minCountEnemyLevel(minCountEnemyLevel), maxCountEnemyLevel(maxCountEnemyLevel), chanceMeetEnemies(chanceMeetEnemies), enemies(enemies), artifacts(artifacts)
    {

    }

protected:
    std::string name{};
    std::vector<EnemyClass> enemies{};
    std::vector<ArtifactClass> artifacts{};
    int levelCount{},
        minCountEnemyLevel{},
        maxCountEnemyLevel{},
        chanceMeetEnemies{};
};
#endif //RPG_DUNGEONCLASS_H
