#pragma once
#include <d2d1_1.h>

struct RGBA { // TODO replace RGBA with RGB (alpha byte will become reserved)
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

public:
    explicit RGBA();
    explicit RGBA(FLOAT rgba[4]);
    explicit RGBA(FLOAT saturation, FLOAT alpha = 1);
    RGBA(BYTE red, BYTE green, BYTE blue, BYTE alpha = 255);

    RGBA operator - () const;
    RGBA operator * (FLOAT multiplier) const;
    RGBA operator / (FLOAT divisor) const;

private:
    explicit RGBA(__m128 rgba);
    explicit RGBA(__m128i rgba);
    explicit operator __m128() const;
    explicit operator __m128i() const;
};