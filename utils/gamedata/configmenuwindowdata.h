#ifndef CONFIGMENUWINDOWDATA_H
#define CONFIGMENUWINDOWDATA_H

#include "configgamedata.h"
#include <utils/data/menu/menuwindowinfostruct.h>
using namespace libconfig;
class ConfigMenuWindowData : public ConfigGameData
{
public:
    ConfigMenuWindowData(const std::shared_ptr<Config>& config) : ConfigGameData(std::move("Is ConfigMenuWindowData created"),
                                                                                 config),
        config_(config) { }
    // GameData interface
public:
    MenuWindowInfo getMenuWindowInfo();
private:
    std::shared_ptr<Config> config_;
};

#endif // CONFIGMENUWINDOWDATA_H
