#include "physicscomponentbodyimpl.h"

PhysicsComponentBodyImpl::PhysicsComponentBodyImpl(const PhysicsInfo &info,
                                                   const std::shared_ptr<Physics> &physicsEngine,
                                                   const std::shared_ptr<LogicBodyComponent> &bodyInfoComponent)
    : info_(info), physicEngine_(physicsEngine), bodyInfoComponent_(bodyInfoComponent){

    TankBodyInfo bodyInfo = bodyInfoComponent_->bodyInfoConst();

    b2BodyDef bodyDef;

    switch (info_.type){
    case 0:
        bodyDef.type = b2_staticBody;
        break;
    case 1:
        bodyDef.type = b2_dynamicBody;
        break;
    default:
        // Nothing
        break;
    }

    Coordinate coord = bodyInfoComponent_->coord();
    coord.toPhysicsengine();

    bodyDef.position.Set(coord.x(), coord.y());

    b2PolygonShape polygonShape;
    // Делим на два, потому что в Box2d другое представление системы координат.
    polygonShape.SetAsBox(bodyInfo.w/2, bodyInfo.h/2);

    b2FixtureDef fixDef;
    fixDef.shape = &polygonShape;
    fixDef.density = info_.density;
    fixDef.restitution = info_.restitution;
    fixDef.friction = info_.friction;

    /*
    body_ = physicsEngine->CreateBody(&bodyDef);
    body_->CreateFixture(&fixDef);
    body_->SetLinearDamping(info_.linearDumping);
    */
    dynamicBodyInfo_ = bodyInfoComponent_->bodyInfoDynamicPtr();
}

void PhysicsComponentBodyImpl::update()
{
    updateFriciton(body_);
    updateDrive(body_, dynamicBodyInfo_->speed);
    updateTurn(body_, dynamicBodyInfo_->turnSpeed);

    coord_.setX(body_->GetPosition().x, Coordinate::CoordTypes::PHYSICSENGINE);
    coord_.setY(body_->GetPosition().y, Coordinate::CoordTypes::PHYSICSENGINE);

    bodyInfoComponent_->moveTo(coord_.x(), coord_.y());
}

void PhysicsComponentBodyImpl::updateTurn(b2Body *body, int angleSpeed)
{
    body->SetAngularVelocity(angleSpeed);
}

void PhysicsComponentBodyImpl::updateDrive(b2Body *body, int speed)
{
    b2Vec2 vec(body->GetPosition().x, body->GetPosition().y + speed);
    body->SetTransform( vec , body->GetAngle());
}

void PhysicsComponentBodyImpl::updateFriciton(b2Body *body)
{
    b2Vec2 impulse = body->GetMass() * -getLateralVelocity(body);
    body->ApplyLinearImpulse(impulse , body->GetWorldCenter(), true);
}

b2Vec2 PhysicsComponentBodyImpl::getLateralVelocity(b2Body* body)
{
    b2Vec2 currentRightNormal = body->GetWorldVector( b2Vec2(1,0) );
    return b2Dot( currentRightNormal, body->GetLinearVelocity() ) * currentRightNormal;
}

