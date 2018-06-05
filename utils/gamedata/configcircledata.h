#ifndef CONFIGCIRCLEDATA_H
#define CONFIGCIRCLEDATA_H

#include <utils/gamedata/configextractor.h>

class ConfigCircleData : public ConfigExtractor
{
public:
    ConfigCircleData() = delete;
    ConfigCircleData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger);

    ~ConfigCircleData() = default;

    CircleInfo getCircleInfo() override;
};

#endif // CONFIGCIRCLEDATA_H
