#pragma once
#include <WinDef.h>

namespace physics {
    struct Vector {
        FLOAT x;
        FLOAT y;

        static FLOAT Distance(Vector vector1, Vector vector2);
        FLOAT Magnitude();
        Vector Normalized();
    };
    struct Body {
        Vector position;
        Vector speed;

        void ApplySpeed();
    };
}