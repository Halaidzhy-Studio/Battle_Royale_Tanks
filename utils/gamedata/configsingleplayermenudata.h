#ifndef SINGLEPLAYERMENUDATA_H
#define SINGLEPLAYERMENUDATA_H

#include "configextractorlibconfig.h"
#include <utils/data/menu/singleplayermenuinfostruct.h>

class ConfigSingleplayerMenuData : public ConfigExtractorLibconfig
{
public:
    ConfigSingleplayerMenuData(const std::shared_ptr<libconfig::Config>& config,
                               const std::shared_ptr<Logger>& logger,
                               bool configIsUpload ) :
        ConfigExtractorLibconfig(
        config, logger, configIsUpload), config_(config), logger_(logger),
        configIsUpload_(configIsUpload){

        std::string total = "ConfigSingleplayerMenuData is created";
        logger_->printLog(total, "[CONFIG]");
    }

    // GameData interface
public:
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;

private:
    std::shared_ptr<libconfig::Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

#endif // SINGLEPLAYERMENUDATA_H
