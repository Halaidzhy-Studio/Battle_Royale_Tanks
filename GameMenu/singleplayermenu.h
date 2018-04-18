    #ifndef SINGLEPLAYERMENU_H
#define SINGLEPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <PlayScene/gameinstance.h>

class SingleplayerMenu: public QWidget
{
    Q_OBJECT

public:
    explicit SingleplayerMenu(QWidget* parent = nullptr);
    ~SingleplayerMenu();

    void initWindow();
signals:
    void mainWindow();

private slots:
    void backToMainWindow();
    void startGame();

private:
    QPushButton* startGameBTN_;
    QPushButton* backToMainWindowBTN_;
    GameInstance* gameInstance_;
};

#endif // SINGLEPLAYERMENU_H
