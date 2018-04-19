#include <Box2D.h>
#include "gamephysicsengineimpl.h"

GamePhysicsEngineImpl::GamePhysicsEngineImpl(): velocityIteration_(6),
    positionIterations_(2)
{
    b2Vec2 gravity(0.0f, 0.0f);
    b2World_ = std::make_unique<b2World>(gravity);
}

void GamePhysicsEngineImpl::updateGame(){
    b2World_ ->Step( timeStep_, velocityIteration_, positionIterations_);
}
