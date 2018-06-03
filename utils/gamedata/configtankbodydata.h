#ifndef CONFIGTANKBODYDATA_H
#define CONFIGTANKBODYDATA_H

#include "configextractor.h"

class ConfigTankBodyData : public ConfigExtractor
{
public:
    ConfigTankBodyData() = delete;
    ConfigTankBodyData(const std::shared_ptr<Config> &config,
                       const std::shared_ptr<Logger> &logger);
    ~ConfigTankBodyData() = default;

    TankBodyInfo getBodyInfoByType(BodyTypes type) override;

private:
    static const std::string listNameInConfig_;

    int findIndexOfType(const std::string &type);
};

#endif // CONFIGTANKBODYDATA_H
