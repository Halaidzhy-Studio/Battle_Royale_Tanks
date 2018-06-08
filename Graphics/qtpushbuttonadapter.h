#ifndef QTPUSHBUTTONADAPTER_H
#define QTPUSHBUTTONADAPTER_H

#include <Graphics/pushbuttonwidget.h>
#include <QPushButton>
#include <Graphics/widget.h>
#include <memory>

class QtPushButtonAdapter : public QObject, public PushButtonWidget
{
    Q_OBJECT
public:
    QtPushButtonAdapter();
    ~QtPushButtonAdapter() = default;
    void setGeometry(int, int, int, int) override;
    void setText(const std::string &) override;
    void setCallback(std::function<void ()>) override;
    void setParent(std::shared_ptr<Widget>) override;
    QPushButton* getSourceWidget();
private:
    QPushButton* widget_;
    std::function<void()> callbackFunc_;
private slots:
    void callback();
};

#endif // QTPUSHBUTTONADAPTER_H
