#include "color.hpp"

RGBA::RGBA(__m128 rgba) {
    __m128 multiplier = {255, 255, 255, 255};
    rgba = _mm_mul_ps(rgba, multiplier);
    __m128i xmm1 = _mm_cvtps_epi32(rgba);
    xmm1 = _mm_packs_epi32(xmm1, xmm1);
    xmm1 = _mm_packus_epi16(xmm1, xmm1);
    UINT32 result = _mm_cvtsi128_si32(xmm1);
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

RGBA::RGBA(UINT32 rgba):
    red((rgba >> 24) & 0xFF),
    green((rgba >> 16) & 0xFF),
    blue((rgba >> 8) & 0xFF),
    alpha(rgba & 0xFF) {}

RGBA RGBA::operator * (FLOAT multiplier) const { // TODO fix, test
    __m128i xmm0 = _mm_loadu_si32(this);
    __m128 xmm1 = _mm_load_ps(&multiplier);
    __m128i zero{};
    xmm0 = _mm_unpacklo_epi8(xmm0, zero);
    xmm0 = _mm_unpacklo_epi16(xmm0, zero);
    // TODO store alpha in a buffer so it wont be affected
    __m128 xmm2 = _mm_cvtepi32_ps(xmm0);
    xmm1 = _mm_shuffle_ps(xmm1, xmm1, 0);
    xmm2 = _mm_mul_ps(xmm2, xmm1);
    return RGBA(xmm2);
}

RGBA RGBA::operator / (FLOAT divisor) const {
    return *this * (1/divisor);
}

RGBA RGBA::operator - () const {
    return RGBA{static_cast<BYTE>(255-red), static_cast<BYTE>(255-green), static_cast<BYTE>(255-blue), alpha};
}

RGBA::operator UINT32() const {
    BYTE littleEndian[4] = {alpha, blue, green, red};
    return *reinterpret_cast<UINT32*>(littleEndian); // IMPORTANT: This code assumes that little endian is used
    BYTE bigEndian[4] = {red, green, blue, alpha};
    return *reinterpret_cast<UINT32*>((&red < &alpha) ? littleEndian : bigEndian);
}