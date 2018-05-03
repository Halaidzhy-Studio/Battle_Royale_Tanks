#ifndef GAMEPHYSICSENGINEIMPL_H
#define GAMEPHYSICSENGINEIMPL_H

#include <memory>
#include <Box2D.h>
#include "libconfig.h++"
#include "gamephysicsengine.h"
#include "gameobject.h"

class GamePhysicsEngineImpl: public GamePhysicsEngine
{
public:
    GamePhysicsEngineImpl(const std::shared_ptr<libconfig::Config> config);
    // GamePhysicsEngine interface
    void updateGame() override;
    void createObjectInWorld(GameObject& gameObject) override;
    void test();
private:
    std::shared_ptr<libconfig::Config> config_;
    std::unique_ptr<b2World> b2World_;
    float timeStep_;
    int velocityIteration_;
    int positionIterations_;

    // GamePhysicsEngine interface
public:
    void createObjectInWorld(GameObject gameObject);
};

#endif // GAMEPHYSICSENGINEIMPL_H
