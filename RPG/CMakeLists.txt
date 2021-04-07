cmake_minimum_required(VERSION 3.17)
project(RPG)
include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


set(CMAKE_CXX_STANDARD 20)

add_executable(RPG
        # Стартовый файл#
        main.cpp
        # Основные классы #
        src/hero/HeroClass.h src/skills/SkillClass.h src/artifacts/ArtifactClass.h src/dungeon/DungeonClass.h src/enemy/EnemyClass.h src/army/ArmyClass.h
        # Классы персонажей #
        src/hero/grade/WarriorClass.h src/hero/grade/ArcherClass.h src/hero/grade/MagClass.h src/hero/grade/AssassinClass.h
        # Сеты артефактов #
        src/artifacts/sets/ArcherArtifact.h src/artifacts/sets/WarriorArtifact.h src/artifacts/sets/MagArtifact.h
        src/artifacts/sets/UndeadArtifact.h src/artifacts/sets/AssassinArtifact.h
        # Сеты скилов #
        src/skills/sets/WarriorSkills.h src/skills/sets/ArcherSkills.h src/skills/sets/MagSkills.h src/skills/sets/PharaohSkills.h
        src/skills/sets/AssassinSkills.h
        # Противники #
        src/enemy/enemies/undead.h
        # Подземелья #
        src/dungeon/dungeons/LiteDungeon.h src/dungeon/dungeons/AverageDungeon.h src/dungeon/dungeons/HardDungeon.h
        # Армии #
        src/army/armies/Elves.h
        # Боссы #
        src/bosses/PharaohClass.h src/bosses/LichClass.h
        ManagementSave.cpp Headers/ManagementSave.h)

target_link_libraries(RPG PRIVATE nlohmann_json::nlohmann_json)

