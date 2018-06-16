#ifndef CONFIGHUDDATA_H
#define CONFIGHUDDATA_H

#include <utils/gamedata/configextractor.h>
class ConfigHudData : public ConfigExtractor
{
public:
    ConfigHudData() = delete;
    ~ConfigHudData() = default;
    ConfigHudData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger);

    HudInfo getHudInfo() override;
};

#endif // CONFIGHUDDATA_H
