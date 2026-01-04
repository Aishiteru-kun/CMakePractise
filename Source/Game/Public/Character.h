#pragma once

#ifdef _EXPORTING
#define GAME_API    __declspec(dllexport)
#elif _IMPORTING
#define GAME_API    __declspec(dllimport)
#else
#define GAME_API
#endif

class GAME_API Character {
public:
    Character();
    ~Character();

    void PrintStatus();
};