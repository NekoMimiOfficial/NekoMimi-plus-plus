cmake_minimum_required(VERSION 3.5.0)
project(NekoMimi-plus-plus-Test)

set (CMAKE_CXX_STANDARD_REQUIRED 20)
set (CMAKE_CXX_STANDARD 20)

set (FullOutputDir "${CMAKE_SOURCE_DIR}/run")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static_libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(header)

add_library(out_tools STATIC ./header/outTools.cpp)
add_library(converter STATIC ./header/Converters.cpp)

add_executable("${PROJECT_NAME}_color" ./tests/color.cpp)
target_link_libraries("${PROJECT_NAME}_color" out_tools)

add_executable("${PROJECT_NAME}_convert" ./tests/convert.cpp)
target_link_libraries("${PROJECT_NAME}_convert" converter)
