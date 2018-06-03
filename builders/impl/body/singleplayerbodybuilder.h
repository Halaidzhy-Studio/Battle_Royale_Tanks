#ifndef SINGLEPLAYERBODYBUILDER_H
#define SINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/body/bodybuilder.h>
#include <builders/interfaces/body/singleplayerbodybuilderimpl.h>

class OfflineBodyBuilder : public BodyBuilder
{
public:
    OfflineBodyBuilder();
    OfflineBodyBuilder(const std::shared_ptr<OfflineBodyBuilderImpl> bodyBuilderImpl):
        bodyBuilderImpl_(bodyBuilderImpl) {}

    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<OfflineBodyBuilderImpl> bodyBuilderImpl_;
};

#endif // SINGLEPLAYERBODYBUILDER_H
