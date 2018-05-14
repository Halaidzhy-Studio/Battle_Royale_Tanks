#ifndef SINGLEPLAYERMENUDATA_H
#define SINGLEPLAYERMENUDATA_H

#include "configextractorlibconfig.h"
#include <utils/data/menu/singleplayermenuinfostruct.h>

using namespace libconfig;

class ConfigSingleplayerMenuData : public ConfigExtractorLibconfig
{
public:
    ConfigSingleplayerMenuData(const std::shared_ptr<Config>& config,
                               const std::shared_ptr<Logger>& logger,
                               bool configIsUpload ) :
        ConfigExtractorLibconfig(std::move(" Is ConfigSignlePLayerMenuData created "),
        config, logger, configIsUpload), config_(config), logger_(logger),
        configIsUpload_(configIsUpload){}

    // GameData interface
public:
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;

private:
    std::shared_ptr<Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

#endif // SINGLEPLAYERMENUDATA_H
