#include "color.hpp"

extern "C" {
    RGBA AssemblyRGBAFromFloatArray(FLOAT* color);
    RGBA AssemblyMultiplyRGBAByFloat(RGBA color, FLOAT multiplier);
}

RGBA RGBA::FromFloat(FLOAT* color) {return AssemblyRGBAFromFloatArray(color);}

RGBA RGBA::FromFloat(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha) {
    FLOAT buffer[4] = {red, green, blue, alpha};
    return RGBA::FromFloat(buffer);
}

RGBA RGBA::FromInt(UINT32 rgba) {
    return *(RGBA*)(void*)&rgba;
}

RGBA RGBA::operator*(FLOAT multiplier) {
    return AssemblyMultiplyRGBAByFloat(*this, multiplier);
}