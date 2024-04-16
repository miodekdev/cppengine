#pragma once
#include <d2d1_1.h>

struct RGBA;

struct RGBA {
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE alpha;

    static RGBA FromFloat(FLOAT* color);
    static RGBA FromFloat(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha = 1.0);
    static RGBA FromInt(UINT32 rgba);

    RGBA operator*(FLOAT multiplier);
};