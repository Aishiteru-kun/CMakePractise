# General Information
cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME CMakePractise)
set(PROJECT_NAME_TESTS ${PROJECT_NAME}TestRunner)
set(PROJECT_NAME_GAME ${PROJECT_NAME}Lib)

project(${PROJECT_NAME} VERSION 1.0.0)

message("----- Practise in Project ${PROJECT_NAME} -----")

# Common Options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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
set(SOURCE_TESTS_DIR ${SOURCE_DIR}/Tests)

set(PUBLIC_INCLUDE_GAME_DIR ${SOURCE_GAME_DIR}/Public)
set(PRIVATE_SOURCES_GAME_DIR ${SOURCE_GAME_DIR}/Private)

set(PUBLIC_INCLUDE_UTILS_DIR ${SOURCE_UTILS_DIR}/Public)
set(PRIVATE_SOURCES_UTILS_DIR ${SOURCE_UTILS_DIR}/Private)

set(PUBLIC_INCLUDE_TESTS_DIR ${SOURCE_TESTS_DIR}/Public)
set(PRIVATE_SOURCES_TESTS_DIR ${SOURCE_TESTS_DIR}/Private)

set(SOURCES ${SOURCE_DIR}/main.cpp)

set(MATH_SOURCES ${PRIVATE_SOURCES_UTILS_DIR}/MathUtils.cpp)
set(MATH_INCLUDES ${PUBLIC_INCLUDE_UTILS_DIR}/MathUtils.h)

set(DLL_GAME_SOURCES ${PRIVATE_SOURCES_GAME_DIR}/Character.cpp)
set(DLL_GAME_INCLUDES ${PUBLIC_INCLUDE_GAME_DIR}/Character.h)

# Game group
set(SOURCE_FILES_GAME "Source files/Game")
set(HEADER_FILES_GAME "Header files/Game")

source_group("${SOURCE_FILES_GAME}" FILES "${PRIVATE_SOURCES_GAME_DIR}/Character.cpp")
source_group("${HEADER_FILES_GAME}" FILES "${PUBLIC_INCLUDE_GAME_DIR}/Character.h")

message("SOURCES: ${SOURCES})")
message("INCLUDES: ${INCLUDES}")

# Targets
add_executable(${PROJECT_NAME} ${SOURCES})

add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
add_library(${PROJECT_NAME_GAME} SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})

add_executable(${PROJECT_NAME_TESTS} ${SOURCE_TESTS_DIR}/main.cpp)

target_compile_definitions(${PROJECT_NAME_GAME} PRIVATE _EXPORTING)
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)

option(SKIP_GAME_OPTION "Skip game" OFF)
if (SKIP_GAME_OPTION)
    target_compile_definitions(${PROJECT_NAME} PUBLIC SKIP_GAME)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME_GAME})
target_link_libraries(${PROJECT_NAME_GAME} PRIVATE MathLib)

target_link_libraries(${PROJECT_NAME_TESTS} PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME_TESTS} PRIVATE ${PROJECT_NAME_GAME})

# Includes

set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME_TESTS} ${PROJECT_NAME_GAME})
foreach (TARGET IN LISTS TARGETS)
    target_include_directories(${TARGET} PUBLIC ${PUBLIC_INCLUDE_GAME_DIR} PUBLIC ${PUBLIC_INCLUDE_UTILS_DIR})
endforeach ()

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
