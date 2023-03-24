cmake_minimum_required(VERSION 3.5)


#comment : ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")


# Ajouter le fichier texte
#set(txt_file "${CMAKE_CURRENT_SOURCE_DIR}/nom_fichier.txt")

#ajouter les fichiers ici
add_executable(ProjectStructure
    main.cpp
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
    #${txt_file}
)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
