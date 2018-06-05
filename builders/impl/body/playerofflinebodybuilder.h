#ifndef PLAYERSINGLEPLAYERBODYBUILDER_H
#define PLAYERSINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/offlinebuilderimpl.h>
#include <utils/data/bodyinfostruct.h>
#include <components/body/logicbodycomponent.h>
#include <components/body/viewcomponentbodyimpl.h>
#include <Graphics/graphics.h>
#include <Graphics/graphicsitem.h>

class PlayerOfflineBodyBuilder : public OfflineBuilderImpl
{
public:
    PlayerOfflineBodyBuilder() = default;
    PlayerOfflineBodyBuilder(const TankBodyInfo& tankBodyInfo,
                             const std::shared_ptr<Graphics>& graphics,
                             const std::shared_ptr<Logger>& logger);

    ~PlayerOfflineBodyBuilder() = default;
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<LogicBodyComponent> bodyInfoComponent_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Logger> logger_;

    // За его удаление отвечает QGraphicsScene;
    GraphicsItem* graphicsItem;
    TankBodyInfo tankBodyInfo_;
};

#endif // PLAYERSINGLEPLAYERBODYBUILDER_H
