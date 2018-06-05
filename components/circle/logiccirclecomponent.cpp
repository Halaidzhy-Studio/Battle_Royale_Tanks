#include "logiccirclecomponent.h"

LogicCircleComponent::LogicCircleComponent(const CircleInfo &circleInfo) :
    circleInfoConst_(circleInfo), circleInfoDynamic_(circleInfo)
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

