#ifndef CONFIGTANKTURRETDATA_H
#define CONFIGTANKTURRETDATA_H

#include "configextractor.h"

class ConfigTankTurretData : public ConfigExtractor
{
public:
    ConfigTankTurretData() = delete;
    ConfigTankTurretData(const std::shared_ptr<Config> &config,
                       const std::shared_ptr<Logger> &logger);
    ~ConfigTankTurretData() = default;

    TankTurretInfo getTurretInfoByType(TurretTypes type);
private:
    static const std::string listNameInConfig_;
};

#endif // CONFIGTANKTURRETDATA_H
