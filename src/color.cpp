#include "color.hpp"

extern "C" {
    RGBA AssemblyRGBAFromFloatArray(FLOAT* color);
    RGBA AssemblyRGBAFromFloats(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha);
    RGBA AssemblyRGBAFromInt(UINT32 rgba);
    RGBA AssemblyRGBAFromByte(BYTE brightness, BYTE opacity);
}

RGBA RGBA::FromFloat(FLOAT* color) {
    return AssemblyRGBAFromFloatArray(color);
}

RGBA RGBA::FromFloat(FLOAT red, FLOAT green, FLOAT blue, FLOAT alpha) {
    return AssemblyRGBAFromFloats(red, green, blue, alpha);
}

RGBA RGBA::FromInt(UINT32 rgba) {
    return AssemblyRGBAFromInt(rgba);
}

RGBA RGBA::FromByte(BYTE brightness, BYTE alpha) {
    return AssemblyRGBAFromByte(brightness, alpha);
}