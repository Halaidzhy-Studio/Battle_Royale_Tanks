#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include <Graphics/labelwidget.h>
#include <Graphics/widget.h>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <utils/loggerinterface.h>
#include <utils/data/hudinfostruct.h>
#include <components/circle/logiccirclecomponent.h>
#include <components/body/logicbodycomponent.h>
#include <components/turret/logicturretcomponent.h>

class PlayerHUD
{
public:
    PlayerHUD() = default;
    PlayerHUD(const std::shared_ptr<GameData>&,
              const std::shared_ptr<Logger>&);
    ~PlayerHUD() = default;

    void update();

    void setViewField(std::shared_ptr<Widget> widget);
    void addHudToViewField();
    void setBodyLogic(const std::shared_ptr<LogicBodyComponent> &bodyLogic);
    void setTurretLogic(const std::shared_ptr<LogicTurretComponent> &turretLogic);
    void setCircleLogic(const std::shared_ptr<LogicCircleComponent> &circleLogic);

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

    std::shared_ptr<LogicBodyComponent> bodyLogic_;
    std::shared_ptr<LogicTurretComponent> turretLogic_;
    std::shared_ptr<LogicCircleComponent> circleLogic_;

    void initInterface();
    std::shared_ptr<LabelWidget> create(int, int, int, int, const std::string&);
    std::shared_ptr<LabelWidget> create(int, int, int, int, int);

    void loggerPrintWrapper(const std::string&);
};

#endif // PLAYERHUD_H
