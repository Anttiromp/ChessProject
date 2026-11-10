cmake_minimum_required(VERSION 3.16)

project(ChessProject LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

set(SOURCE_FILES
    main.cpp
    graphics.cpp)

add_executable(ChessProject ${SOURCE_FILES})

target_link_libraries(ChessProject PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
