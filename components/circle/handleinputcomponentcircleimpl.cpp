#include "handleinputcomponentcircleimpl.h"
#include "QTimer"
HandleInputComponentCircleImpl::HandleInputComponentCircleImpl(
        const std::shared_ptr<LogicCircleComponent> &logicCircle,
        const std::shared_ptr<Logger> &logger) :
    logicCircle_(logicCircle), logger_(logger), isCanMoving_(false)
{
    QTimer::singleShot(1000*logicCircle_->getCircleInfo().start_delay, [this](){
        isCanMoving_ = true;
    });
}

void HandleInputComponentCircleImpl::update()
{
    if (isCanMoving_){
        command->execute();

        if (nextRadius_ <= logicCircle_->getRadius()){
            isCanMoving_ = false;
            QTimer::singleShot(1000*logicCircle_->getCircleInfo().simple_delay,
                               [this](){
                isCanMoving_ = true;
            });
        }
    }
}

void HandleInputComponentCircleImpl::initCommand()
{
    command = std::make_shared<DecreaseCommand>(std::dynamic_pointer_cast<Modifiable>(logicCircle_));
}

void HandleInputComponentCircleImpl::calculateNextRadius()
{
    if (nextRadius_ - logicCircle_->getCircleInfo().r_k > logicCircle_->getCircleInfo().min_r){
        nextRadius_ -= logicCircle_->getCircleInfo().r_k;
    } else {
        nextRadius_ = logicCircle_->getCircleInfo().min_r;
    }
}

void HandleInputComponentCircleImpl::canMove()
{
    isCanMoving_ = true;
}
