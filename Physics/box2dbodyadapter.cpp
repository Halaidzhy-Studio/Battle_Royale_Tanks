#include "box2dbodyadapter.h"
#include <Physics/box2dphysicsadapter.h>
#include <qdebug.h>

Box2dBodyAdapter::Box2dBodyAdapter(b2Body *body, const std::shared_ptr<Logger> &logger) :
    body_(body), logger_(logger)
{

}


void Box2dBodyAdapter::createFixture(FixtureDef fixture)
{

}

void Box2dBodyAdapter::setLinearDamping(double linearDamping)
{
    body_->SetLinearDamping(linearDamping);
}

double Box2dBodyAdapter::getAngle()
{
    return body_->GetAngle();
}

void Box2dBodyAdapter::setMassData(MassData mass)
{
    auto massData = Box2dPhysicsAdapter::convertTob2MassData(mass);
    body_->SetMassData(&massData);
}

Vec2D Box2dBodyAdapter::getPosition()
{
    return Vec2D(body_->GetPosition().x, body_->GetPosition().y);
}

void Box2dBodyAdapter::connectToFixture(FixtureDef &fixtureDef)
{
    auto fixture = Box2dPhysicsAdapter::convertTob2FixtureDef(fixtureDef);
    body_->CreateFixture(&fixture);
}

void Box2dBodyAdapter::SetAngularVelocity(double aVelocity)
{
    body_->SetAngularVelocity(aVelocity);
}

void Box2dBodyAdapter::applyForce(Vec2D force, Vec2D point, bool wake)
{
    //qDebug() << force.x() << " " << force.y() << "\n";
    std::string total = "force: " + std::to_string(force.x()) + "; " + std::to_string(force.y());
    logger_->printLog(total, "[PHYSICS]");

    b2Vec2 forceb2(force.x(), force.y());
    b2Vec2 pointb2(point.x(), point.y());

   // qDebug() << forceb2.x << " " << forceb2.y << "\n";
   // qDebug() << pointb2.x << " " << pointb2.y << "\n";

    body_->ApplyForce(forceb2, pointb2, wake);
}

Vec2D Box2dBodyAdapter::getLocalCenter()
{
    return Vec2D(body_->GetLocalCenter().x, body_->GetLocalCenter().y);
}

void Box2dBodyAdapter::setPos(const Vec2D &pos)
{
    b2Vec2 b2Pos(pos.x(), pos.y());
    body_->SetTransform(b2Pos, body_->GetAngle());
}
