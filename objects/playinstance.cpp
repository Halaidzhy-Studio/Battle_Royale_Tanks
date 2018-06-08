#include "playinstance.h"
#include <builders/impl/body/playerofflinebodybuilder.h>
#include <builders/impl/circle/simpleofflinecirclebuilder.h>
#include <builders/impl/wall/simplewallbuilder.h>
#include <builders/impl/offlinebuilder.h>
#include <Graphics/qtgraphicsitemadapter.h>
#include <utils/data/wallinfostruct.h>
#include <utils/mapmanagertxtimpl.h>
#include <builders/impl/turret/playerofflineturretbuilder.h>
#include <Graphics/qtgraphicsadapter.h>

PlayInstance::PlayInstance(const std::shared_ptr<GameData> & gameData,
                           const std::shared_ptr<Logger>& logger) :
    gameData_(gameData), logger_(logger), graphics_(std::make_shared<QtGraphicsAdapter>(logger))
{

    director_ = std::make_unique<Director>();
    mapManager_ = std::make_unique<MapManager>(graphics_, nullptr, logger_);
    mapManager_->setMapManagerImpl(std::make_unique<MapManagerTxtImpl>(logger_));

    window_ = std::make_unique<PlayWindow>(gameData_);
    window_->setRenderView(graphics_);
    //playerHud_ = std::make_shared<PlayerHUD>();
    gameInfo_ = gameData->getGameInfo();
    timer_ = std::make_unique<QTimer>();

    connect(window_.get(), &PlayWindow::exitSignal, this, &PlayInstance::stop);
}

void PlayInstance::start()
{
    initMap();
    initPlayer();
    window_->show();

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
    circle_->update();
    for(const auto& el: tanksList_)
        el->update();
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

    TankBodyInfo bodyInfo = gameData_->getBodyInfoByType(BodyTypes::DEFAULT);
    TankTurretInfo turretInfo = gameData_->getTurretInfoByType(TurretTypes::DEFAULT);


    auto body = director_->getTankBody(
                std::make_shared<OfflineBuilder>(
                    std::make_shared<PlayerOfflineBodyBuilder>(bodyInfo, graphics_, logger_)
                    )
                );

    auto turret = director_->getTurret(
                std::make_shared<OfflineBuilder>(
                    std::make_shared<PlayerOfflineTurretBuilder>(graphics_, nullptr,logger_, turretInfo)
                    )
                );

    tanksList_.push_back(std::make_shared<TankComplexObject>(body, turret));
    tanksList_[0]->setPos(mapManager_->getPlayerStartCoord());
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
