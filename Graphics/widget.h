#ifndef WIDGET_H
#define WIDGET_H

class Widget {
public:
    virtual ~Widget() = default;
    virtual void resize(int, int) = 0;
    virtual int getW() = 0;
    virtual int getH() = 0;
    virtual void show() = 0;
    virtual void close() = 0;
};

#endif // WIDGET_H
