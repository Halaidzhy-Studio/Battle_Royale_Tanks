#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <objects/playerhud.h>
#include <Graphics/graphics.h>
#include <utils/gamedata/gamedata.h>
#include <Graphics/pushbuttonwidget.h>

class PlayWindow : public QObject
{
public:
    PlayWindow() = default;
    PlayWindow(const std::shared_ptr<GameData>&);
    ~PlayWindow() = default;
    void initPlayerHud(const std::shared_ptr<PlayerHUD>&);
    void setSize(int , int);
    void setRenderView(const std::shared_ptr<Graphics>& );
    void show();
signals:
    void exitSignal();
private:
    std::shared_ptr<Widget> widget_;
    std::unique_ptr<PushButtonWidget> exitBTN_;
    GameWindowInfo info_;

    void initInterface();
};

#endif // PLAYWINDOW_H
