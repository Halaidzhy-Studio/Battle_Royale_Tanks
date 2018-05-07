#include "turretbuilddirector.h"

TurretBuilderDirector::TurretBuilderDirector()
{

}

void TurretBuilderDirector::setBuilder(const std::shared_ptr<TurretBuilder> &builder)
{
    builder_ = builder;
}

std::shared_ptr<TankTurret> TurretBuilderDirector::getTurret()
{

}
