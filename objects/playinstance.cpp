#include "playinstance.h"
#include <builders/impl/body/playerofflinebodybuilder.h>
#include <builders/impl/circle/simpleofflinecirclebuilder.h>
#include <builders/impl/wall/simplewallbuilder.h>
#include <builders/impl/offlinebuilder.h>
#include <Graphics/qtgraphicsitemadapter.h>
#include <utils/data/wallinfostruct.h>
#include <utils/mapmanagertxtimpl.h>

PlayInstance::PlayInstance(const std::shared_ptr<GameData> & gameData,
                           const std::shared_ptr<Logger>& logger) :
    gameData_(gameData), logger_(logger), graphics_(std::make_shared<Graphics>())
{

    director_ = std::make_unique<Director>();
    mapManager_ = std::make_unique<MapManager>(graphics_, nullptr, logger_);

    mapManager_->setMapManagerImpl(std::make_unique<MapManagerTxtImpl>(logger_));

    // need to set PlayerBuilder for bodyDirector
    gameInfo_ = gameData->getGameInfo();
    timer_ = std::make_unique<QTimer>();
    playInstanceWidget_ = std::make_unique<PlayInstanceWidget>(gameData_, graphics_);
    connect(playInstanceWidget_.get(), &PlayInstanceWidget::exitSignal, this, &PlayInstance::stop);
}

void PlayInstance::start()
{
    //tanksList_.push_back(tankDirector_->getTank());
    initMap();
    initPlayer();

    playInstanceWidget_->show();

    initCircle();
    connect(timer_.get(), &QTimer::timeout,this, &PlayInstance::update);
    timer_->start(1000/gameInfo_.tick);

}

void PlayInstance::stop()
{
    logger_->printLog("PlayInstance is stoped", "[GAME]");
    timer_->stop();
    emit stopSignal();
}

void PlayInstance::update()
{
    logger_->printLog("PlayInstance is updated", "[GAME]");

    testBody_->update();
    circle_->update();

    std::for_each(tanksList_.cbegin(), tanksList_.cend(), [](auto& el) {
        el->update();
    });
}

TankTypes PlayInstance::playerTankType() const
{
    return playerTankType_;
}

void PlayInstance::setPlayerTankType(const TankTypes &playerTankType)
{
    playerTankType_ = playerTankType;
}

void PlayInstance::initPlayer()
{
    // Test need to delete
    TankBodyInfo bodyInfo = gameData_->getBodyInfoByType(BodyTypes::DEFAULT);

    std::shared_ptr<Builder> builder =
            std::make_shared<OfflineBuilder>(std::make_shared<PlayerOfflineBodyBuilder>(bodyInfo, graphics_, logger_));

    testBody_ = director_->getTankBody(builder);
}

void PlayInstance::initCircle()
{
    CircleInfo circleInfo = gameData_->getCircleInfo();
    std::shared_ptr<Builder> builder =
            std::make_shared<OfflineBuilder>(
                std::make_shared<SimpleOfflineCircleBuilder>(graphics_, nullptr, logger_, circleInfo));

    circle_ = director_->getCircle(builder);
}

void PlayInstance::initMap()
{
    // Пока только один тип
    auto file = gameData_->getMapFileByType(MapTypes::DEFAULT);
    mapManager_->upload(file);
    mapManager_->create();
}
