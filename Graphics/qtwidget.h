#ifndef QTWIDGET_H
#define QTWIDGET_H

#include <Graphics/widget.h>
#include <QWidget>

class QtWidget : public Widget
{
public:
    QtWidget();
    ~QtWidget() = default;
    void resize(int, int) override;
    int getW() override;
    int getH() override;
    void show() override;
    QWidget* getSourceWidget() const;
private:
    QWidget* widget_;

};

#endif // QTWIDGET_H
