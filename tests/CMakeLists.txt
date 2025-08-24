cmake_minimum_required(VERSION 3.5.0)
project(NMPP_Tests VERSION 0.1.4)

include_directories(../header/)
include_directories(../source/)
include_directories(../objects/)
include_directories(.)

set (CMAKE_CXX_STANDARD_REQUIRED 20)
set (CMAKE_CXX_STANDARD 20)

set (FullOutputDir "${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

link_directories(../objects/)

add_executable(${PROJECT_NAME}-color ./color.cpp)
add_executable(${PROJECT_NAME}-convert ./convert.cpp)
add_executable(${PROJECT_NAME}-files ./files.cpp)

target_link_libraries(${PROJECT_NAME}-color NMPP)
target_link_libraries(${PROJECT_NAME}-convert NMPP)
target_link_libraries(${PROJECT_NAME}-files NMPP)
