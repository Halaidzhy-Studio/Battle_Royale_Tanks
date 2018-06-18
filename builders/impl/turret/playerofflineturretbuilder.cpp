#include "playerofflineturretbuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/turret/handleinputcomponentturretimpl.h>
#include <components/turret/viewcomponentturretimpl.h>

PlayerOfflineTurretBuilder::PlayerOfflineTurretBuilder(
        const std::shared_ptr<Graphics> &graphics,
        const std::shared_ptr<Physics> &physics,
        const std::shared_ptr<Logger> &logger,
        const TankTurretInfo &info,
        const std::shared_ptr<PlayerHUD>& hud,
        const std::shared_ptr<LogicTurretComponent>& logic) :
    graphics_(graphics), physics_(physics), logger_(logger), info_(info),
    item_(new QtGraphicsItemAdapter(graphics, logger)),
    logicTurret_(logic)
{
    hud->setTurretLogic(logicTurret_);
}

std::shared_ptr<HandleInputComponent> PlayerOfflineTurretBuilder::getHandleInputComponent()
{
    std::shared_ptr<HandleInputComponent> input =
            std::make_shared<HandleInputComponentTurretImpl>(graphics_, logicTurret_, logger_);
    input->initCommand();
    return input;
}

std::shared_ptr<PhysicsComponent> PlayerOfflineTurretBuilder::getPhysicsComponent()
{
    return nullptr;
}

std::shared_ptr<ViewComponent> PlayerOfflineTurretBuilder::getViewComponent()
{
    item_->setTexture(info_.styleInfo.pathToTexture);

    if (info_.styleInfo.default_rect_pos)
        item_->setRect(info_.styleInfo.width, info_.styleInfo.height);
    else
        item_->setRect(info_.styleInfo.x, info_.styleInfo.y,
                       info_.styleInfo.width, info_.styleInfo.height);

    item_->setControlable();

    std::shared_ptr<ViewComponent> view =
            std::make_shared<ViewComponentTurretImpl>(item_, logicTurret_);
    return view;
}

std::shared_ptr<ContactComponent> PlayerOfflineTurretBuilder::getContactComponent()
{
    return nullptr;
}
