#pragma once
#include <cmath>
#include <concepts>
#include <utility>
#include <iostream>
#include <type_traits>

static class MathHelper{
public:
    static const float PI;
    static float fwrap(float x, float min, float max);
};