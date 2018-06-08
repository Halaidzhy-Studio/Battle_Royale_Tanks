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
        logger_->printLog("Can't upload Map, because MapManagerImpl wasn't installed", "[MapManager]");
}

void MapManager::create()
{
    if (impl_){
        int width = impl_->getSceneWidth();
        int height = impl_->getSceneHeight();
        graphics_->setSceneRect(-width/2, -height/2, width, height);
    }else
        logger_->printLog("Can't create Map, because MapManagerImpl wasn't installed", "[MapManager]");
}

Coordinate MapManager::getPlayerStartCoord()
{
    return impl_->getPlayerPos();
}

