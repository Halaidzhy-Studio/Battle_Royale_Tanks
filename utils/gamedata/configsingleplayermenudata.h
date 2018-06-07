#ifndef SINGLEPLAYERMENUDATA_H
#define SINGLEPLAYERMENUDATA_H

#include "configextractor.h"
#include <utils/data/menu/singleplayermenuinfostruct.h>

class ConfigSingleplayerMenuData : public ConfigExtractor
{
public:
    ConfigSingleplayerMenuData(const std::shared_ptr<Config>& config,
                               const std::shared_ptr<Logger>& logger);

    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
};

#endif // SINGLEPLAYERMENUDATA_H
