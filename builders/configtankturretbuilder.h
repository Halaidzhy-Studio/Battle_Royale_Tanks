#ifndef CONFIGTANKTURRETBUILDER_H
#define CONFIGTANKTURRETBUILDER_H

#include "interfaces/turretbuilder.h"
#include "objects/tankturret.h"

class ConfigTankTurretBuilder : public TurretBuilder
{
public:
    ConfigTankTurretBuilder() = default;
    ConfigTankTurretBuilder(const TankTurretInfo& tankTurretInfo) : tankTurretInfo_(tankTurretInfo) {}
private:
    TankTurretInfo tankTurretInfo_;
};

#endif // CONFIGTANKTURRETBUILDER_H
