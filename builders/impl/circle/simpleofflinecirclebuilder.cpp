#include "simpleofflinecirclebuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/circle/viewcomponentcircleimpl.h>
#include <components/circle/handleinputcomponentcircleimpl.h>

SimpleOfflineCircleBuilder::SimpleOfflineCircleBuilder(
        const std::shared_ptr<Graphics> & graphics,
        const std::shared_ptr<Physics> & physics,
        const std::shared_ptr<Logger> &logger,
        const CircleInfo &info,
        const std::shared_ptr<PlayerHUD>& hud) : graphics_(graphics), physics_(physics), logger_(logger),
    logicCircle_(std::make_shared<LogicCircleComponent>(info)), info_(info)
{
    hud->setCircleLogic(logicCircle_);
}

std::shared_ptr<HandleInputComponent> SimpleOfflineCircleBuilder::getHandleInputComponent()
{
    std::shared_ptr<HandleInputComponent> input =
            std::make_shared<HandleInputComponentCircleImpl>(logicCircle_, logger_);
    input->initCommand();
    return input;
}

std::shared_ptr<PhysicsComponent> SimpleOfflineCircleBuilder::getPhysicsComponent()
{
}

std::shared_ptr<ViewComponent> SimpleOfflineCircleBuilder::getViewComponent()
{
    GraphicsItem* graphicsItem = new QtGraphicsItemAdapter(graphics_, logger_);
    graphicsItem->setTexture(info_.styleInfo.pathToTexture);
    graphicsItem->setPos(Coordinate(0, 0, Coordinate::CoordTypes::QT, logger_));
    graphicsItem->setRect(info_.r*2, info_.r*2);
    graphicsItem->setIsScalableTexture(false);
    std::shared_ptr<ViewComponent> view =
            std::make_shared<ViewComponentCircleImpl>(graphicsItem, logicCircle_, logger_);

    return view;
}
