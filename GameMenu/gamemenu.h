#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <GameMenu/singleplayermenu.h>
#include <libconfig.h++>
#include "multiplayermenu.h"

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMenu(int width, int height,
                      const std::shared_ptr<libconfig::Config> config, QWidget *parent = nullptr);

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

    std::shared_ptr<libconfig::Config> config_;
    int menuWidth_;
    int menuHeight_;
};

#endif // GAMEMENU_H
