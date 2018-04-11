#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QTimer>
#include <GameObjects/tank.h>

namespace Ui {
class Singleplayer;
}

class Singleplayer : public QWidget
{
    Q_OBJECT

public:
    explicit Singleplayer(QWidget *parent = 0);
    ~Singleplayer();

signals:
    void mainWindow();

public slots:
    void backToMainWindow();
private:
    Ui::Singleplayer *ui;
    QPushButton* backToMainWindowBTN_;
    QGraphicsScene* playScene_;
    QGraphicsView* playView_;
    QTimer* gameTimer_;
    QVector<Tank*> tanks_;
    Tank* player_;

    void getTanks(QVector<Tank *> &tanks);
    void addTanksToScene(QVector<Tank *> &tanks, QGraphicsScene *playScene);
};

#endif // SINGLEPLAYER_H
