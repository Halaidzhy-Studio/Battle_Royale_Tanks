#include "playersingleplayerbodybuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/body/handleinputcomponentimplbody.h>

PlayerOfflineBodyBuilder::PlayerOfflineBodyBuilder(const TankBodyInfo &tankBodyInfo,
                                                   const std::shared_ptr<Graphics> &graphics,
                                                   const std::shared_ptr<Logger>& logger) :
    tankBodyInfo_(tankBodyInfo), graphics_(graphics), logger_(logger)
{
    bodyInfoComponent_ = std::make_shared<LogicBodyComponent>(tankBodyInfo_, logger_);

    // Графический объект отвечает за Нажатые клавиши и за отрисовку.
    graphicsItem = new QtGraphicsItemAdapter(graphics_);
}


std::shared_ptr<HandleInputComponent> PlayerOfflineBodyBuilder::getHandleInputComponent()
{
    graphicsItem->setControlable();
    std::shared_ptr<HandleInputComponent> handleInputComponent(
                new HandleInputComponentImplBody(graphicsItem, bodyInfoComponent_, logger_));

    handleInputComponent->initCommand();
    return handleInputComponent;
}

std::shared_ptr<PhysicsComponent> PlayerOfflineBodyBuilder::getPhysicsComponent()
{

}

std::shared_ptr<ViewComponent> PlayerOfflineBodyBuilder::getViewComponent()
{

    Texture texture;
    texture.pathTo = tankBodyInfo_.styleInfo.pathToTexture;
    graphicsItem->setTexture(texture);
    graphicsItem->setRect(tankBodyInfo_.w, tankBodyInfo_.h);
    std::shared_ptr<ViewComponent> viewComponent =
            std::make_shared<ViewComponentBodyImpl>(graphicsItem, bodyInfoComponent_);

    return viewComponent;
}
