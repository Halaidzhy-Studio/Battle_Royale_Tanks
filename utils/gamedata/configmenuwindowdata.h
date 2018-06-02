#ifndef CONFIGMENUWINDOWDATA_H
#define CONFIGMENUWINDOWDATA_H

#include "configextractorlibconfig.h"
#include <utils/data/menu/menuwindowinfostruct.h>

using namespace libconfig;

class ConfigMenuWindowData : public ConfigExtractorLibconfig
{
public:
    ConfigMenuWindowData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger,
                         bool configIsUpload);
    MenuWindowInfo getMenuWindowInfo() override;
};

#endif // CONFIGMENUWINDOWDATA_H
