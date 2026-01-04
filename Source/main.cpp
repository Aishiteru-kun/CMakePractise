#include <iostream>
#include "Game/Public/Character.h"

int main()
{
#ifdef SKIP_GAME
    std::cout << "Skipping Game Module" << std::endl;
    return 0;
#endif

    Character().Test();
    Character().PrintStatus();

    std::cin.get();

    return 0;
}