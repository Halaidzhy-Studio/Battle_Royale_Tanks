#ifndef BOX2DBODYADAPTER_H
#define BOX2DBODYADAPTER_H

#include <Physics/physicsbody.h>
#include <3rdparty/Box2D/Box2D.h>

class Box2dBodyAdapter : public PhysicsBody
{
public:
    Box2dBodyAdapter(b2Body*, const std::shared_ptr<Logger>&);

    // b2Body удаляет b2World, который создает b2Body
    ~Box2dBodyAdapter() = default;

    void createFixture(FixtureDef) override;
    void setLinearDamping(double) override;
    double getAngle() override;
    void setMassData(MassData) override;
    Vec2D getPosition() override;
    void connectToFixture(FixtureDef &) override;
    void SetAngularVelocity(double) override;
    void applyForce(Vec2D, Vec2D, bool) override;
    Vec2D getLocalCenter() override;
    void setPos(const Vec2D &) override;

private:
    b2Body* body_;
    std::shared_ptr<Logger> logger_;
};

#endif // BOX2DBODYADAPTER_H
