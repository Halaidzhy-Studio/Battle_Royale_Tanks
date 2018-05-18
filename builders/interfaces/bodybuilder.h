#ifndef TANKBODYBUILDER_H
#define TANKBODYBUILDER_H

#include <objects/tankbody.h>

class BodyBuilder{
public:
    BodyBuilder() = default;

    virtual std::shared_ptr<HandleInputComponent> getHandleInputComponent() = 0;
    virtual std::shared_ptr<PhysicsComponent> getPhysicsComponent() = 0;
    virtual std::shared_ptr<ViewComponent> getViewComponent() = 0;
};
#endif // TANKBODYBUILDER_H
