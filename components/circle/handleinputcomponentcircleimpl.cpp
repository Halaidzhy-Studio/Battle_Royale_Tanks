#include "handleinputcomponentcircleimpl.h"
#include "QTimer"
HandleInputComponentCircleImpl::HandleInputComponentCircleImpl(
        const std::shared_ptr<LogicCircleComponent> &logicCircle,
        const std::shared_ptr<Logger> &logger) :
    logicCircle_(logicCircle), logger_(logger),
    isCanMoving_(false), isNeverMove_(false)
{
    nextRadius_ = logicCircle_->getRadius();
    calculateNextRadius();
    QTimer::singleShot(1000*logicCircle_->getCircleInfo().start_delay, [this](){
        isCanMoving_ = true;
    });
}

void HandleInputComponentCircleImpl::update()
{
    if (isCanMoving_ && !isNeverMove_){
        if (nextRadius_ >= logicCircle_->getRadius()){
            if (nextRadius_ <= logicCircle_->getCircleInfo().min_r){
                isNeverMove_ = true;
            }

            isCanMoving_ = false;
            calculateNextRadius();
            QTimer::singleShot(1000*logicCircle_->getCircleInfo().simple_delay,
                               [this](){
                isCanMoving_ = true;
            });
        }

        command->execute();
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
