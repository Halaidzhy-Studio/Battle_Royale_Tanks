#ifndef PLAYERSINGLEPLAYERBODYBUILDER_H
#define PLAYERSINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/offlinebuilderimpl.h>
#include <utils/data/bodyinfostruct.h>
#include <components/body/logicbodycomponent.h>
#include <components/body/viewcomponentbodyimpl.h>
#include <Graphics/graphics.h>
#include <Graphics/graphicsitem.h>
#include <objects/playerhud.h>
#include <Physics/physics.h>

class PlayerOfflineBodyBuilder : public OfflineBuilderImpl
{
public:
    PlayerOfflineBodyBuilder() = default;
    PlayerOfflineBodyBuilder(const TankBodyInfo& tankBodyInfo,
                             const std::shared_ptr<Graphics>& graphics,
                             const std::shared_ptr<Logger>& logger,
                             const std::shared_ptr<PlayerHUD>& hud,
                             const std::shared_ptr<Physics>& physics,
                             const std::shared_ptr<LogicBodyComponent>&);

    ~PlayerOfflineBodyBuilder() = default;

    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
    std::shared_ptr<ContactComponent> getContactComponent() override;
private:
    std::shared_ptr<LogicBodyComponent> bodyInfoComponent_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Physics> physics_;

    // За его удаление отвечает QGraphicsScene;
    GraphicsItem* item_;
    TankBodyInfo info_;
};

#endif // PLAYERSINGLEPLAYERBODYBUILDER_H
