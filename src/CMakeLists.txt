cmake_minimum_required(VERSION 3.1)

project(nikimultigame)

## If you want to link SFML statically
## set(SFML_STATIC_LIBRARIES TRUE)

list(APPEND myApp_sources
    main.cpp 
    util/element/ElementUtil.cpp
    util/resources/Resources.cpp
    util/resources/fonts/FontStorage.cpp
    mainmenu/MainMenu.cpp
    bepis_game/BepisClickerGame.cpp
    tictactoe_game/TicTacToeGame.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/src)
find_package(SFML 2.5.1 COMPONENTS graphics window REQUIRED)
add_executable(nikimultigame ${myApp_sources})


target_link_libraries(nikimultigame sfml-graphics sfml-window)
