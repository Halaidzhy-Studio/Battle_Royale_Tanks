#ifndef PLAYINSTANCEWIDGET_H
#define PLAYINSTANCEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <Graphics/graphics.h>

class PlayInstanceWidget : public QWidget
{
    Q_OBJECT
public:
    ~PlayInstanceWidget() = default;
    PlayInstanceWidget();
    PlayInstanceWidget(const std::shared_ptr<GameData>&,
                       const std::shared_ptr<Graphics>&);

signals:
    void exitSignal();

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Graphics> graphics_;
    GameWindowInfo gameWindowInfo_;
    QPushButton* exitBTN_;


    void initInterface();
    void exit();
};

#endif // PLAYINSTANCEWIDGET_H
