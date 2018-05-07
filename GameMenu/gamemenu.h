#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <GameMenu/singleplayermenu.h>
#include <utils/data/menu/menuwindowinfostruct.h>
#include <utils/gamedata.h>

#include "multiplayermenu.h"

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMenu( const std::shared_ptr<GameData>& gameData, QWidget *parent = nullptr);

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
    MenuWindowInfo menuWindowInfo_;
};

#endif // GAMEMENU_H
