#pragma once

namespace physics {
    struct Vector {
        float x;
        float y;

        static float Distance(Vector vector1, Vector vector2);
        float Magnitude();
        Vector Normalized();
    };
    struct Body {
        Vector position;
        Vector speed;

        void ApplySpeed();
    };
}

