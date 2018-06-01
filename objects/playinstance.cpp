#include "playinstance.h"

PlayInstance::PlayInstance()
{

}

PlayInstance::PlayInstance(const std::shared_ptr<GameData> & gameData,
                           const std::shared_ptr<Logger>& logger) : gameData_(gameData), logger_(logger)
{

    tankDirector_ = std::make_unique<TankBuilderDirector>();
    // need to set PlayerBuilder for bodyDirector
    gameInfo_ = gameData->getGameInfo();
    timer_ = std::make_unique<QTimer>();
    playInstanceWidget_ = new PlayInstanceWidget(gameData_);
    camera_ = new QGraphicsView();
    camera_->setParent(playInstanceWidget_);

}

void PlayInstance::start()
{
   // tanksList_.push_back(tankDirector_->getTank());
    connect(timer_.get(), &QTimer::timeout,this, &PlayInstance::update);
    timer_->start(1000/gameInfo_.tick);
    playInstanceWidget_->show();
}

void PlayInstance::stop()
{
    timer_->stop();
}

void PlayInstance::update()
{
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
