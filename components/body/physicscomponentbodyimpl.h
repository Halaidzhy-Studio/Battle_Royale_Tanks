#ifndef PHYSICSCOMPONENTBODYIMPL_H
#define PHYSICSCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/body/bodyinfocomponent.h>

class PhysicsComponentBodyImpl : public PhysicsComponent
{
public:
    PhysicsComponentBodyImpl();
private:
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;
};

#endif // PHYSICSCOMPONENTBODYIMPL_H
