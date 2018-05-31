#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <memory>
#include <Box2D.h>

class PhysicsEngine
{
public:
    PhysicsEngine() = default;
    b2Body* CreateBody(const b2BodyDef* body);

    void updateTurn(b2Body* body, int angleSpeed);
    void updateDrive(b2Body* body, int speed);
    void updateFriciton(b2Body* body);
private:
    std::unique_ptr<b2World> world_;

    b2Vec2 getLateralVelocity(b2Body* body);
};

#endif // PHYSICSENGINE_H
