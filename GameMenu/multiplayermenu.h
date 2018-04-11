#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QVector>

#include <PlayScene/multiplayer.h>
#include <GameMenu/gameroom.h>

namespace Ui {
class MultiplayerMenu;
}

class MultiplayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerMenu(QWidget *parent = 0);
    ~MultiplayerMenu();

signals:
    void mainWindow();
public slots:
    void backToMainWindow();
private:

    Ui::MultiplayerMenu *ui;
    QPushButton* backToMainWindowBTN_;
    QLabel* multiplayerMenuTitle_;
    QListWidget* roomsListWidget_;

    QVector<GameRoom*> roomsList_;

    void createRoomsListElement(QListWidget*, GameRoom*);
    void formRoomsList(QListWidget*);

    void getRooms();
};

#endif // MULTIPLAYERMENU_H
