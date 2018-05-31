#ifndef CONFIGSERVERDATA_H
#define CONFIGSERVERDATA_H

#include "configextractorlibconfig.h".h"

class ConfigServerData : public ConfigExtractorLibconfig
{
public:
    ConfigServerData(const std::shared_ptr<libconfig::Config>& config,
                              const std::shared_ptr<Logger>& logger,
                              bool configIsUpload) :
                              ConfigExtractorLibconfig(
                              config, logger, configIsUpload), configIsUpload_(configIsUpload),
                              logger_(logger), config_(config) {
        std::string total = "ConfigMultiplayerMenuData is created";
        logger_->printLog(total, "[CONFIG]");
    }
    ServerInfo getServerInfo() const override;

private:
    std::shared_ptr<libconfig::Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

#endif // CONFIGSERVERDATA_H
