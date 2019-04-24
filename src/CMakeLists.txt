CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Space-Battle)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

set (CMAKE_CXX_STANDARD 14)

SET(Qt5_COMPONENTS Core Gui Widgets Multimedia)
FIND_PACKAGE(Qt5 COMPONENTS ${Qt5_COMPONENTS} REQUIRED)

SET(HEADERS Game.h
            GameObjects/GameObject.h
            GameObjects/PlayerObject.h
            GameObjects/MovableObject.h
            GameObjects/Gunshells/Gunshell.h
            GameObjects/Weapons/Weapon.h
            GameObjects/Weapons/Bazooka.h
            GameObjects/Weapons/Machinegun.h
            GameObjects/Enemies/Enemy.h
            GameObjects/Enemies/EnemyDecorators/AbstractEnemyDecorator.h
            GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h
            HandWeapons/HandWeapon.h
            HandWeapons/HandGun.h
            HandWeapons/HandMachinegun.h
            HandWeapons/HandBazooka.h
            MoveStrategies/MoveStrategy.h
            MoveStrategies/MoveByLine.h
            MoveStrategies/MoveByCurve.h
            MoveStrategies/MoveByRandom.h
            SpecialObjects/Subjects/AbstractSubject.h
            SpecialObjects/Subjects/Score.h
            SpecialObjects/Subjects/Level.h
            SpecialObjects/Subjects/Health.h
            SpecialObjects/Observers/AbstractObserver.h
            SpecialObjects/Observers/ScoreObserver.h
            SpecialObjects/Observers/LevelObserver.h
            SpecialObjects/Observers/HealthObserver.h
            SpecialObjects/Observers/LabelObserver.h
            Visitors/AbstractVisitor.h
            Visitors/MoveVisitor.h
            LevelFactories/AbstractLevelFactory.h
            LevelFactories/Level1Factory.h
            LevelFactories/Level2Factory.h
            LevelFactories/Level3Factory.h
            GameObjectBuilders/GameObjectBuilder.h
            GameObjectBuilders/PresetPositionBuilder.h
)

SET(SOURCES Game.cpp
            GameObjects/GameObject.cpp
            GameObjects/PlayerObject.cpp
            GameObjects/MovableObject.cpp
            GameObjects/Gunshells/Gunshell.cpp
            GameObjects/Weapons/Weapon.cpp
            GameObjects/Weapons/Bazooka.cpp
            GameObjects/Weapons/Machinegun.cpp
            GameObjects/Enemies/Enemy.cpp
            GameObjects/Enemies/EnemyDecorators/AbstractEnemyDecorator.cpp
            GameObjects/Enemies/EnemyDecorators/ShieldDecorator.cpp
	    HandWeapons/HandWeapon.cpp
            HandWeapons/HandGun.cpp
            HandWeapons/HandMachinegun.cpp
            HandWeapons/HandBazooka.cpp
            MoveStrategies/MoveStrategy.cpp
            MoveStrategies/MoveByLine.cpp
            MoveStrategies/MoveByCurve.cpp
            MoveStrategies/MoveByRandom.cpp
            SpecialObjects/Subjects/AbstractSubject.cpp
            SpecialObjects/Subjects/Score.cpp
            SpecialObjects/Subjects/Level.cpp
            SpecialObjects/Subjects/Health.cpp
            SpecialObjects/Observers/ScoreObserver.cpp
            SpecialObjects/Observers/LevelObserver.cpp
            SpecialObjects/Observers/HealthObserver.cpp
            Visitors/MoveVisitor.cpp
            LevelFactories/AbstractLevelFactory.cpp
            LevelFactories/Level1Factory.cpp
            LevelFactories/Level2Factory.cpp
            LevelFactories/Level3Factory.cpp
            GameObjectBuilders/GameObjectBuilder.cpp
            GameObjectBuilders/PresetPositionBuilder.cpp
)

SET(LIBS Qt5::Core
         Qt5::Gui
         Qt5::Widgets
         Qt5::Multimedia
)

SET(RESOURCES ../resources/res.qrc)

ADD_EXECUTABLE(${PROJECT_NAME} ../main.cpp ${SOURCES} ${HEADERS} ${RESOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${LIBS})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
