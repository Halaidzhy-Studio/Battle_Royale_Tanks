#ifndef PHYSICSFIXTURE_H
#define PHYSICSFIXTURE_H

#include <Physics/physicsshape.h>
#include <memory>
struct FixtureDef
{
    /// The constructor sets the default fixture definition values.
    FixtureDef()
    {
        shape = nullptr;
        userData = nullptr;
        friction = 0.2;
        restitution = 0.0;
        density = 0.0;
        isSensor = false;
    }

    std::shared_ptr<PhysicsShape> shape;

    /// Use this to store application specific fixture data.
    void* userData;

    /// The friction coefficient, usually in the range [0,1].
    double friction;

    /// The restitution (elasticity) usually in the range [0,1].
    double restitution;
    double density;

    /// A sensor shape collects contact information but never generates a collision
    /// response.
    bool isSensor;
};

class PhysicsFixture{
public:
    virtual ~PhysicsFixture() = default;

};

#endif // PHYSICSFIXTURE_H
