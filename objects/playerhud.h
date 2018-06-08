#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include <Graphics/labelitem.h>
#include <Graphics/widget.h>
#include <memory>

class PlayerHUD
{
public:
    PlayerHUD();
    void setViewField(std::shared_ptr<Widget> widget);
private:
    // Сырые указатели, потому что за очистку выполняет Parent виджет
    LabelWidget* hpImage_;
    LabelWidget* hpCount_;
    LabelWidget* bulletImage_;
    LabelWidget* bulletTime_;
    LabelWidget* cicle_;
    LabelWidget* circleTime_;

    void initInterface();
};

#endif // PLAYERHUD_H
