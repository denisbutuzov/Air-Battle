CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(AirBattle)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

SET(Qt5_COMPONENTS Core Gui Widgets Multimedia)
FIND_PACKAGE(Qt5 COMPONENTS ${Qt5_COMPONENTS} REQUIRED)

SET(HEADERS include/Game.h
            include/gameobjects/GameObject.h
            include/gameobjects/PlayerObject.h
            include/gameobjects/MovableObject.h
            include/gameobjects/SpawnObject.h
            include/gameobjects/gunshells/Gunshell.h
            include/gameobjects/gunshells/Bullet.h
            include/gameobjects/gunshells/Rocket.h
            include/gameobjects/weapons/Weapon.h
            include/gameobjects/weapons/Machinegun.h
            include/gameobjects/weapons/Bazooka.h
            include/gameobjects/enemies/Enemy.h
            include/handweapons/IHandWeapon.h
            include/handweapons/HandMachinegun.h
            include/handweapons/HandBazooka.h
)

SET(SOURCES src/Game.cpp
            src/gameobjects/GameObject.cpp
            src/gameobjects/PlayerObject.cpp
            src/gameobjects/MovableObject.cpp
            src/gameobjects/SpawnObject.cpp
            src/gameobjects/gunshells/Gunshell.cpp
            src/gameobjects/gunshells/Bullet.cpp
            src/gameobjects/gunshells/Rocket.cpp
            src/gameobjects/weapons/Weapon.cpp
            src/gameobjects/weapons/Machinegun.cpp
            src/gameobjects/weapons/Bazooka.cpp
            src/gameobjects/enemies/Enemy.cpp
            src/handweapons/HandMachinegun.cpp
            src/handweapons/HandBazooka.cpp
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
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/gameobjects/weapons
                                                  ${CMAKE_CURRENT_SOURCE_DIR}/include/handweapons/)
