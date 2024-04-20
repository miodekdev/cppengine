#include "color.hpp"

RGBA::RGBA(__m128 rgba) {
    const __m128 multiplier{255, 255, 255, 255};
    rgba = _mm_mul_ps(rgba, multiplier);
    *this = RGBA(_mm_cvtps_epi32(rgba));
}

RGBA::RGBA(__m128i rgba) {
    rgba = _mm_packs_epi32(rgba, rgba);
    rgba = _mm_packus_epi16(rgba, rgba);
    UINT32 result = _mm_cvtsi128_si32(rgba);
    *this = *reinterpret_cast<RGBA*>(&result);
}

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

RGBA RGBA::operator * (FLOAT multiplier) const { // TODO fix, test

}

RGBA RGBA::operator / (FLOAT divisor) const {
    return *this * (1/divisor);
}

RGBA RGBA::operator - () const {
    return RGBA{static_cast<BYTE>(255-red), static_cast<BYTE>(255-green), static_cast<BYTE>(255-blue), alpha};
}

RGBA::operator __m128() {
    const __m128 zero{};
    __m128i rgba = _mm_loadu_si32(this);
    rgba = _mm_unpacklo_epi8(rgba, zero);
    rgba = _mm_unpackhi_epi16(rgba, zero);
    return _mm_cvtepi32_ps(rgba);
}