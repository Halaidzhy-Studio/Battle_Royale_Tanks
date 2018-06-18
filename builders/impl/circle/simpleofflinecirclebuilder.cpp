#include "simpleofflinecirclebuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/circle/viewcomponentcircleimpl.h>
#include <components/circle/handleinputcomponentcircleimpl.h>
#include <components/circle/contactcomponentcircleimpl.h>

SimpleOfflineCircleBuilder::SimpleOfflineCircleBuilder(
        const std::shared_ptr<Graphics> & graphics,
        const std::shared_ptr<Physics> & physics,
        const std::shared_ptr<Logger> &logger,
        const CircleInfo &info,
        const std::shared_ptr<PlayerHUD>& hud,
        const std::vector<std::shared_ptr<TankComplexObject>>& tanks) : graphics_(graphics), physics_(physics), logger_(logger),
    logicCircle_(std::make_shared<LogicCircleComponent>(info, graphics, logger)),
    info_(info), tanks_(tanks)
{
    if (hud)
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
    return nullptr;
}

std::shared_ptr<ViewComponent> SimpleOfflineCircleBuilder::getViewComponent()
{
    GraphicsItem* graphicsItem = new QtGraphicsItemAdapter(graphics_, logger_);
    graphicsItem->setTexture(info_.styleInfo.pathToTexture);
    graphicsItem->setPos(Coordinate(0, 0, Coordinate::CoordTypes::QT, logger_));
    graphicsItem->setRect(info_.r*2, info_.r*2);
    graphicsItem->setIsScalableTexture(info_.styleInfo.is_scalable);
    graphicsItem->setOpacity(info_.styleInfo.opacity);
    std::shared_ptr<ViewComponent> view =
            std::make_shared<ViewComponentCircleImpl>(graphicsItem, logicCircle_, logger_);

    return view;
}

std::shared_ptr<ContactComponent> SimpleOfflineCircleBuilder::getContactComponent()
{
    std::shared_ptr<ContactComponent> component =
            std::make_shared<ContactComponentCircleImpl>(logicCircle_, logger_, tanks_);
    return component;
}
