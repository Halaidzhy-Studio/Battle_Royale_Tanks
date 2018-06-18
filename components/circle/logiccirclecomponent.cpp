#include "logiccirclecomponent.h"
#include <builders/director.h>
#include <builders/impl/circle/simpleofflinecirclebuilder.h>
#include <builders/impl/offlinebuilder.h>

LogicCircleComponent::LogicCircleComponent(const CircleInfo &circleInfo,
                                           const std::shared_ptr<Graphics>& graphics,
                                           const std::shared_ptr<Logger>& logger) :
    circleInfoConst_(circleInfo), circleInfoDynamic_(circleInfo),
    timeToMove_(circleInfo.start_delay), graphics_(graphics), logger_(logger)
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

const CircleInfo *LogicCircleComponent::getCircleInfoPtr()
{
    return &circleInfoConst_;
}

void LogicCircleComponent::createShapeCircle(int radius)
{
    Director director;
    CircleInfo circleInfo = circleInfoConst_;
    circleInfo.styleInfo.opacity = circleInfo.circleShape.opacity;
    circleInfo.r = radius;
    if (shapeCircle_){
        shapeCircle_->viewComponent()->close();
        shapeCircle_.reset();
    }
    shapeCircle_ = director.getShapeCircle(std::make_shared<OfflineBuilder>(
            std::make_shared<SimpleOfflineCircleBuilder>(graphics_, nullptr, logger_,
                                                         circleInfo, nullptr,
                                                         std::vector<std::shared_ptr<TankComplexObject>>())));
}

int LogicCircleComponent::circleToMoveTime() const
{
    return timeToMove_;
}

void LogicCircleComponent::setCircleTimeToMove(int time)
{
    timeToMove_ = time;
}

void LogicCircleComponent::setGraphics(const std::shared_ptr<Graphics> &graphics)
{
    graphics_ = graphics;
}

Coordinate LogicCircleComponent::getCenter()
{
    return Coordinate(circleInfoDynamic_.center_x, circleInfoDynamic_.center_y, Coordinate::CoordTypes::QT, logger_);
}

int LogicCircleComponent::getDmg() const
{
    return circleInfoDynamic_.dmg;
}

ContactEntityTypes LogicCircleComponent::getEntityType()
{
    return ContactEntityTypes::CIRCLE;
}
