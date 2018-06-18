#ifndef CONFIGWORLDPHYSICSDATA_H
#define CONFIGWORLDPHYSICSDATA_H

#include <utils/gamedata/configextractor.h>

class ConfigWorldPhysicsData : public ConfigExtractor
{
public:
    ConfigWorldPhysicsData() = delete;
    ConfigWorldPhysicsData(const std::shared_ptr<Config> &config,
                       const std::shared_ptr<Logger> &logger);
    ~ConfigWorldPhysicsData() = default;

    WorldPhysicsInfo getWorldPhysicsInfo() override;
};

#endif // CONFIGWORLDPHYSICSDATA_H
