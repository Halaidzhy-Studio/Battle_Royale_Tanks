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
                              config, logger, configIsUpload){
        std::string total = "ConfigMultiplayerMenuData is created";
        logger_->printLog(total, "[CONFIG]");
    }
    ServerInfo getServerInfo() override;
};

#endif // CONFIGSERVERDATA_H
