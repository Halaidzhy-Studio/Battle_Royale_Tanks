#ifndef PLAYEROFFLINETURRETBUILDER_H
#define PLAYEROFFLINETURRETBUILDER_H

#include <utils/logger.h>
#include <builders/interfaces/offlinebuilderimpl.h>
#include <Graphics/graphicsitem.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/data/turretinfostruct.h>
#include <components/turret/logicturretcomponent.h>
#include <objects/playerhud.h>

class PlayerOfflineTurretBuilder : public OfflineBuilderImpl
{
public:
    PlayerOfflineTurretBuilder(const std::shared_ptr<Graphics>&,
                               const std::shared_ptr<Physics>&,
                               const std::shared_ptr<Logger>&,
                               const TankTurretInfo&,
                               const std::shared_ptr<PlayerHUD>&,
                               const std::shared_ptr<LogicTurretComponent>&);

    ~PlayerOfflineTurretBuilder() = default;
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
    std::shared_ptr<ContactComponent> getContactComponent() override;

private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<LogicTurretComponent> logicTurret_;
    GraphicsItem* item_;
    TankTurretInfo info_;
};

#endif // PLAYEROFFLINETURRETBUILDER_H
