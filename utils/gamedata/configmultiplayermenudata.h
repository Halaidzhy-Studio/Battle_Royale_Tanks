#ifndef CONFIGMULTIPLAYERMENUDATA_H
#define CONFIGMULTIPLAYERMENUDATA_H

#include "configextractorlibconfig.h"

class ConfigMultiplayerMenuData : public ConfigExtractorLibconfig
{
public:
    ConfigMultiplayerMenuData(const std::shared_ptr<Config>& config,
                              const std::shared_ptr<Logger>& logger,
                              bool configIsUpload) :
                              ConfigExtractorLibconfig(std::move("Is ConfigMenuWindowData created"),
                              config, logger, configIsUpload), configIsUpload_(configIsUpload),
                              logger_(logger), config_(config) { }

    // GameData interface
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;

private:
    std::shared_ptr<Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

#endif // CONFIGMULTIPLAYERMENUDATA_H
