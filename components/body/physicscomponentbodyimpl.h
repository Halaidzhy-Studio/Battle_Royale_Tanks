#ifndef PHYSICSCOMPONENTBODYIMPL_H
#define PHYSICSCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/body/bodyinfocomponent.h>
#include <objects/commands/movetocommand.h>
#include <utils/data/infostruct.h>
#include <Box2D.h>
#include "physicsengine.h"

class PhysicsComponentBodyImpl : public PhysicsComponent
{
public:
    PhysicsComponentBodyImpl(const PhysicsInfo& info,
                             const std::shared_ptr<PhysicsEngine>& physicsEngine,
                             const std::shared_ptr<BodyInfoComponent>& bodyInfoComponent);
    void update() override;
private:
    PhysicsInfo info_;
    Coordinate coord_;
    TankBodyInfo* dynamicBodyInfo_;
    std::shared_ptr<PhysicsEngine> physicEngine_;
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;
    b2Body* body_;

    void updateTurn(b2Body* body, int angleSpeed);
    void updateDrive(b2Body* body, int speed);
    void updateFriciton(b2Body* body);

};

#endif // PHYSICSCOMPONENTBODYIMPL_H
