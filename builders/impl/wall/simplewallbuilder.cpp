#include "simplewallbuilder.h"
#include <Graphics/qtgraphicsitemadapter.h>
#include <components/wall/viewcomponentwallimpl.h>

SimpleWallBuilder::SimpleWallBuilder(const std::shared_ptr<Graphics> &graphisc,
                                     const std::shared_ptr<Physics> &physics,
                                     const std::shared_ptr<Logger> &logger,
                                     const WallInfo &info) : graphics_(graphisc), physics_(physics),
    logger_(logger), info_(info)
{
}

std::shared_ptr<HandleInputComponent> SimpleWallBuilder::getHandleInputComponent()
{
}

std::shared_ptr<PhysicsComponent> SimpleWallBuilder::getPhysicsComponent()
{
}

std::shared_ptr<ViewComponent> SimpleWallBuilder::getViewComponent()
{
    GraphicsItem* item = new QtGraphicsItemAdapter(graphics_, logger_);
    item->setTexture(info_.styleInfo.pathToTexture);

    item->setPos(Coordinate(info_.x, info_.y, Coordinate::CoordTypes::QT, logger_));

    if (info_.styleInfo.default_rect_pos)
        item->setRect(info_.styleInfo.width, info_.styleInfo.height);
    else
        item->setRect(info_.styleInfo.x, info_.styleInfo.y, info_.styleInfo.width, info_.styleInfo.height);

    std::shared_ptr<ViewComponent> view =
            std::make_shared<ViewComponentWallImpl>(item);

    return view;
}
