#include "color.hpp"

static RGBA FloatsToRGBA(__m128 xmm0) {
    __m128i xmm1 = _mm_cvtps_epi32(xmm0);
    xmm1 = _mm_packs_epi32(xmm1, xmm1);
    xmm1 = _mm_packus_epi16(xmm1, xmm1);
    return RGBA(_mm_cvtsi128_si32(xmm1));
}

RGBA::RGBA(__m128 xmm0) {
    __m128 xmm1 = {255, 255, 255, 255};
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    *this = FloatsToRGBA(xmm0);
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

RGBA RGBA::operator*(FLOAT multiplier) {
    __m128i xmm0 = _mm_cvtsi32_si128(); //TODO
    __m128 xmm1;
    _mm_store_ss(&multiplier, xmm1);
}

RGBA RGBA::operator/(FLOAT multiplier) {
    return this->operator*(1/multiplier);
}
