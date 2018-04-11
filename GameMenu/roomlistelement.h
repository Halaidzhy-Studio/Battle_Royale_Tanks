#ifndef ROOMLISTELEMENT_H
#define ROOMLISTELEMENT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <memory>

#include "PlayScene/multiplayer.h"
#include "GameMenu/gameroom.h"

class RoomListElement : public QWidget
{
    Q_OBJECT

public:
    explicit RoomListElement(QWidget *parent = nullptr);
    ~RoomListElement();

    GameRoom *gameRoom() const;
    void setGameRoom(GameRoom *gameRoom);


    Multiplayer *gameScene() const;
    void setGameScene(Multiplayer *gameScene);

signals:
    void doCloseMenu();
public slots:
    void connectToRoom();

private:

    QPushButton* connectToRoomBTN_;
    QLabel* roomName_;

    GameRoom* gameRoom_;
    Multiplayer* gameScene_;

};

#endif // ROOMLISTELEMENT_H
