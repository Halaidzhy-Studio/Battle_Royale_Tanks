#ifndef CONFIGTANKBODYDATA_H
#define CONFIGTANKBODYDATA_H

#include "configextractorlibconfig.h"

class ConfigTankBodyData : public ConfigExtractorLibconfig
{
public:
    ConfigTankBodyData() = delete;
    ~ConfigExtractor() = default;
    ConfigTankBodyData(const std::shared_ptr<libconfig::Config> &config,
                       const std::shared_ptr<Logger> &logger,
                       bool configIsUpload);

    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
};

#endif // CONFIGTANKBODYDATA_H
