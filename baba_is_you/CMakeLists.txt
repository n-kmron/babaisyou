cmake_minimum_required(VERSION 3.5)

project(baba_is_you LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#comment : ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

#ajouter les fichiers ici
add_executable(baba_is_you main.cpp)

install(TARGETS baba_is_you
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
