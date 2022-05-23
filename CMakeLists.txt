cmake_minimum_required(VERSION 3.22)
project(Pong)

find_package(SFML 2.5 COMPONENTS network graphics audio REQUIRED)

add_library(scrLib
        scr/Defender.cpp
        scr/Ball.cpp
        )

target_link_libraries(scrLib PRIVATE sfml-network sfml-graphics sfml-audio)

add_executable(Pong scr/main.cpp)
target_link_libraries(Pong scrLib)
