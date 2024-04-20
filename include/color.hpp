#pragma once
#include <d2d1_1.h>

struct RGBA {
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

    explicit RGBA();
    explicit RGBA(__m128 rgba);
    explicit RGBA(UINT32 rgba);
    RGBA(BYTE red, BYTE green, BYTE blue, BYTE alpha = 255);

    RGBA operator * (FLOAT multiplier);
    RGBA operator / (FLOAT multiplier);

    explicit operator UINT32 ();
};