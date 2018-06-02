#ifndef CONFIGGAMEWINDOWDATA_H
#define CONFIGGAMEWINDOWDATA_H

#include "configextractorlibconfig.h"

class ConfigGameWindowData : public ConfigExtractorLibconfig
{
public:
    ConfigGameWindowData(const std::shared_ptr<libconfig::Config>& config,
                         const std::shared_ptr<Logger>& logger,
                         bool configIsUpload);
    ~ConfigGameWindowData();

    GameWindowInfo getGameWindowInfo() override;
};

#endif // CONFIGGAMEWINDOWDATA_H
