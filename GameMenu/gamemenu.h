#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <GameMenu/singleplayermenu.h>
#include <utils/data/menu/menuwindowinfostruct.h>
#include <utils/gamedata/gamedata.h>
#include "game.h"
#include "multiplayermenu.h"
#include <utils/loggerinterface.h>

// потому что вызыватся из Game
class Game;

class MultiplayerMenu;
class SingleplayerMenu;

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    GameMenu() {}
    explicit GameMenu( const std::shared_ptr<GameData>& gameData,
                       const std::shared_ptr<Game>& game,
                       const std::shared_ptr<Logger>& logger,
                       QWidget *parent = nullptr);

signals:

public slots:
    void showSingleplayerMenu();
    void showMultiplayerMenu();

private:
    QPushButton* singleplayerBTN_;
    QPushButton* multiplayerBTN_;
    QPushButton* exitBTN_;
    SingleplayerMenu* spWindow_;
    MultiplayerMenu* mpWindow_;

    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Game> game_;
    std::shared_ptr<Logger> logger_;

    MenuWindowInfo menuWindowInfo_;
};

#endif // GAMEMENU_H
