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
#include <Graphics/qtgraphicssceneadapter.h>
#include <Physics/box2dphysicsadapter.h>

PlayInstance::PlayInstance(const std::shared_ptr<GameData> & gameData,
                           const std::shared_ptr<Logger>& logger) :
    gameData_(gameData), logger_(logger),
    graphics_(std::make_shared<QtGraphicsAdapter>(
        logger, std::make_shared<QtGraphicsSceneAdapter>(logger))),
    physics_(std::make_shared<Box2dPhysicsAdapter>(gameData, logger))
{

    director_ = std::make_unique<Director>();
    mapManager_ = std::make_unique<MapManager>(graphics_, nullptr, logger_);
    mapManager_->setMapManagerImpl(std::make_unique<MapManagerTxtImpl>(logger_));

    playerHud_ =  std::make_shared<PlayerHUD>(gameData_, logger_);
    window_ = std::make_unique<PlayWindow>(gameData_, graphics_, logger_);
    window_->setRenderView(graphics_);
    window_->initPlayerHud(playerHud_);
    window_->initInterface();

    gameInfo_ = gameData->getGameInfo();
    timer_ = std::make_unique<QTimer>();

    connect(window_.get(), &PlayWindow::exitSignal, this, &PlayInstance::stop);
}

void PlayInstance::start()
{
    initMap();

    initPlayer();
    window_->show();

    initWalls();
    initCircle();
    connect(timer_.get(), &QTimer::timeout,this, &PlayInstance::update);
    timer_->start(SECOND/gameInfo_.tick);

}

void PlayInstance::stop()
{
    logger_->printLog("PlayInstance is stoped", "[GAME]");
    timer_->stop();
    emit stopSignal();
}

void PlayInstance::update()
{

    circle_->update();
    physics_->update();
    for(const auto& el: tanksList_)
        el->update();

    playerHud_->update();

    checkGameState();
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

    std::shared_ptr<LogicBodyComponent> logicBody =
            std::make_shared<LogicBodyComponent>(bodyInfo, logger_);

    std::shared_ptr<LogicTurretComponent> logicTurret =
            std::make_shared<LogicTurretComponent>(turretInfo, logger_);

    auto body = director_->getTankBody(
                std::make_shared<OfflineBuilder>(
                    std::make_shared<PlayerOfflineBodyBuilder>(bodyInfo, graphics_,
                                                               logger_, playerHud_,
                                                               physics_, logicBody)
                    )
                );

    auto turret = director_->getTurret(
                std::make_shared<OfflineBuilder>(
                    std::make_shared<PlayerOfflineTurretBuilder>(graphics_, physics_,logger_,
                                                                 turretInfo, playerHud_,
                                                                 logicTurret)
                    )
                );

    auto tank = std::make_shared<TankComplexObject>(body, turret, logicBody, logicTurret);
    tanksList_.push_back(tank);
    tanksList_[0]->setPos(mapManager_->getPlayerStartCoord());
}

void PlayInstance::initCircle()
{
    CircleInfo circleInfo = gameData_->getCircleInfo();
    std::shared_ptr<Builder> builder =
            std::make_shared<OfflineBuilder>(
                std::make_shared<SimpleOfflineCircleBuilder>(graphics_, nullptr, logger_,
                                                             circleInfo, playerHud_, tanksList_));

    circle_ = director_->getCircle(builder);
}

void PlayInstance::initMap()
{
    // Пока только один тип
    auto file = gameData_->getMapFileByType(MapTypes::DEFAULT);
    mapManager_->upload(file);
    mapManager_->create();

}

void PlayInstance::initWalls()
{
    WallInfo info = gameData_->getWallInfo();
    auto walls =  mapManager_->getWalls();

    for (const auto& wallCoord: walls){

        auto copyInfo = info;
        auto copyCoord = wallCoord;

        copyInfo.x = copyCoord.a.toQt().x();
        copyInfo.y = copyCoord.a.toQt().y();

        auto wall = director_->getWall(std::make_shared<OfflineBuilder>(
                                           std::make_shared<SimpleWallBuilder>(
                                               graphics_, physics_, logger_, copyInfo
                                )));
        walls_.push_back(wall);
    }
}

void PlayInstance::checkGameState()
{
    if (!tanksList_[0]->isTankAlive() && tanksList_.size() == 1){
        window_->showWinState();
    }
}
