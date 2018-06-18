#include "vec2d.h"

Vec2D::Vec2D(double x, double y) : x_(x), y_(y)
{

}

void Vec2D::set(double x, double y)
{
    x_ = x;
    y_ = y;
}

double Vec2D::x() const
{
    return x_;
}

double Vec2D::y() const
{
    return y_;
}

void Vec2D::operator*=(double val)
{
    x_*= val; y_*=val;
}

void Vec2D::operator*(int val)
{
    x_*= val; y_*=val;
}
