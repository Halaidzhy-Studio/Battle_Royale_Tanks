    #ifndef SINGLEPLAYERMENU_H
#define SINGLEPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <memory>
#include <utils/gamedata.h>
#include <utils/data/menu/singleplayermenuinfostruct.h>

class SingleplayerMenu: public QWidget
{
    Q_OBJECT

public:
    explicit SingleplayerMenu(const std::shared_ptr<GameData>& gameData, QWidget* parent = nullptr);
    ~SingleplayerMenu();
signals:
    void mainWindow();

private slots:
    void backToMainWindow();
    void startGame();

private:
    std::shared_ptr<GameData> gameData_;
    SingleplayerMenuInfo singleplayernMenuInfo_;
    QPushButton* startGameBTN_;
    QPushButton* backToMainWindowBTN_;
};

#endif // SINGLEPLAYERMENU_H
