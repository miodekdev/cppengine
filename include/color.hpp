#pragma once
#include <d2d1_1.h>

struct RGBA {
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

public:
    explicit RGBA(UINT32 rgba);
    RGBA() : red(0), green(0), blue(0), alpha(0) {};
    RGBA(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha = 1.0);
    RGBA operator*(FLOAT multiplier);
    RGBA operator/(FLOAT multiplier);
    explicit operator UINT32();
private:
    explicit RGBA(__m128 xmm0);
};