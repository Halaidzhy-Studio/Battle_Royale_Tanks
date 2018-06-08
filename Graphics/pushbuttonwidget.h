#ifndef PUSHBUTTONWIDGET_H
#define PUSHBUTTONWIDGET_H

#include <functional>

class PushButtonWidget{
public:
    ~PushButtonWidget() = default;
    virtual void setGeometry(int, int, int, int) = 0;
    virtual void setText(const std::string&) = 0;
    virtual void setCallback(std::function<void()>) = 0;
};
#endif // PUSHBUTTONWIDGET_H
