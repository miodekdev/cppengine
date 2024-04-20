#include "color.hpp"

RGBA::RGBA():
        red(0),
        green(0),
        blue(0),
        alpha(255) {}

RGBA::RGBA(BYTE red, BYTE green, BYTE blue, BYTE alpha):
        red(red),
        blue(blue),
        green(green),
        alpha(alpha) {}

RGBA::RGBA(__m128 rgba) {*this = RGBA(_mm_cvtps_epi32(rgba));}

RGBA::RGBA(__m128i rgba) {
    rgba = _mm_packs_epi32(rgba, rgba);
    rgba = _mm_packus_epi16(rgba, rgba);
    UINT32 result = _mm_cvtsi128_si32(rgba);
    *this = *reinterpret_cast<RGBA*>(&result);
}

RGBA RGBA::operator * (FLOAT multiplier) const {
    auto multiplicands = static_cast<__m128>(*this);
    __m128 multipliers = _mm_set1_ps(multiplier);
    return RGBA(_mm_mul_ps(multiplicands, multipliers));
}

RGBA RGBA::operator / (FLOAT divisor) const {return *this * (1/divisor);}

RGBA RGBA::operator - () const {
    return RGBA{static_cast<BYTE>(255-red), static_cast<BYTE>(255-green), static_cast<BYTE>(255-blue), alpha};
}

RGBA::operator __m128i() const {
    const __m128i zero{};
    __m128i rgba = _mm_loadu_si32(this);
    rgba = _mm_unpacklo_epi8(rgba, zero);
    rgba = _mm_unpacklo_epi16(rgba, zero);
    return rgba;
}

RGBA::operator __m128() const {
    return _mm_cvtepi32_ps(static_cast<__m128i>(*this));
}