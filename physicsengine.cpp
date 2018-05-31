#include "physicsengine.h"

b2Body *PhysicsEngine::CreateBody(const b2BodyDef* body)
{
    return world_->CreateBody(body);
}
