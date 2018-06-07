#ifndef CONFIGGAMEINFODATA_H
#define CONFIGGAMEINFODATA_H

#include <utils/gamedata/configextractor.h>
class ConfigGameInfoData : public ConfigExtractor
{
public:
    ConfigGameInfoData() = delete;
    ConfigGameInfoData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger);
    ~ConfigGameInfoData() = default;

    GameInfo getGameInfo() override;
};

#endif // CONFIGGAMEINFODATA_H
