#include "physics.hpp"

using namespace physics;

extern "C" {
    float AsmVectorDistance(Vector vector1, Vector vector2);
    float AsmVectorMagnitude(Vector* vector);
    Vector AsmVectorNormalized(Vector* vector);
    void AsmBodyApplySpeed(Body* body);
}

float Vector::Distance(Vector vector1, Vector vector2) {return AsmVectorDistance(vector1, vector2);}
float Vector::Magnitude() {return AsmVectorMagnitude(this);}
Vector Vector::Normalized() {return AsmVectorNormalized(this);}
void Body::ApplySpeed() {return AsmBodyApplySpeed(this);}