#include "../Public/Character.h"

#include <iostream>

#include "MathUtils.h"

Character::Character()
{
    // Constructor implementation
}

Character::~Character()
{
    // Destructor implementation
}

void Character::Test()
{
    using namespace MathPractise;

    const int Result = max(10, 20);
    const int ResultFactorial = factorial(10);
    const int ResultSum = sum(10);
    const int GlobalResult = Result + ResultFactorial + ResultSum;
    const std::vector<int> Vector = createLargeVector();

    std::cout << "Global Result: " << GlobalResult << std::endl;
    std::cout << "Size: " << Vector.size() << std::endl;
}

void Character::PrintStatus()
{
    std::cout << "Random Status: " << MathPractise::randomInt(0, 100) << std::endl;
}