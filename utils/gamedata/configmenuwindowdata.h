#ifndef CONFIGMENUWINDOWDATA_H
#define CONFIGMENUWINDOWDATA_H

#include "configextractor.h"
#include <utils/data/menu/menuwindowinfostruct.h>

class ConfigMenuWindowData : public ConfigExtractor
{
public:
    ConfigMenuWindowData() = delete;
    ~ConfigMenuWindowData() = default;
    ConfigMenuWindowData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger);
    MenuWindowInfo getMenuWindowInfo() override;
};

#endif // CONFIGMENUWINDOWDATA_H
