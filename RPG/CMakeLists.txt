cmake_minimum_required(VERSION 3.17)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG
        # Стартовый файл#
        main.cpp
        # Основные классы #
        src/hero/HeroClass.h src/skills/SkillClass.h src/artifacts/ArtifactClass.h
        # Классы персонажей #
        src/hero/grade/WarriorClass.h src/hero/grade/ArcherClass.h src/hero/grade/MagClass.h
        # Сеты артефактов #
        src/artifacts/ArcherArtifact.h src/artifacts/WarriorArtifact.h src/artifacts/MagArtifact.h
        # Сеты скилов #
        src/skills/WarriorSkills.h src/skills/ArcherSkills.h src/skills/MagSkills.h
        )
