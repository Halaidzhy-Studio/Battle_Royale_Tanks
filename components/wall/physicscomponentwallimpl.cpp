#include "physicscomponentwallimpl.h"
#include <Physics/box2dshapeadapter.h>

PhysicsComponentWallImpl::PhysicsComponentWallImpl(
        const std::shared_ptr<Physics> &physics,
        const std::shared_ptr<Logger> &logger,
        const WallInfo &info) : physics_(physics), logger_(logger), info_(info)
{
    PhysicsBodyDef bodyDef;
    bodyDef.type = info.physicsInfo.type;
    bodyDef.position.set(Coordinate::qtConvertToPhysics(info.x),Coordinate::qtConvertToPhysics(info.y));

    std::shared_ptr<PhysicsShape> shape = std::make_shared<Box2dShapeAdapter>();
    shape->setAsBox(info.physicsInfo.w/2, info.physicsInfo.h/2);

    FixtureDef fixtureDef;
    fixtureDef.shape = shape;

    body_ = physics_->createBody(bodyDef);
    body_->connectToFixture(fixtureDef);
}

void PhysicsComponentWallImpl::update()
{
}
