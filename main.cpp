#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "GameMenu/gamemenu.h"
#include "utils/logger.h"
#include "utils/gamedata.h"
#include "utils/configgamedata.h"
#include <libconfig.h++>
#include <memory>
#include "game.h"
#include "engine.h"
#include "engineqt.h"

using namespace libconfig;

//#include "playwidget.h"



int main(int argc, char *argv[])
{

    std::shared_ptr<Engine> engineQt = std::make_shared<EngineQT>(argc, argv);

    std::shared_ptr<ConfigGameData> gameConfig(new ConfigGameData());
    gameConfig->upload("/home/sinimawath/QtProjects/Battle-Royale-Tank/Resources/config.cfg");
    std::shared_ptr<GameData> gameData = std::dynamic_pointer_cast<GameData>(gameConfig);

    engineQt->setGameData(gameData);

    return engineQt->startGame();
}
