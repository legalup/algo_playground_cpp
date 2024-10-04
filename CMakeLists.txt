cmake_minimum_required(VERSION 3.17)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)


project(gp)
add_executable( gp graphprob_play.cpp algo.h)
add_definitions(-g -Wreturn-type -Wcomment -Wunused-variable -Wunused-parameter -Wno-sign-compare)
