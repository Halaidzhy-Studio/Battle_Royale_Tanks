#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include <Graphics/labelwidget.h>
#include <Graphics/widget.h>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <utils/loggerinterface.h>
#include <utils/data/hudinfostruct.h>

class PlayerHUD
{
public:
    PlayerHUD() = default;
    PlayerHUD(const std::shared_ptr<GameData>&,
              const std::shared_ptr<Logger>&);
    ~PlayerHUD() = default;

    void setViewField(std::shared_ptr<Widget> widget);
private:
    std::shared_ptr<Logger> logger_;
    HudInfo info_;
    std::shared_ptr<LabelWidget> hpImage_;
    std::shared_ptr<LabelWidget> hpCount_;
    std::shared_ptr<LabelWidget> bulletImage_;
    std::shared_ptr<LabelWidget> bulletTime_;
    std::shared_ptr<LabelWidget> circleImage_;
    std::shared_ptr<LabelWidget> circleTime_;

    std::shared_ptr<Widget> viewWidget_;

    void initInterface();
    std::shared_ptr<LabelWidget> create(int, int, int, int, const std::string&);
    std::shared_ptr<LabelWidget> create(int, int, int, int, int);
};

#endif // PLAYERHUD_H
