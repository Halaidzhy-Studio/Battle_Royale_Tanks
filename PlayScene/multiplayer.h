#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QVector>

#include "GameObjects/tank.h"

class Multiplayer: public QWidget
{
    Q_OBJECT

signals:

public slots:
    void onBadConnection();
    void onGoodConnection();

public:
    explicit Multiplayer(QWidget* parent = 0);
    ~Multiplayer();

private:
    QTimer* playSceneTimer_;
    QTimer* sendPackageTimer_;

    QGraphicsScene* playScene_;
    QGraphicsView* playerView_;

    qint16 roomNumber_;
    Tank* player_;
    QVector<Tank*> tanks_;
};

#endif // MULTIPLAYER_H