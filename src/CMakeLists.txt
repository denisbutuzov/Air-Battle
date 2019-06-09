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
)

SET(SOURCES Game.cpp
            GameObjects/GameObject.cpp
            GameObjects/PlayerObject.cpp
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
