#pragma once

// clang-format off
#if defined(WIN32) || defined(_WINDOWS)
    #ifdef _EXPORTING
        #define GAME_API __declspec(dllexport)
    #elif _IMPORTING
        #define GAME_API __declspec(dllimport)
    #else
        #define GAME_API
    #endif
#else
    #define MATH_API __attribute__((visibility("default")))
#endif
// clang-format on

class GAME_API Character
{
public:
    Character();
    ~Character();

    void Test();
    void PrintStatus();
};