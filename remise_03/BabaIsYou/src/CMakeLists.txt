cmake_minimum_required(VERSION 3.5)

set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})  # Adjust the path if necessary

#comment : ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

#ajouter les fichiers ici
add_executable(BabaIsYou
    main.cpp
    guiview.ui
    util.cpp
    consolecontroller.h
    consolecontroller.cpp
    guicontroller.h
    guicontroller.cpp
    views/textview.h
    views/textview.cpp
    views/guiview.h
    views/guiview.cpp
    model/observer.h
    model/observable.h
    model/rulemanager.h
    model/game.h
    model/level.h
    model/levelloader.h
    model/element.h
    model/direction.h
    model/position.h
    model/gameobject.h
    model/levelmechanics.h
    model/rulemanager.cpp
    model/game.cpp
    model/levelloader.cpp
    model/position.cpp
    model/gameobject.cpp
    model/levelmechanics.cpp
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

target_link_libraries(BabaIsYou PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_sources(BabaIsYou PRIVATE ${SOURCES})


install(TARGETS BabaIsYou
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
