cmake_minimum_required(VERSION 3.16)
project(TheMollusk)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib 5.5 REQUIRED)

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/core/*.cpp"
)

add_executable(TheMollusk ${SOURCES})

target_include_directories(TheMollusk PUBLIC core)

target_link_libraries(TheMollusk PRIVATE raylib)