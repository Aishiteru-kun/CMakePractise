# General Information
cmake_minimum_required(VERSION 4.0)
set(PROJECT_NAME CMakePractiseFresh)
project(${PROJECT_NAME} VERSION 1.0.0)

message("----- Practise in Project ${PROJECT_NAME} -----")

# Common Options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)

set(CMAKE_SUPPRESS_REGENERATION ON)

# cpp Options
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} /FA")

# Application Options

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

set(SOURCE_GAME_DIR ${SOURCE_DIR}/Game)
set(SOURCE_UTILS_DIR ${SOURCE_DIR}/Utils)

set(PUBLIC_INCLUDE_GAME_DIR ${SOURCE_GAME_DIR}/Public)
set(PRIVATE_SOURCES_GAME_DIR ${SOURCE_GAME_DIR}/Private)

set(PUBLIC_INCLUDE_UTILS_DIR ${SOURCE_UTILS_DIR}/Public)
set(PRIVATE_SOURCES_UTILS_DIR ${SOURCE_UTILS_DIR}/Private)

set(SOURCES
        ${SOURCE_DIR}/main.cpp

        ${PRIVATE_SOURCES_GAME_DIR}/Character.cpp
        ${PRIVATE_SOURCES_UTILS_DIR}/MathUtils.cpp
)

set(INCLUDES
        ${PUBLIC_INCLUDE_GAME_DIR}/Character.h
        ${PUBLIC_INCLUDE_UTILS_DIR}/MathUtils.h
)

# Utils group
set(SOURCE_FILES_UTILS "Source files/Utils")
set(HEADER_FILES_UTILS "Header files/Utils")

source_group("${SOURCE_FILES_UTILS}" FILES "${PRIVATE_SOURCES_UTILS_DIR}/MathUtils.cpp")
source_group("${HEADER_FILES_UTILS}" FILES "${PUBLIC_INCLUDE_UTILS_DIR}/MathUtils.h")

# Game group
set(SOURCE_FILES_GAME "Source files/Game")
set(HEADER_FILES_GAME "Header files/Game")

source_group("${SOURCE_FILES_GAME}" FILES "${PRIVATE_SOURCES_GAME_DIR}/Character.cpp")
source_group("${HEADER_FILES_GAME}" FILES "${PUBLIC_INCLUDE_GAME_DIR}/Character.h")

message("SOURCES: ${SOURCES})")
message("INCLUDES: ${INCLUDES}")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCLUDE_GAME_DIR} PUBLIC ${PUBLIC_INCLUDE_UTILS_DIR})
message("PUBLIC_INCLUDE_GAME_DIR: ${PUBLIC_INCLUDE_GAME_DIR}")
message("PUBLIC_INCLUDE_UTILS_DIR: ${PUBLIC_INCLUDE_UTILS_DIR}")

message("Using ${CMAKE_CXX_COMPILER_ID} compiler")

if (WIN32)
    message("Running on Windows")
elseif (LINUX)
    message("Running on Linux")
endif ()

if (MSVC)
    message("Using MSVC")
    message("MSVC version: ${MSVC_VERSION}")
    message("MSVC toolset: ${MSVC_TOOLSET_VERSION}")

    target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
endif ()

if (MSVC_TOOLSET_VERSION EQUAL 143)
    message("MSVC TOOLSET is equal to 143")
endif ()

message("Compiler flags: ${CMAKE_CXX_FLAGS}")
message("Compiler debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message("Compiler release flags: ${CMAKE_CXX_FLAGS_RELEASE}")

message("Configuration: ${CMAKE_CONFIGURATION_TYPES}")
