cmake_minimum_required(VERSION 3.17)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG
        # Стартовый файл#
        main.cpp
        # Основные классы #
        src/hero/HeroClass.h src/skills/SkillClass.h src/artifacts/ArtifactClass.h src/enemy/EnemyClass.h
        # Классы персонажей #
        src/hero/grade/WarriorClass.h src/hero/grade/ArcherClass.h src/hero/grade/MagClass.h
        # Сеты артефактов #
        src/artifacts/sets/ArcherArtifact.h src/artifacts/sets/WarriorArtifact.h src/artifacts/sets/MagArtifact.h
        # Сеты скилов #
        src/skills/sets/WarriorSkills.h src/skills/sets/ArcherSkills.h src/skills/sets/MagSkills.h
        # Противники #
        src/enemy/enemies/undead.h
        )
