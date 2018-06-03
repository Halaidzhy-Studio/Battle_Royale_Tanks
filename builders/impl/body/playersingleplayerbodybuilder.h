#ifndef PLAYERSINGLEPLAYERBODYBUILDER_H
#define PLAYERSINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/body/singleplayerbodybuilderimpl.h>
#include <utils/data/bodyinfostruct.h>
#include <components/body/bodyinfocomponent.h>
#include <components/body/viewcomponentbodyimpl.h>
#include <Graphics/graphics.h>

class PlayerOfflineBodyBuilder : public OfflineBodyBuilderImpl
{
public:
    PlayerOfflineBodyBuilder();
    PlayerOfflineBodyBuilder(TankBodyInfo tankBodyInfo,
                             const std::shared_ptr<Graphics>& graphics,
                             const std::shared_ptr<Logger>& logger);

    ~PlayerOfflineBodyBuilder() = default;
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Logger> logger_;

    GraphicsItem* graphicsItem;
    TankBodyInfo tankBodyInfo_;
};

#endif // PLAYERSINGLEPLAYERBODYBUILDER_H
