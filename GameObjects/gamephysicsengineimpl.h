#ifndef GAMEPHYSICSENGINEIMPL_H
#define GAMEPHYSICSENGINEIMPL_H

#include <memory>
#include <Box2D.h>
#include "gamephysicsengine.h"
class GamePhysicsEngineImpl: public GamePhysicsEngine
{
public:
    GamePhysicsEngineImpl();
    // GamePhysicsEngine interface
    void updateGame() override;
    void test();
private:
    std::unique_ptr<b2World> b2World_;
    float timeStep_;
    int velocityIteration_;
    int positionIterations_;
};

#endif // GAMEPHYSICSENGINEIMPL_H
