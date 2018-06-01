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

class MultiplayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerMenu(const std::shared_ptr<GameData>& gameData,
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

    MultiplayerMenuInfo multiplayerMenuInfo_;
    QPushButton* backToMainWindowBTN_;
    QPushButton* startMultiplayerGameBTN_;
    QLabel* choseTankLabel_;

    QPushButton* prevTankBTN_;
    QPushButton* nextTankBTN_;
    QPixmap* currentTankTypeImage_;

    std::string currentTankTypeString_;

};

#endif // MULTIPLAYERMENU_H
