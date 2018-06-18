#ifndef PHYSICS_H
#define PHYSICS_H

#include <Physics/physicsbody.h>
class Physics
{
public:
    virtual ~Physics() = default;
    virtual std::shared_ptr<PhysicsBody> createBody(PhysicsBodyDef&) = 0;
    virtual void update() = 0;
};

#endif // PHYSICS_H
