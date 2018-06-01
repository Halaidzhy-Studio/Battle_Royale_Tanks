#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <memory>
#include <QGraphicsView>
#include <QPushButton>
#include <utils/gamedata/gamedata.h>
#include <utils/loggerinterface.h>

class PlaygroundWidget : public QWidget
{
    Q_OBJECT
public:
    PlaygroundWidget(const std::shared_ptr<GameData>& gameData,
               const std::shared_ptr<Logger>& logger, QWidget* parent = 0);
    ~PlaygroundWidget();

    void initInterface();
signals:
    void backToMenuSignal();
private slots:
   void backToMenu();
private:
    QPushButton* backToMenuBTN_;
    GameWindowInfo gameWindowInfo_;

    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Logger> logger_;
};

#endif // GAMEWIDGET_H
