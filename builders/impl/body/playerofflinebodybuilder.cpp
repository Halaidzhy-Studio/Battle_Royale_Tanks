#include "playerofflinebodybuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/body/handleinputcomponentimplbody.h>
#include <components/body/physicscomponentbodyimpl.h>
#include <components/body/contactcomponentbodyimpl.h>

PlayerOfflineBodyBuilder::PlayerOfflineBodyBuilder(const TankBodyInfo &tankBodyInfo,
                                                   const std::shared_ptr<Graphics> &graphics,
                                                   const std::shared_ptr<Logger>& logger,
                                                   const std::shared_ptr<PlayerHUD>& hud,
                                                   const std::shared_ptr<Physics>& physics,
                                                   const std::shared_ptr<LogicBodyComponent>&logic) :
    info_(tankBodyInfo), graphics_(graphics), logger_(logger), physics_(physics),
    bodyInfoComponent_(logic)
{

    hud->setBodyLogic(bodyInfoComponent_);

    // Графический объект отвечает за Нажатые клавиши и за отрисовку.
    item_ = new QtGraphicsItemAdapter(graphics_, logger_);
}


std::shared_ptr<HandleInputComponent> PlayerOfflineBodyBuilder::getHandleInputComponent()
{
    std::shared_ptr<HandleInputComponent> handleInputComponent(
                new HandleInputComponentImplBody(graphics_, bodyInfoComponent_, logger_));

    handleInputComponent->initCommand();
    return handleInputComponent;
}

std::shared_ptr<PhysicsComponent> PlayerOfflineBodyBuilder::getPhysicsComponent()
{
    std::shared_ptr<PhysicsComponent> physicsComponent =
            std::make_shared<PhysicsComponentBodyImpl>(physics_, bodyInfoComponent_, logger_);

    return physicsComponent;
}

std::shared_ptr<ViewComponent> PlayerOfflineBodyBuilder::getViewComponent()
{

    item_->setTexture(info_.styleInfo.pathToTexture);

    if (info_.styleInfo.default_rect_pos)
        item_->setRect(info_.styleInfo.width, info_.styleInfo.height);
    else
        item_->setRect(info_.styleInfo.x, info_.styleInfo.y, info_.styleInfo.width, info_.styleInfo.height);

    std::shared_ptr<ViewComponent> viewComponent =
            std::make_shared<ViewComponentBodyImpl>(item_, bodyInfoComponent_);

    return viewComponent;
}

std::shared_ptr<ContactComponent> PlayerOfflineBodyBuilder::getContactComponent()
{
    std::shared_ptr<ContactComponent> component =
            std::make_shared<ContactComponentBodyImpl>(bodyInfoComponent_, logger_);

    return component;
}
