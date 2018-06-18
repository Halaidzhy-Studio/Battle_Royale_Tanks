#include "physicscomponentbodyimpl.h"
#include <cmath>
#include <objects/commands/movetocommand.h>
#include <objects/commands/turntocommand.h>
#include <Physics/box2dshapeadapter.h>
#include <utils/angle.h>

PhysicsComponentBodyImpl::PhysicsComponentBodyImpl(
        const std::shared_ptr<Physics> &physics,
        const std::shared_ptr<LogicBodyComponent> &logicComponent,
        const std::shared_ptr<Logger>& logger) :
    physics_(physics), logicComponent_(logicComponent), logger_(logger)
{
    auto info = logicComponent->bodyInfoConst();

    initCommand();

    PhysicsBodyDef bodyDef;
    bodyDef.type = info.physicsInfo.type;
    Coordinate coord = logicComponent_->coord();
    bodyDef.position.set(coord.toPhysicsengine().x(), coord.toPhysicsengine().y());
    bodyDef.linearDamping = info.physicsInfo.linearDumping;

    std::shared_ptr<PhysicsShape> shape( new Box2dShapeAdapter());
    shape->setAsBox(info.physicsInfo.w/2, info.physicsInfo.h/2);

    FixtureDef fixtureDef;
    fixtureDef.density = info.physicsInfo.density;
    fixtureDef.friction = info.physicsInfo.friction;
    fixtureDef.restitution = info.physicsInfo.restitution;
    fixtureDef.shape = shape;

    body_ = physics_->createBody(bodyDef);
    body_->connectToFixture(fixtureDef);

    MassData mass;
    mass.mass = info.physicsInfo.mass;
    mass.I = info.physicsInfo.I;
    mass.center = body_->getLocalCenter();

    body_->setMassData(mass);
}

void PhysicsComponentBodyImpl::update()
{
    updateDrive(logicComponent_->bodyInfoDynamicPtr()->speed);
    updateTurn(Angle::degreeToRad(logicComponent_->bodyInfoDynamicPtr()->turnSpeed));

    move_->execute(Coordinate(body_->getPosition().x(), body_->getPosition().y(),
                              Coordinate::CoordTypes::PHYSICSENGINE, logger_));

    double normAngle = Angle::normalizeDegreeAngle(
                Angle::radToDegree(body_->getAngle()));
    turn_->execute(normAngle);
}



void PhysicsComponentBodyImpl::setPos(const Coordinate &coordConst)
{
    auto coord = coordConst;
    auto x = coord.toPhysicsengine().x();
    auto y = coord.toPhysicsengine().y();
    body_->setPos(Vec2D(x, y));
}

void PhysicsComponentBodyImpl::updateTurn(double turnSpeed){
    double desiredTorque = turnSpeed;
    body_->SetAngularVelocity(desiredTorque);
}

void PhysicsComponentBodyImpl::updateDrive(int speed){
    int desiredSpeed = speed;

    float rot = (float) body_->getAngle() + (float) (M_PI/2);
    Vec2D vec(cos(rot), sin(rot));
    vec*=desiredSpeed;

    body_->applyForce(vec, body_->getPosition(), true);
}

void PhysicsComponentBodyImpl::initCommand()
{
    auto moveable = std::dynamic_pointer_cast<Moveable>(logicComponent_);
    if (moveable){
        move_ = std::make_shared<MoveToCommand>(moveable);
    }else{
        logger_->printLog("Body doesn't have Move Possibility", "[GAME]");
    }

    auto turnable = std::dynamic_pointer_cast<Turnable>(logicComponent_);
    if (turnable){
        turn_ = std::make_shared<TurnToCommand>(turnable);
    }else {
        logger_->printLog("Body doesn't have Turn Possibility", "[GAME]");
    }
}

