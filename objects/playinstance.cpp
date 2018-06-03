#include "playinstance.h"

PlayInstance::PlayInstance(const std::shared_ptr<GameData> & gameData,
                           const std::shared_ptr<Logger>& logger) :
    gameData_(gameData), logger_(logger), graphics_(std::make_shared<Graphics>())
{

    tankDirector_ = std::make_unique<TankBuilderDirector>();

    // need to set PlayerBuilder for bodyDirector
    gameInfo_ = gameData->getGameInfo();
    timer_ = std::make_unique<QTimer>();
    playInstanceWidget_ = std::make_unique<PlayInstanceWidget>(gameData_, graphics_);
    connect(playInstanceWidget_.get(), &PlayInstanceWidget::exitSignal, this, &PlayInstance::stop);
}

void PlayInstance::start()
{
    //tanksList_.push_back(tankDirector_->getTank());
    connect(timer_.get(), &QTimer::timeout,this, &PlayInstance::update);
    playInstanceWidget_->show();
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
