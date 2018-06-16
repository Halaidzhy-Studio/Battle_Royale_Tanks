    #ifndef SINGLEPLAYERMENU_H
#define SINGLEPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <utils/data/menu/singleplayermenuinfostruct.h>
#include <objects/playinstance.h>

class SingleplayerMenu: public QWidget
{
    Q_OBJECT

public:
    SingleplayerMenu(const std::shared_ptr<GameData>& gameData,
                     const std::shared_ptr<Logger>& logger,
                              QWidget* parent = nullptr);
    ~SingleplayerMenu();
signals:
    void mainWindow();

private slots:
    void backToMainWindow();
    void startGame();

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Logger> logger_;
    std::unique_ptr<PlayInstance> playInstance_;
    SingleplayerMenuInfo singleplayernMenuInfo_;
    QPushButton* startGameBTN_;
    QPushButton* backToMainWindowBTN_;

    // Выбранный тип танка.
    TankTypes tankType_;

    void initInterface();
    void stopGame();
};

#endif // SINGLEPLAYERMENU_H
