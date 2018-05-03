#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QVector>
#include <vector>
#include <memory>
#include "utils/tanktype.h"

//#include <PlayScene/multiplayer.h>
#include <GameObjects//gameinstance.h>
#include <GameMenu/gameroom.h>

class MultiplayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerMenu(int width, int height, QWidget *parent = 0);
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
    int menuWidth_;
    int menuHeight_;

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

    GameInstance* gameInstance_;
};

#endif // MULTIPLAYERMENU_H
