#ifndef ROOMLISTELEMENT_H
#define ROOMLISTELEMENT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class RoomListElement : public QWidget
{
    Q_OBJECT
public:
    explicit RoomListElement(QWidget *parent = nullptr);

signals:

public slots:
    void connectToRoom(int roomNumber);
private:
    QPushButton* connectToRoomBTN_;
    QLabel* roomName_;
};

#endif // ROOMLISTELEMENT_H
