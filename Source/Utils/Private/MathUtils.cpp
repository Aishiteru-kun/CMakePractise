// MathUtils.cpp
#include "../Public/MathUtils.h"

#include <vector>

namespace MathPractise {
    int max(int x, int y)
    {
        return x > y ? x : y;
    }

    int factorial(int n)
    {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }

    int sum(int n)
    {
        return n <= 0 ? 0 : n + sum(n - 1);
    }

    std::vector<int> createLargeVector()
    {
        std::vector<int> vec(100000000, 12);
        return vec;
    }
}
