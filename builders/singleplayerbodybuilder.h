#ifndef SINGLEPLAYERBODYBUILDER_H
#define SINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/bodybuilder.h>
#include <builders/interfaces/singleplayerbodybuilderimpl.h>

class SingleplayerBodyBuilder : public BodyBuilder
{
public:
    SingleplayerBodyBuilder();
    SingleplayerBodyBuilder(const std::shared_ptr<SingleplayerBodyBuilderImpl> bodyBuilderImpl):
        bodyBuilderImpl_(bodyBuilderImpl) {}

    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<SingleplayerBodyBuilderImpl> bodyBuilderImpl_;
};

#endif // SINGLEPLAYERBODYBUILDER_H
