#include "configmapfiledata.h"


const std::string ConfigMapFileData::listNameInConfig_ = "game.map.types";

ConfigMapFileData::ConfigMapFileData(const std::shared_ptr<Config> &config,
                                     const std::shared_ptr<Logger> &logger) : ConfigExtractor(config, logger)
{
}


std::string ConfigMapFileData::getMapFileByType(MapTypes type)
{
    std::string file = ":map/Resources/map/default.map";

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigMapFileData is downloading", "[CONFIG]");

        int index = config_->findIndexOfType(listNameInConfig_, static_cast<int>(type));
        if (index == Config::NO_FINDED_INDEX){
            std::string total = "No '" + std::to_string(static_cast<int>(type))
                    + "' in config in '" + listNameInConfig_ + "'\n";
            logger_->printLog(total, "[CONFIG]");
        } else {
            config_->lookup(listNameInConfig_, index, "file", file);
        }
    }
    return file;
}
