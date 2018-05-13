#include "bodybuilderdirector.h"

BodyBuilderDirector::BodyBuilderDirector()
{

}

void BodyBuilderDirector::setBuilder(const std::shared_ptr<BodyBuilder> &builder)
{
    builder_ = builder;
}

std::shared_ptr<TankBody> BodyBuilderDirector::getBody()
{

    if (!builder_){
        std::shared_ptr<TankBody> body = std::make_shared<TankBody>();

        body->setHandleInputComponent(builder_->getHandleInputComponent());
        body->setPhysicsComponent(builder_->getPhysicsComponent());
        body->setViewComponent(builder_->getViewComponent());

        
    }
}
