cmake_minimum_required (VERSION 2.8)
project(TicTacToe)
aux_source_directory(. DIRSRC)
add_executable(TicTacToe ${DIRSRC}) 

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
