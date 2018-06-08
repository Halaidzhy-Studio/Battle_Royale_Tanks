#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <Graphics/widget.h>
#include <string>
class LabelWidget {
public:
    virtual ~LabelWidget() = default;
    virtual void setGeometry(int, int, int, int) = 0;
    virtual void setText(const std::string&) = 0;
    virtual void setTexture(int, int, const std::string&) = 0;
    virtual void setParentWidget(Widget*) = 0;
};

#endif // LABELWIDGET_H
