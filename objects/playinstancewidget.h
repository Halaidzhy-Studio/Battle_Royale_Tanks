#ifndef PLAYINSTANCEWIDGET_H
#define PLAYINSTANCEWIDGET_H

#include <QWidget>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <QGraphicsView>

class PlayInstanceWidget : public QWidget
{
public:
    ~PlayInstanceWidget() = default;
    PlayInstanceWidget();
    PlayInstanceWidget(const std::shared_ptr<GameData>&);
private:
    std::shared_ptr<GameData> gameData_;
    GameWindowInfo gameWindowInfo_;
};

#endif // PLAYINSTANCEWIDGET_H
