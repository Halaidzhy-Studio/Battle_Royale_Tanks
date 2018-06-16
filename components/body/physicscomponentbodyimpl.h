#ifndef PHYSICSCOMPONENTBODYIMPL_H
#define PHYSICSCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/body/logicbodycomponent.h>
#include <objects/commands/movetocommand.h>
#include <utils/data/infostruct.h>
#include <Physics/physics.h>
#include <3rdparty/Box2D/Box2D.h>

class PhysicsComponentBodyImpl : public PhysicsComponent
{
public:
    PhysicsComponentBodyImpl() = default;
    void update() override;
};

#endif // PHYSICSCOMPONENTBODYIMPL_H
