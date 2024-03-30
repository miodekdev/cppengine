#include "physics.hpp"

using namespace physics;

extern "C" {
    float AsmVectorDistance(Vector vector1, Vector vector2);
    float AsmVectorMagnitude(Vector* vector);
    Vector AsmVectorNormalized(Vector* vector);
    void AsmBodyApplySpeed(Body* body);
}

float Vector::Distance(Vector vector1, Vector vector2) {
    // Returns the distance between two points.
    return AsmVectorDistance(vector1, vector2);
}

float Vector::Magnitude() {
    // Returns the magnitude (length) of a vector.
    return AsmVectorMagnitude(this);
}

Vector Vector::Normalized() {
    // Normalizes a vector, making it a unit vector.
    return AsmVectorNormalized(this);
}

void Body::ApplySpeed() {
    // Adds the speed of a body to its position.
    return AsmBodyApplySpeed(this);
}