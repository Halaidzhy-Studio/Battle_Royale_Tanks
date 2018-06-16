#include "logiccirclecomponent.h"

LogicCircleComponent::LogicCircleComponent(const CircleInfo &circleInfo) :
    circleInfoConst_(circleInfo), circleInfoDynamic_(circleInfo), timeToMove_(circleInfo.start_delay)
{
}

int LogicCircleComponent::getRadius() const
{
    return circleInfoDynamic_.r;
}

void LogicCircleComponent::decrease()
{
    circleInfoDynamic_.r -= circleInfoDynamic_.speed;
}

CircleInfo LogicCircleComponent::getCircleInfo() const
{
    return circleInfoConst_;
}

int LogicCircleComponent::circleToMoveTime() const
{
    return timeToMove_;
}

