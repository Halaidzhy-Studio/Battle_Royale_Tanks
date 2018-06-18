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
private:
    template<typename T>
    void lookupWrapper(const std::string &setting, T &var);
};

#endif // CONFIGMENUWINDOWDATA_H
