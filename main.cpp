#include <utils/gamedata/gamedata.h>
#include <utils/gamedata/configextractor.h>
#include <utils/logger.h>
#include <memory>
#include "engine.h"
#include "engineqt.h"
int main(int argc, char *argv[])
{
    std::shared_ptr<Engine> engineQt = std::make_shared<EngineQT>(argc, argv);

    std::shared_ptr<Logger> logger(new QtLogger());

    std::shared_ptr<Extractor> extractor(new ConfigExtractor(logger, argv[1]));

    std::shared_ptr<GameData> gameData = GameData::createGameData(extractor, logger);

    engineQt->setGameData(gameData);
    engineQt->setLogger(logger);
    return engineQt->startGame();

}
