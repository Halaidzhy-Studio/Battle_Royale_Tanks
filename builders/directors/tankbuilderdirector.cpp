#include "tankbuilderdirector.h"
std::shared_ptr<TankComplexObject> TankBuilderDirector::getTank()
{
    if (builder_){
        auto tank = std::make_shared<TankComplexObject>();

        tank->setBody( builder_->getBody() );
        tank->setTurret( builder_->getTurret() );

        return tank;
    }

    return nullptr;
}

void TankBuilderDirector::setBuilder(const std::shared_ptr<TankBuilder> &builder)
{
    builder_ = builder;
}
