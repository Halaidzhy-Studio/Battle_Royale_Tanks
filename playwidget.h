#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H


#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

namespace Ui {
class PlayWidget;
}

class PlayWidget : public QWidget{

    Q_OBJECT

public:
    explicit PlayWidget(QWidget* parent = 0);
    ~PlayWidget();
private:
    Ui::PlayWidget* ui;
    QGraphicsScene* playScene_;
    QTimer* gameTimer;

};

#endif // PLAYWIDGET_H
