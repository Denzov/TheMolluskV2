cmake_minimum_required(VERSION 3.16)
project(TheMollusk)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib 5.5 REQUIRED)

include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported OUTPUT ipo_error)

if(ipo_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE)
    message("LTO SUPPORTED")
else()
    message(WARNING "LTO ${ipo_error}")
endif()

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/core/*.cpp"
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    string(REPLACE "-O2" "-O3" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
endif()

add_executable(TheMollusk ${SOURCES})


target_include_directories(TheMollusk PUBLIC core core/GameObjects/EntityObjects)

target_link_libraries(TheMollusk PRIVATE raylib)