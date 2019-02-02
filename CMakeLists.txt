CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(SpaceBattle)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

set (CMAKE_CXX_STANDARD 14)

SET(Qt5_COMPONENTS Core Gui Widgets Multimedia)
FIND_PACKAGE(Qt5 COMPONENTS ${Qt5_COMPONENTS} REQUIRED)

SET(HEADERS include/Game.h
            include/Score.h
            include/Health.h
            include/Level.h
            include/gameobjects/GameObject.h
            include/gameobjects/PlayerObject.h
            include/gameobjects/HeartObject.h
            include/gameobjects/MovableObject.h
            include/gameobjects/SpawnObject.h
            include/gameobjects/gunshells/Gunshell.h
            include/gameobjects/gunshells/Bullet.h
            include/gameobjects/gunshells/Rocket.h
            include/gameobjects/weapons/Weapon.h
            include/gameobjects/weapons/Machinegun.h
            include/gameobjects/weapons/Bazooka.h
            include/gameobjects/enemies/Enemy.h
            include/gameobjects/enemies/Enemy1.h
            include/gameobjects/enemies/Enemy2.h
            include/gameobjects/enemies/enemydecorators/AbstractEnemyDecorator.h
	    include/gameobjects/enemies/enemydecorators/ShieldDecorator.h
	    include/handweapons/HandWeapon.h
            include/handweapons/HandMachinegun.h
            include/handweapons/HandBazooka.h
            include/levelfactories/AbstractLevelFactory.h
            include/levelfactories/Level1Factory.h
            include/levelfactories/Level2Factory.h
            include/levelfactories/Level3Factory.h
)

SET(SOURCES src/Game.cpp
            src/Score.cpp
            src/Health.cpp
            src/Level.cpp
            src/gameobjects/GameObject.cpp
            src/gameobjects/PlayerObject.cpp
            src/gameobjects/HeartObject.cpp
            src/gameobjects/MovableObject.cpp
            src/gameobjects/SpawnObject.cpp
            src/gameobjects/gunshells/Gunshell.cpp
            src/gameobjects/gunshells/Bullet.cpp
            src/gameobjects/gunshells/Rocket.cpp
            src/gameobjects/weapons/Weapon.cpp
            src/gameobjects/weapons/Machinegun.cpp
            src/gameobjects/weapons/Bazooka.cpp
            src/gameobjects/enemies/Enemy.cpp
            src/gameobjects/enemies/Enemy1.cpp
            src/gameobjects/enemies/Enemy2.cpp
	    src/gameobjects/enemies/enemydecorators/AbstractEnemyDecorator.cpp
	    src/gameobjects/enemies/enemydecorators/ShieldDecorator.cpp
	    src/handweapons/HandWeapon.cpp
            src/handweapons/HandMachinegun.cpp
            src/handweapons/HandBazooka.cpp
	    src/levelfactories/AbstractLevelFactory.cpp
	    src/levelfactories/Level1Factory.cpp
            src/levelfactories/Level2Factory.cpp
            src/levelfactories/Level3Factory.cpp
)

SET(LIBS Qt5::Core
         Qt5::Gui
         Qt5::Widgets
         Qt5::Multimedia
)

SET(RESOURCES resources/res.qrc)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS} ${RESOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  PUBLIC ${LIBS})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/gunshells
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/enemies
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/enemies/enemydecorators
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/weapons
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/handweapons/
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/levelfactories/)
