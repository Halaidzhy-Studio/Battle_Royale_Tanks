#include "playersingleplayerbodybuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
PlayerSingleplayerBodyBuilder::PlayerSingleplayerBodyBuilder()
{

}

PlayerSingleplayerBodyBuilder::PlayerSingleplayerBodyBuilder(TankBodyInfo tankBodyInfo,
                                                             const std::shared_ptr<Graphics> &graphics) :
    tankBodyInfo_(tankBodyInfo), graphics_(graphics)
{
    bodyInfoComponent_ = std::make_shared<BodyInfoComponent>();
}


std::shared_ptr<HandleInputComponent> PlayerSingleplayerBodyBuilder::getHandleInputComponent()
{
}

std::shared_ptr<PhysicsComponent> PlayerSingleplayerBodyBuilder::getPhysicsComponent()
{
}

std::shared_ptr<ViewComponent> PlayerSingleplayerBodyBuilder::getViewComponent()
{
    std::shared_ptr<GraphicsItem> graphicsItem = std::make_shared<QtGraphicsItemAdapter>(graphics_);
    graphicsItem->setControlable();
    graphicsItem->setRect(0, 0, tankBodyInfo_.w, tankBodyInfo_.h);
    std::shared_ptr<ViewComponent> viewComponent = std::make_shared<ViewComponentBodyImpl>(graphicsItem);
}
