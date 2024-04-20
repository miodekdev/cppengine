#pragma once
#include <d2d1_1.h>

struct RGBA { // TODO replace RGBA with RGB (alpha byte will become reserved)
    BYTE red{};
    BYTE green{};
    BYTE blue{};
    BYTE alpha{};

public:
    explicit RGBA();
    RGBA(BYTE red, BYTE green, BYTE blue, BYTE alpha = 255);

    RGBA operator - () const;
    RGBA operator * (FLOAT multiplier) const;
    RGBA operator * (DOUBLE multiplier) const; // TODO
    RGBA operator / (FLOAT divisor) const;
    RGBA operator / (DOUBLE divisor) const; // TODO

private:
    explicit RGBA(__m128 rgba);  // These functions are private, because they don't take endianness into account
    explicit RGBA(__m128i rgba); // and take arguments as they are.
    explicit RGBA(__m256 rgba); // TODO
    explicit RGBA(__m256i rgba); // TODO
    explicit operator __m128() const;
    explicit operator __m128i() const;
    explicit operator __m256() const; // TODO
    explicit operator __m256i() const; // TODO
};