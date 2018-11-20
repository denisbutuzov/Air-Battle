CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(AirBattle)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

SET(Qt5_COMPONENTS Core Gui Widgets Multimedia)
FIND_PACKAGE(Qt5 COMPONENTS ${Qt5_COMPONENTS} REQUIRED)

SET(HEADERS include/Game.h
            include/Player.h
            include/Bullet.h
            include/Enemy.h
            include/Score.h
            include/Health.h
)

SET(SOURCES src/Game.cpp
            src/Player.cpp
            src/Bullet.cpp
            src/Enemy.cpp
            src/Score.cpp
            src/Health.cpp
)

SET(LIBS Qt5::Core
         Qt5::Gui
         Qt5::Widgets
         Qt5::Multimedia
)

#SET(RESOURCES resources/bullet.wav
#              resources/boom.wav)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS} ${RESOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  PUBLIC ${LIBS})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES RESOURCE ${RESOURCES})
