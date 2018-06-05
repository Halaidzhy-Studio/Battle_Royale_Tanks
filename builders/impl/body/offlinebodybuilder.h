#ifndef SINGLEPLAYERBODYBUILDER_H
#define SINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/builder.h>
#include <builders/interfaces/offlinebodybuilderimpl.h>

class OfflineBodyBuilder : public Builder
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
