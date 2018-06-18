#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include <utils/coordinate.h>
#include <Physics/physicsshape.h>
#include <Physics/physicsfixture.h>
#include <Physics/vec2d.h>

enum class BodyType{
    StaticBody = 0,
    KinematicBody,
    DynamicBody,
};

struct PhysicsBodyDef{
    PhysicsBodyDef()
    {
        userData = nullptr;
        position.set(0.0, 0.0);
        angle = 0.0;
        linearVelocity.set(0.0, 0.0);
        angularVelocity = 0.0;
        linearDamping = 0.0;
        angularDamping = 0.0;
        allowSleep = true;
        awake = true;
        fixedRotation = false;
        bullet = false;
        type = BodyType::StaticBody;
        active = true;
        gravityScale = 1.0;
    }

    BodyType type;
    Vec2D position;
    double angle;
    Vec2D linearVelocity;
    double angularVelocity;
    double linearDamping;
    double angularDamping;
    bool allowSleep;
    bool awake;
    bool fixedRotation;
    bool bullet;
    bool active;
    void* userData;
    double gravityScale;
};


class PhysicsBody{
public:
    virtual ~PhysicsBody() = default;
    virtual void createFixture(FixtureDef) = 0;
    virtual void setLinearDamping(double) = 0;
    virtual double getAngle() = 0;
    virtual void setMassData(MassData) = 0;
    virtual Vec2D getPosition() = 0;
    virtual void connectToFixture(FixtureDef&) = 0;
    virtual void SetAngularVelocity(double) = 0;
    virtual void applyForce(Vec2D, Vec2D, bool) = 0;
    virtual Vec2D getLocalCenter() = 0;
    virtual void setPos(const Vec2D&) = 0;
};

#endif // PHYSICSBODY_H
