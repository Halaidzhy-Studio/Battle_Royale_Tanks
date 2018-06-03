#ifndef SINGLEPLAYERBODYBUILDERIMPL_H
#define SINGLEPLAYERBODYBUILDERIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <memory>

class OfflineBodyBuilderImpl{
public:
    virtual ~OfflineBodyBuilderImpl() = default;
    virtual std::shared_ptr<HandleInputComponent> getHandleInputComponent() = 0;
    virtual std::shared_ptr<PhysicsComponent> getPhysicsComponent() = 0;
    virtual std::shared_ptr<ViewComponent> getViewComponent() = 0;
};
#endif // SINGLEPLAYERBODYBUILDERIMPL_H
