#include "color.hpp"

RGBA::RGBA(__m128 xmm0) { // TODO test
    __m128 multiplier = {255, 255, 255, 255};
    xmm0 = _mm_mul_ps(xmm0, multiplier);
    __m128i xmm1 = _mm_cvtps_epi32(xmm0);
    xmm1 = _mm_packs_epi32(xmm1, xmm1);
    xmm1 = _mm_packus_epi16(xmm1, xmm1);
    *this = RGBA(_mm_cvtsi128_si32(xmm1));
}

RGBA::RGBA(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha) {
    *this = RGBA(__m128{red, green, blue, alpha});
}

RGBA::RGBA(UINT32 rgba) {
    *this = *(RGBA*)(void*)&rgba;
}

RGBA::operator UINT32() {
    return *(UINT32*) (void*) this;
}

RGBA RGBA::operator*(FLOAT multiplier) { // TODO test
    __m128i xmm0 = _mm_cvtsi32_si128((UINT32) *this);
    __m128 xmm1 = _mm_load_ps(&multiplier);
    __m128 zero{};
    xmm0 = _mm_unpacklo_epi8(xmm0, zero);
    xmm0 = _mm_unpacklo_epi16(xmm0, zero);
    __m128 xmm2 = _mm_cvtepi32_ps(xmm0);
    xmm1 = _mm_shuffle_ps(xmm1, xmm1, 0);
    xmm2 = _mm_mul_ps(xmm2, xmm1);
    return RGBA(xmm2);
}

RGBA RGBA::operator/(FLOAT multiplier) {
    return this->operator*(1/multiplier);
}
