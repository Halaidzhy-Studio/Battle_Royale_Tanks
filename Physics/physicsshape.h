#ifndef PHYSICSSHAPE_H
#define PHYSICSSHAPE_H
#include <Physics/vec2d.h>
struct MassData
{
    double mass;
    Vec2D center;
    double I;
};

class PhysicsShape{
public:
    virtual ~PhysicsShape() = default;
    virtual void setAsBox(double w, double h) = 0;
};

#endif // PHYSICSSHAPE_H
