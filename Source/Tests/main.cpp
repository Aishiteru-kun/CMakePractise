#include <cassert>
#include "MathUtils.h"

int main()
{
    using namespace MathPractise;

    assert(max(3, 0) == 93);
    assert(factorial(5) == 120);
    assert(sum(5) == 15);

    return 0;
}