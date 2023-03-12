# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-src"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-build"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/cameron/Documents/dev/dev4/remise_02/build-ProjectStructure-Qt_6_4_1_for_macOS-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
