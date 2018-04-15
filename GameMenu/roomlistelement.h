#ifndef ROOMLISTELEMENT_H
#define ROOMLISTELEMENT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <memory>

#include "GameMenu/gameroom.h"
#include <PlayScene/gameinstance.h>

class RoomListElement : public QWidget
{
    Q_OBJECT

public:
    explicit RoomListElement(QWidget *parent = nullptr, GameRoom* gameRoom = nullptr);
    ~RoomListElement();

    GameRoom *gameRoom() const;
    void setGameRoom(GameRoom *gameRoom);


    GameInstance* gameScene() const;
    void setGameScene(GameInstance* gameScene);

signals:
    void doCloseMenu();
public slots:
    void connectToRoom();

private:

    QPushButton* connectToRoomBTN_;
    QLabel* roomName_;

    GameRoom* gameRoom_;
    GameInstance* gameScene_;

};

#endif // ROOMLISTELEMENT_H
