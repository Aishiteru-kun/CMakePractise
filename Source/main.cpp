#include <iostream>
#include "Game/Public/Character.h"
#include "Utils/Public/MathUtils.h"

int main() {
	std::cout << "Hello, World!" << std::endl;

	using namespace MathPractise;

	const int Result = max(10, 20);
	const int ResultFactorial = factorial(10);
	const int ResultSum = sum(10);
	const int GlobalResult = Result + ResultFactorial + ResultSum;
	const std::vector<int> Vector = createLargeVector();

	std::cout << "Global Result: " << GlobalResult << std::endl;
	std::cout << "Size: " << Vector.size() << std::endl;

    Character().PrintStatus();

	std::cin.get();

    return 0;
}