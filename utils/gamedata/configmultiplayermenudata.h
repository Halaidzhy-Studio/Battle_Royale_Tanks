#ifndef CONFIGMULTIPLAYERMENUDATA_H
#define CONFIGMULTIPLAYERMENUDATA_H

#include "configextractorlibconfig.h"

class ConfigMultiplayerMenuData : public ConfigExtractorLibconfig
{
public:
    ConfigMultiplayerMenuData(const std::shared_ptr<libconfig::Config>& config,
                              const std::shared_ptr<Logger>& logger,
                              bool configIsUpload) :
                              ConfigExtractorLibconfig(
                              config, logger, configIsUpload), configIsUpload_(configIsUpload),
                              logger_(logger), config_(config) {
        std::string total = "ConfigMultiplayerMenuData is created";
        logger_->printLog(total, "[CONFIG]");
    }

    // GameData interface
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;

private:
    std::shared_ptr<libconfig::Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

#endif // CONFIGMULTIPLAYERMENUDATA_H
