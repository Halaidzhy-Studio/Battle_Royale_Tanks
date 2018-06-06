#ifndef CONFIGMAPFILEDATA_H
#define CONFIGMAPFILEDATA_H

#include "configextractor.h"

class ConfigMapFileData : public ConfigExtractor
{
public:
    ConfigMapFileData() = delete;
    ~ConfigMapFileData() = default;
    ConfigMapFileData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger);

    std::string getMapFileByType(MapTypes type) override;
private:
    static const std::string listNameInConfig_;
    int findIndexOfType(const int &type);
};

#endif // CONFIGMAPFILEDATA_H
