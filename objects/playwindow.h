#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <objects/playerhud.h>
#include <Graphics/graphics.h>
#include <utils/gamedata/gamedata.h>
#include <Graphics/pushbuttonwidget.h>

class PlayWindow : public QObject
{
    Q_OBJECT
public:
    PlayWindow() = default;
    PlayWindow(const std::shared_ptr<GameData>&,
               const std::shared_ptr<Graphics>&,
               const std::shared_ptr<Logger>&);
    ~PlayWindow() = default;
    void initPlayerHud(const std::shared_ptr<PlayerHUD>&);
    void setSize(int , int);
    void setRenderView(const std::shared_ptr<Graphics>& );
    void show();
    void initInterface();
signals:
    void exitSignal();
private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Widget> widget_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<PushButtonWidget> exitBTN_;
    GameWindowInfo info_;

    void exit();
};

#endif // PLAYWINDOW_H
