#ifndef CONFIGSERVERDATA_H
#define CONFIGSERVERDATA_H

#include "configextractor.h"

class ConfigServerData : public ConfigExtractor
{
public:
    ConfigServerData() = delete;
    ConfigServerData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger);
    ~ConfigServerData() = default;
    ServerInfo getServerInfo() override;
};

#endif // CONFIGSERVERDATA_H
