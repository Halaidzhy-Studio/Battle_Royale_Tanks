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

}
