#include "configmapfiledata.h"


const std::string ConfigMapFileData::listNameInConfig_ = "game.map.types";

ConfigMapFileData::ConfigMapFileData(const std::shared_ptr<Config> &config,
                                     const std::shared_ptr<Logger> &logger) : ConfigExtractor(config, logger)
{
}


std::string ConfigMapFileData::getMapFileByType(MapTypes type)
{
    std::string file = ":maps/Resources/map/default.map";

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigMapFileData is downloading", "[CONFIG]");

        int index = findIndexOfType(static_cast<int>(type));
        if (index == -1){
            std::string total = "No '" + std::to_string(static_cast<int>(type))
                    + "' in config in '" + listNameInConfig_ + "'\n";
            logger_->printLog(total, "[CONFIG]");
        } else {
            config_->lookup(listNameInConfig_, index, "file", file);
        }
    }

    return file;
}

// Вынесу в конфиг класс, если будет время
int ConfigMapFileData::findIndexOfType(const int& type){
    int lengthOfList = config_->getLengthOfList(listNameInConfig_);

    for (int i = 0; i < lengthOfList; i++){
        int tmp;
        config_->lookup(listNameInConfig_, i, "type", tmp);

        if (tmp == type)
            return i;
    }

    return -1;
}
