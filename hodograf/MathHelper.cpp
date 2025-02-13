#include "MathHelper.h"

const float MathHelper::PI = 3.14159265358979323846;
float MathHelper::fwrap(float x, float min, float max)
{
    if (min > max) {
        std::swap(min, max);
    }
    return (x < 0 ? max : min) + std::fmod(x, max - min);
}
