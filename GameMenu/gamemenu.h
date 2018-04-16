#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <GameMenu/singleplayermenu.h>
#include "multiplayermenu.h"

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMenu(QWidget *parent = nullptr);

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
};

#endif // GAMEMENU_H
