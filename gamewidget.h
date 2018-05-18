#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <memory>
#include <QGraphicsView>
#include <QPushButton>
#include <utils/gamedata/gamedata.h>
#include <utils/loggerinterface.h>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(const std::shared_ptr<GameData>& gameData,
               const std::shared_ptr<Logger>& logger, QWidget* parent = 0);
    ~GameWidget();

    void initInterface();
signals:
    void backToMenuSignal();
private slots:
   void backToMenu();
private:
    QGraphicsView* qGraphicsView_;
    QPushButton* backToMenuBTN_;

    GameWindowInfo gameWindowInfo_;
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<GameView> viewGame_;
};

#endif // GAMEWIDGET_H
