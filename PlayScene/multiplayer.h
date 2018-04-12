#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QVector>
#include <QPushButton>
#include <memory>

#include "GameObjects/tank.h"
#include "GameMenu/gameroom.h"

class Multiplayer: public QWidget
{
    Q_OBJECT

signals:
    void multiplayerMenu();

public slots:
    void onBadConnection();
    void onGoodConnection();

    void onGetReceivingPackage();
    void onSetSendingPackage();

    void onBackToMultiplayerMenu();
public:
    explicit Multiplayer(QWidget* parent = 0, GameRoom* gameRoom = nullptr);
    ~Multiplayer();

    qint16 roomNumber() const;
    void setRoomNumber(const qint16 &roomNumber);

    void renderGame();
    void startGame();
private:
    QPushButton* backToMultiplayerMenuBTN_;

    QTimer* playSceneTimer_;
    QTimer* sendPackageTimer_;

    QGraphicsScene* playScene_;
    QGraphicsView* playView_;

    GameRoom* gameRoom_;
    quint16 roomNumber_;

    Tank* player_;
    QVector<Tank*> tanks_;

   // Map

};

#endif // MULTIPLAYER_H
