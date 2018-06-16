#ifndef OFFLINEBUILDERIMPL_H
#define OFFLINEBUILDERIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <memory>

class OfflineBuilderImpl{
public:
    ~OfflineBuilderImpl() = default;
    virtual std::shared_ptr<HandleInputComponent> getHandleInputComponent() = 0;
    virtual std::shared_ptr<PhysicsComponent> getPhysicsComponent() = 0;
    virtual std::shared_ptr<ViewComponent> getViewComponent() = 0;
};
#endif // OFFLINEBUILDERIMPL_H
