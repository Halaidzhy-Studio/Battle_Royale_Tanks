#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <GameMenu/singleplayermenu.h>
#include <utils/data/menu/menuwindowinfostruct.h>
#include <utils/gamedata/gamedata.h>
#include "multiplayermenu.h"
#include <utils/loggerinterface.h>

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    GameMenu() = default;
    explicit GameMenu( const std::shared_ptr<GameData>& gameData,
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

    std::shared_ptr<Logger> logger_;

    MenuWindowInfo menuWindowInfo_;

    void initInterface();
};

#endif // GAMEMENU_H
