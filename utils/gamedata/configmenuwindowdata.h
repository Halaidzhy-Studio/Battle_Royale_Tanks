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
                         bool configIsUpload) :
                         ConfigExtractorLibconfig(std::move("Is ConfigMenuWindowData created"),
                         config, logger, configIsUpload), configIsUpload_(configIsUpload),
                         logger_(logger), config_(config) { }
    // GameData interface
public:
    MenuWindowInfo getMenuWindowInfo() override;
private:
    bool configIsUpload_;
    std::shared_ptr<Config> config_;
    std::shared_ptr<Logger> logger_;
};

#endif // CONFIGMENUWINDOWDATA_H
