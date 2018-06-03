#include "configserverdata.h"

ConfigServerData::ConfigServerData(const std::shared_ptr<Config> &config,
                                   const std::shared_ptr<Logger> &logger)  :
    ConfigExtractor( config, logger)
{
    logger_->printLog("ConfigServerData is created", "[CONFIG]");
}

ServerInfo ConfigServerData::getServerInfo()
{

}
