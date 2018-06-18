#ifndef BUILDER_H
#define BUILDER_H

#include <components/interfaces/componentsinterfaces.h>
#include <memory>

class Builder{
public:
    virtual ~Builder() = default;

    virtual std::shared_ptr<HandleInputComponent> getHandleInputComponent() {}
    virtual std::shared_ptr<PhysicsComponent> getPhysicsComponent() {}
    virtual std::shared_ptr<ViewComponent> getViewComponent() {}
    virtual std::shared_ptr<NetworkComponent> getNetworkComponent() {}
    virtual std::shared_ptr<ContactComponent> getContactComponent() {}

};

#endif // BUILDER_H
