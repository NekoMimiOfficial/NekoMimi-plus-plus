cmake_minimum_required(VERSION 3.5.0)
project(NekoMimi-plus-plus VERSION 1.0.7)

set (CMAKE_CXX_STANDARD_REQUIRED 20)
set (CMAKE_CXX_STANDARD 20)

set (FullOutputDir "${CMAKE_SOURCE_DIR}/objects")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static_libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(header)
include_directories(source)

add_library(NMPP SHARED
  ./source/meta.cpp
  ./source/Utils.cpp
  ./source/FileIO.cpp
  ./source/outTools.cpp
  ./source/Operators.cpp
  ./source/Conditions.cpp
  ./source/Converters.cpp
  ./source/BinaryReader.cpp
)

set_target_properties(NMPP PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  PUBLIC_HEADER ./header/Utils.hpp
  PUBLIC_HEADER ./header/FileIO.hpp
  PUBLIC_HEADER ./header/outTools.hpp
  PUBLIC_HEADER ./header/Operators.hpp
  PUBLIC_HEADER ./header/Conditions.hpp
  PUBLIC_HEADER ./header/Converters.hpp
  PUBLIC_HEADER ./header/BinaryReader.hpp
)
