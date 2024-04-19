#pragma once
#include <d2d1_1.h>

struct RGBA {
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

public:
    RGBA() = default;
    RGBA(__m128 rgba);
    RGBA(BYTE red, BYTE blue, BYTE green, BYTE alpha = 255);
    RGBA operator*(FLOAT multiplier);
    RGBA operator/(FLOAT multiplier);
};