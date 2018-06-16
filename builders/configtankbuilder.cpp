#include "configtankbuilder.h"
#include "configtankbodybuilder.h"
#include "configtankturretbuilder.h"

std::shared_ptr<TankBody> ConfigTankBuilder::getBody()
{
    auto configTankBodyBuilder = std::make_shared<ConfigTankBodyBuilder>(tankInfo_.bodyInfo);
    bodyDirector_->setBuilder(configTankBodyBuilder);
    return bodyDirector_->getBody();
}

std::shared_ptr<TankTurret> ConfigTankBuilder::getTurret()
{
    auto configTankTurretBuilder = std::make_shared<ConfigTankTurretBuilder>(tankInfo_.turretInfo);
    turretDirector_->setBuilder(configTankTurretBuilder);
    return turretDirector_->getTurret();
}
