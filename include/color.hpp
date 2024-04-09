#pragma once
#include <d2d1_1.h>

struct RGBA;
struct HSV;

struct RGBA {
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE alpha;

    static RGBA FromFloat(FLOAT* color);
    static RGBA FromFloat(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha = 1.0);
    static RGBA FromInt(UINT32 rgba);
    static RGBA FromHSV(HSV color); //TODO
};

struct HSV {
    FLOAT hue;
    FLOAT saturation;
    FLOAT value;

    static HSV FromRGBA(RGBA color); //TODO
};