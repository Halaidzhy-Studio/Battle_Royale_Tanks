#ifndef CONFIGGAMEINFODATA_H
#define CONFIGGAMEINFODATA_H

#include <utils/gamedata/configextractorlibconfig.h>
class ConfigGameInfoData : public ConfigExtractorLibconfig
{
public:
    ConfigGameInfoData(const std::shared_ptr<libconfig::Config>& config,
                         const std::shared_ptr<Logger>& logger,
                         bool configIsUpload);
    ~ConfigGameInfoData();
    GameInfo getGameInfo() override;
};

#endif // CONFIGGAMEINFODATA_H
