#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QVector>
#include <vector>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <utils/data/menu/multiplayermenuinfostruct.h>
//#include <PlayScene/multiplayer.h>
#include <GameMenu/gameroom.h>
#include "game.h"

//потому что вызыватся из GameMenu, который в свою очередь первый раз вызывает из Game.
class Game;
class SingleplayerMenu;

class MultiplayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerMenu(const std::shared_ptr<GameData>& gameData,
                             const std::shared_ptr<Game>& game,
                             QWidget *parent = 0);
    ~MultiplayerMenu();
signals:
    void mainWindow();
public slots:
    void backToMainWindow();
    void onShow();
    void startMultiplayerGame();
    void nextTank();
    void previousTank();

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Game> game_;
    MultiplayerMenuInfo multiplayerMenuInfo_;
    QPushButton* backToMainWindowBTN_;
    QPushButton* startMultiplayerGameBTN_;
    QLabel* choseTankLabel_;

    QPushButton* prevTankBTN_;
    QPushButton* nextTankBTN_;

    //std::vector<TankTypeEnum> tankTypeList_;
    //int currentTankTypeNum_;
    //TankTypeEnum chosenTankType_;
    QPixmap* currentTankTypeImage_;

    std::string currentTankTypeString_;

};

#endif // MULTIPLAYERMENU_H
