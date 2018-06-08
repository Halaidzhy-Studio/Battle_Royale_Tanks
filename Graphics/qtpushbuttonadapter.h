#ifndef QTPUSHBUTTONADAPTER_H
#define QTPUSHBUTTONADAPTER_H

#include <Graphics/pushbuttonwidget.h>
#include <QPushButton>

class QtPushButtonAdapter : public PushButtonWidget, public QObject
{
    Q_OBJECT
public:
    QtPushButtonAdapter();
    void setGeometry(int, int, int, int) override;
    void setText(const std::string &) override;
    void setCallback(std::function<void ()>) override;
public:
    QPushButton* widget_;
    std::function<void()> callbackFunc_;
};

#endif // QTPUSHBUTTONADAPTER_H
