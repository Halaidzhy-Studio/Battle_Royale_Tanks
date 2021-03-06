#ifndef CONFIGGAMEWINDOWDATA_H
#define CONFIGGAMEWINDOWDATA_H

#include "configextractor.h"

class ConfigGameWindowData : public ConfigExtractor
{
public:
    ConfigGameWindowData() = delete;
    ConfigGameWindowData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& loggers);
    ~ConfigGameWindowData() = default;

    GameWindowInfo getGameWindowInfo() override;
};

#endif // CONFIGGAMEWINDOWDATA_H
