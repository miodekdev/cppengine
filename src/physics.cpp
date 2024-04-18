#include "physics.hpp"
#include <immintrin.h>

using namespace physics;

extern "C" {
    float AsmVectorDistance(Vector vector1, Vector vector2);
    float AsmVectorMagnitude(Vector* vector);
    Vector AsmVectorNormalized(Vector* vector);
}
// TODO Compare performance - intrinsics vs assembly
float Vector::Distance(Vector vector1, Vector vector2) {
    __m128 xmm0 = _mm_load_ps((float*) &vector1);
    __m128 xmm1 = _mm_load_ps((float*) &vector2);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    xmm0 = _mm_mul_ps(xmm0, xmm0);
    xmm0 = _mm_hadd_ps(xmm0, xmm0);
    xmm0 = _mm_sqrt_ss(xmm0);
    return _mm_cvtss_f32(xmm0);
}

float Vector::Magnitude() {
    __m128 xmm0 = _mm_load_ss(&x);
    __m128 xmm1 = _mm_load_ss(&y);
    xmm0 = _mm_mul_ss(xmm0, xmm0);
    xmm1 = _mm_mul_ss(xmm1, xmm1);
    xmm0 = _mm_add_ss(xmm0, xmm1);
    xmm0 = _mm_sqrt_ss(xmm0);
    return _mm_cvtss_f32(xmm0);
}

Vector Vector::Normalized() { // TODO fix
    float magnitude = this->Magnitude();
    __m128 xmm0 = _mm_load_ps((float*) this);
    __m128 xmm1 = _mm_load_ss(&magnitude);
    xmm1 = _mm_moveldup_ps(xmm1);
    xmm0 = _mm_div_ps(xmm0, xmm1);
    float result[4];
    _mm_store_ps(result, xmm0);
    return *(Vector*) (result+8);
}
void Body::ApplySpeed() {
    __m128 xmm0 = _mm_load_ps((float*) &position);
    __m128 xmm1 = _mm_load_ps((float*) &speed);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    _mm_storeu_si64(&position, (__m128i) xmm0);
}