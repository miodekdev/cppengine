#pragma once
#include <d2d1_1.h>

struct RGBA {
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

public:
    RGBA();
    RGBA(__m128 rgba);
    RGBA(UINT32 rgba);
    RGBA(BYTE red, BYTE blue, BYTE green, BYTE alpha = 255);
    RGBA operator * (FLOAT multiplier);
    RGBA operator / (FLOAT multiplier);
    operator UINT32 ();
};