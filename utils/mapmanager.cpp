#include "mapmanager.h"
#include <fstream>
#include <sstream>
#include <QCoreApplication>

MapManager::MapManager()
{

}

MapManager::MapManager(const std::shared_ptr<Graphics> &graphics,
                       const std::shared_ptr<Physics> &physics,
                       const std::shared_ptr<Logger> &logger) :
    graphics_(graphics), physics_(physics), logger_(logger)
{
}

void MapManager::setMapManagerImpl(std::unique_ptr<MapManagerImpl> impl)
{
    impl_ = std::move(impl);
}

void MapManager::upload(const std::string & file)
{
    if (impl_)
        impl_ ->upload(file);
    else
        loggerLookUp("Can't upload Map, because MapManagerImpl wasn't installed");
}

void MapManager::create()
{
    if (impl_){
        int width = impl_->getSceneWidth();
        int height = impl_->getSceneHeight();
        graphics_->setSceneRect(-width/2, -height/2, width, height);
    }else
        loggerLookUp("Can't create Map, because MapManagerImpl wasn't installed");
}

Coordinate MapManager::getPlayerStartCoord()
{
    if (impl_){
        return impl_->getPlayerPos();
    } else {
        loggerLookUp("Can't get Player Pos, because MapManagerImpl wasn't installed");
    }

    return Coordinate();
}

std::vector<GeometryRect> MapManager::getWalls()
{
    if (impl_)
        return impl_->getWalls();
    else
        loggerLookUp("Can't get Walls, because MapManagerImpl wasn't installed");

    return {};
}

void MapManager::loggerLookUp(const std::string &str)
{
    logger_->printLog(str, "[MapManager]");
}

