#ifndef TANKBODYBUILDER_H
#define TANKBODYBUILDER_H

#include <objects/tankbody.h>

class BodyBuilder{
public:
    ~BodyBuilder() = default;

    virtual std::shared_ptr<HandleInputComponent> getHandleInputComponent() {}
    virtual std::shared_ptr<PhysicsComponent> getPhysicsComponent() {}
    virtual std::shared_ptr<ViewComponent> getViewComponent() {}
    virtual std::shared_ptr<NetworkComponent> getNetworkComponent() {}

};
#endif // TANKBODYBUILDER_H
