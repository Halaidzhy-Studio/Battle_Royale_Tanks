#include "playwindow.h"
#include <Graphics/qtwidget.h>

PlayWindow::PlayWindow(const std::shared_ptr<GameData> & data) :
    widget_(std::make_shared<QtWidget>())
{
    info_ = data->getGameWindowInfo();
    widget_->resize(info_.width, info_.height);
}

void PlayWindow::initPlayerHud(const std::shared_ptr<PlayerHUD> &)
{

}

void PlayWindow::setSize(int w, int h)
{
    widget_->resize(w, h);
}

void PlayWindow::setRenderView(const std::shared_ptr<Graphics> &graphics)
{
    graphics->setViewParent(widget_.get());
}

void PlayWindow::show()
{
    widget_->show();
}

void PlayWindow::initInterface()
{
    exitBTN_ = std::make_unique<>();
}
