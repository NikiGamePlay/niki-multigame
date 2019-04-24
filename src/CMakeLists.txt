cmake_minimum_required(VERSION 3.1)

project(nikimultigame)

list(APPEND myApp_sources
    ${CMAKE_SOURCE_DIR}/main.cpp 
    ${CMAKE_SOURCE_DIR}/util/element/ElementUtil.cpp
    ${CMAKE_SOURCE_DIR}/util/resources/Resources.cpp
    ${CMAKE_SOURCE_DIR}/util/resources/fonts/FontStorage.cpp
    ${CMAKE_SOURCE_DIR}/mainmenu/MainMenu.cpp
    ${CMAKE_SOURCE_DIR}/bepis_game/BepisClickerGame.cpp
    ${CMAKE_SOURCE_DIR}/tictactoe_game/TicTacToeGame.cpp
)
include_directories(${CMAKE_SOURCE_DIR})
find_package(SFML 2.5.1 COMPONENTS graphics window REQUIRED)
add_executable(nikimultigame ${myApp_sources})


target_link_libraries(nikimultigame sfml-graphics sfml-window)
