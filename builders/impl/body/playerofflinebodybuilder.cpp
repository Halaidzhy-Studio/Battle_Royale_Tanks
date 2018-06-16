#include "playerofflinebodybuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/body/handleinputcomponentimplbody.h>

PlayerOfflineBodyBuilder::PlayerOfflineBodyBuilder(const TankBodyInfo &tankBodyInfo,
                                                   const std::shared_ptr<Graphics> &graphics,
                                                   const std::shared_ptr<Logger>& logger) :
    info_(tankBodyInfo), graphics_(graphics), logger_(logger)
{
    bodyInfoComponent_ = std::make_shared<LogicBodyComponent>(info_, logger_);

    // Графический объект отвечает за Нажатые клавиши и за отрисовку.
    item_ = new QtGraphicsItemAdapter(graphics_, logger_);
}


std::shared_ptr<HandleInputComponent> PlayerOfflineBodyBuilder::getHandleInputComponent()
{
    item_->setControlable();
    std::shared_ptr<HandleInputComponent> handleInputComponent(
                new HandleInputComponentImplBody(item_, bodyInfoComponent_, logger_));

    handleInputComponent->initCommand();
    return handleInputComponent;
}

std::shared_ptr<PhysicsComponent> PlayerOfflineBodyBuilder::getPhysicsComponent()
{

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
