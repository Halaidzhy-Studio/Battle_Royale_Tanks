#ifndef QTLABELADAPTER_H
#define QTLABELADAPTER_H

#include <Graphics/labelwidget.h>
#include <utils/loggerinterface.h>
#include <QLabel>
#include <memory>

class QtLabelAdapter : public LabelWidget
{
public:
    QtLabelAdapter() = default;
    QtLabelAdapter(const std::shared_ptr<Logger>&);
    ~QtLabelAdapter() = default;

    void setGeometry(int, int, int, int) override;
    void setText(const std::string &) override;
    void setTexture(int, int, const std::string &) override;
    void setParentWidget(std::shared_ptr<Widget>) override;
    QLabel* getSourceWidget();
private:
    std::shared_ptr<Logger> logger_;
    QLabel* widget_;
};

#endif // QTLABELADAPTER_H
