#include "box2dphysicsadapter.h"
#include <Physics/box2dbodyadapter.h>
#include <Physics/vec2d.h>
#include <Physics/box2dshapeadapter.h>

Box2dPhysicsAdapter::Box2dPhysicsAdapter(const std::shared_ptr<GameData>& data,
                                         const std::shared_ptr<Logger>& logger)  : logger_(logger)
{
    info_ = data->getWorldPhysicsInfo();
    world_ = std::make_unique<b2World>(b2Vec2(info_.gravity_x, info_.gravity_y));
}

std::shared_ptr<PhysicsBody> Box2dPhysicsAdapter::createBody(PhysicsBodyDef &bodyDef)
{
    auto fixture = convertTob2BodyDef(bodyDef);
    return std::make_shared<Box2dBodyAdapter>(world_->CreateBody(&fixture), logger_);
}

void Box2dPhysicsAdapter::update()
{
    world_->Step(1.00f/info_.time_step, info_.velocity_iteration, info_.position_iteration);
}

b2BodyDef Box2dPhysicsAdapter::convertTob2BodyDef(const PhysicsBodyDef &physicsBodyDef)
{
    b2BodyDef bodyDef;

    bodyDef.active = physicsBodyDef.active;
    bodyDef.allowSleep = physicsBodyDef.allowSleep;
    bodyDef.angle = physicsBodyDef.angle;
    bodyDef.angularDamping = physicsBodyDef.angularDamping;
    bodyDef.angularVelocity = physicsBodyDef.angularVelocity;
    bodyDef.awake = physicsBodyDef.awake;
    bodyDef.bullet = physicsBodyDef.bullet;
    bodyDef.fixedRotation = physicsBodyDef.fixedRotation;
    bodyDef.gravityScale = physicsBodyDef.gravityScale;
    bodyDef.linearDamping = physicsBodyDef.linearDamping;
    bodyDef.linearVelocity.Set(physicsBodyDef.linearVelocity.x(), physicsBodyDef.linearVelocity.y());
    bodyDef.position.Set(physicsBodyDef.position.x(), physicsBodyDef.position.y());

    switch(physicsBodyDef.type){
    case BodyType::DynamicBody:
        bodyDef.type = b2_dynamicBody;
        break;
    case BodyType::KinematicBody:
        bodyDef.type = b2_kinematicBody;
        break;
    case BodyType::StaticBody:
        bodyDef.type = b2_staticBody;
        break;
    default:
        bodyDef.type = b2_staticBody;
        break;
    }

    bodyDef.userData = physicsBodyDef.userData;
    return bodyDef;
}

// TODO
b2FixtureDef Box2dPhysicsAdapter::convertTob2FixtureDef(const FixtureDef &def)
{
    b2FixtureDef fixtureDef;
    fixtureDef.density = def.density;
    fixtureDef.friction = def.friction;
    fixtureDef.isSensor = def.isSensor;
    fixtureDef.restitution = def.restitution;
    fixtureDef.userData = def.userData;

    auto shapeB2 = std::dynamic_pointer_cast<Box2dShapeAdapter>(def.shape);
    if (shapeB2){
        auto shape = shapeB2->getShape();
        fixtureDef.shape = &(*shape);
    }else {
        // TODO
    }

    return fixtureDef;
}

b2MassData Box2dPhysicsAdapter::convertTob2MassData(const MassData &mass)
{
    b2MassData b2mass;
    b2mass.mass = mass.mass;
    b2mass.I = mass.I;
    b2mass.center.Set(mass.center.x(), mass.center.y());

    return b2mass;
}
