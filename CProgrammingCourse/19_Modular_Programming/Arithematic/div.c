#include "div.h"

float divide(int x, int y)
{
    if (y == 0)
        return 0.0f; // Handle divide-by-zero
    return (float)x / y;
}
