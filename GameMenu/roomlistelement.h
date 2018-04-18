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
    explicit RoomListElement(QWidget *parent = nullptr, GameRoom* gameRoom = nullptr,
                             GameInstance* gameInstance = nullptr);
    ~RoomListElement();

signals:
    void doCloseMenu();
public slots:
    void connectToRoom();

private:

    QPushButton* connectToRoomBTN_;
    QLabel* roomName_;

    GameRoom* gameRoom_;
    GameInstance* gameInstance_;

};

#endif // ROOMLISTELEMENT_H
