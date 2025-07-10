cmake_minimum_required(VERSION 3.15)
project(SmartChargeHub VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/firmware/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/firmware/include/*.h"
)
include_directories(${CMAKE_SOURCE_DIR}/firmware/include)
add_executable(SmartChargeHub ${SRC_FILES})