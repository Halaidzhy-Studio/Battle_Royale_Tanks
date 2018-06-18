#include "handleinputcomponentcircleimpl.h"
#include "QTimer"
#include <utils/gamedata/gamedata.h>

HandleInputComponentCircleImpl::HandleInputComponentCircleImpl(
        const std::shared_ptr<LogicCircleComponent> &logicCircle,
        const std::shared_ptr<Logger> &logger) :
    logicCircle_(logicCircle), logger_(logger),
    isCanMoving_(false), isNeverMove_(false), isCanDecrease_(true)
{
    nextRadius_ = logicCircle_->getRadius();
    calculateNextRadius();
    logicCircle->createShapeCircle(nextRadius_);

    commandTimer_ = std::make_unique<QTimer>();
    connect(commandTimer_.get(), &QTimer::timeout, this, &HandleInputComponentCircleImpl::commandCall);

    timer_ = std::make_unique<QTimer>();
    connect(timer_.get(), &QTimer::timeout, this, &HandleInputComponentCircleImpl::timeDecrease);

    // 1000 мс
    timer_->start(SECOND);
}

void HandleInputComponentCircleImpl::update()
{
    if (isCanMoving_ && !isNeverMove_){
        if (nextRadius_ >= logicCircle_->getRadius()){
            if (nextRadius_ <= logicCircle_->getCircleInfoPtr()->min_r){
                isNeverMove_ = true;
            }

            isCanMoving_ = false;
            isCanDecrease_ = false;

            calculateNextRadius();
            commandTimer_->stop();

            logicCircle_->createShapeCircle(nextRadius_);
            logicCircle_->setCircleTimeToMove(logicCircle_->getCircleInfo().simple_delay);
            timer_->start(SECOND);
        }

        if (isCanDecrease_){
            isCanDecrease_ = false;
            commandTimer_->start(SECOND);
        }

    }
}

void HandleInputComponentCircleImpl::initCommand()
{
    auto modifableObject = std::dynamic_pointer_cast<Modifiable>(logicCircle_);
    if (modifableObject)
        command = std::make_shared<DecreaseCommand>(modifableObject);
}

void HandleInputComponentCircleImpl::calculateNextRadius()
{
    if (nextRadius_ - logicCircle_->getCircleInfoPtr()->r_k > logicCircle_->getCircleInfoPtr()->min_r){
        nextRadius_ -= logicCircle_->getCircleInfoPtr()->r_k;
    } else {
        nextRadius_ = logicCircle_->getCircleInfoPtr()->min_r;
    }
}

void HandleInputComponentCircleImpl::timeDecrease(){
    if (logicCircle_->circleToMoveTime() > 0){
        logicCircle_->setCircleTimeToMove(logicCircle_->circleToMoveTime() - 1);
    }else {
        timer_->stop();
        isCanMoving_ = true;
        isCanDecrease_ = true;
    }
}

void HandleInputComponentCircleImpl::commandCall()
{
    if (command)
        command->execute();
}

void HandleInputComponentCircleImpl::canMove()
{
    isCanMoving_ = true;
}

