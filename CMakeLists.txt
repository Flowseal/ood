cmake_minimum_required(VERSION 3.10.0)
project(figures VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(lab1 lab1/main.cpp)
target_compile_features(lab1 PRIVATE cxx_std_17)
target_link_libraries(lab1 PRIVATE SFML::Graphics)

add_executable(lab2 lab2/main.cpp)
target_compile_features(lab2 PRIVATE cxx_std_17)
target_link_libraries(lab2 PRIVATE SFML::Graphics)

add_executable(lab3 lab3/main.cpp)
target_compile_features(lab3 PRIVATE cxx_std_17)
target_link_libraries(lab3 PRIVATE SFML::Graphics)