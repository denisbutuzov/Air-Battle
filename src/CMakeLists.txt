CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Space-Battle)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)

SET(CMAKE_CXX_STANDARD 14)

SET(Qt5_COMPONENTS Core Gui Widgets Multimedia)
FIND_PACKAGE(Qt5 COMPONENTS ${Qt5_COMPONENTS} REQUIRED)

SET(HEADERS additionals.h
            AppSettings.h
            GameWindow.h
            Game.h
            FactoryManager.h
            GameObjectStorage.h
            GameObjects/GameObject.h
            GameObjects/PlayerObject.h
            GameObjects/MovableObject.h
            GameObjects/Enemies/Enemy.h
            GameObjects/Enemies/EnemyDecorators/AbstractEnemyDecorator.h
            GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h
            GameObjects/Weapons/Weapon.h
            GameObjects/Weapons/Machinegun.h
            GameObjects/Weapons/Bazooka.h
            GameObjects/Bonuses/Bonus.h
            GameObjects/Bonuses/Detonation.h
            GameObjects/Gunshells/Gunshell.h
            HandWeapons/HandWeapon.h
            HandWeapons/HandGun.h
            HandWeapons/HandMachinegun.h
            HandWeapons/HandBazooka.h
            HandBonuses/HandBonus.h
            HandBonuses/HandDetonation.h
            MoveStrategies/MoveStrategy.h
            MoveStrategies/MoveByLine.h
            MoveStrategies/MoveByCurve.h
            LevelFactories/AbstractLevelFactory.h
            LevelFactories/Level1Factory.h
            LevelFactories/Level2Factory.h
            LevelFactories/Level3Factory.h
            LevelFactories/Level4Factory.h
            LevelFactories/Level5Factory.h
            SpecialObjects/Subjects/AbstractSubject.h
            SpecialObjects/Subjects/Level.h
            SpecialObjects/Subjects/Score.h
            SpecialObjects/Subjects/Health.h
            SpecialObjects/Subjects/Equipment.h
            SpecialObjects/Observers/AbstractObserver.h
            SpecialObjects/Observers/LabelObserver.h
            SpecialObjects/Observers/HealthObserver.h
            SpecialObjects/Observers/EquipmentObserver.h
            Visitors/AbstractVisitor.h
            Visitors/MoveVisitor.h
)

SET(SOURCES additionals.cpp
            AppSettings.cpp
            GameWindow.cpp
            Game.cpp
            FactoryManager.cpp
            GameObjectStorage.cpp
            GameObjects/GameObject.cpp
            GameObjects/PlayerObject.cpp
            GameObjects/MovableObject.cpp
            GameObjects/Enemies/Enemy.cpp
            GameObjects/Enemies/EnemyDecorators/AbstractEnemyDecorator.cpp
            GameObjects/Enemies/EnemyDecorators/ShieldDecorator.cpp
            GameObjects/Weapons/Weapon.cpp
            GameObjects/Weapons/Machinegun.cpp
            GameObjects/Weapons/Bazooka.cpp
            GameObjects/Bonuses/Bonus.cpp
            GameObjects/Bonuses/Detonation.cpp
            GameObjects/Gunshells/Gunshell.cpp
            HandWeapons/HandWeapon.cpp
            HandWeapons/HandGun.cpp
            HandWeapons/HandMachinegun.cpp
            HandWeapons/HandBazooka.cpp
            HandBonuses/HandBonus.cpp
            HandBonuses/HandDetonation.cpp
            MoveStrategies/MoveStrategy.cpp
            MoveStrategies/MoveByLine.cpp
            MoveStrategies/MoveByCurve.cpp
            LevelFactories/AbstractLevelFactory.cpp
            LevelFactories/Level1Factory.cpp
            LevelFactories/Level2Factory.cpp
            LevelFactories/Level3Factory.cpp
            LevelFactories/Level4Factory.cpp
            LevelFactories/Level5Factory.cpp
            SpecialObjects/Subjects/AbstractSubject.cpp
            SpecialObjects/Subjects/Level.cpp
            SpecialObjects/Subjects/Score.cpp
            SpecialObjects/Subjects/Health.cpp
            SpecialObjects/Subjects/Equipment.cpp
            SpecialObjects/Observers/HealthObserver.cpp
            SpecialObjects/Observers/EquipmentObserver.cpp
            Visitors/MoveVisitor.cpp
)

SET(LIBS Qt5::Core
         Qt5::Gui
         Qt5::Widgets
         Qt5::Multimedia
)

SET(UI GameWindow.ui)

SET(RESOURCES ../resources/res.qrc)

ADD_EXECUTABLE(${PROJECT_NAME} ../main.cpp ${SOURCES} ${HEADERS} ${RESOURCES} ${UI})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${LIBS})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
