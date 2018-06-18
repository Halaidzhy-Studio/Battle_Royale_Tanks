#ifndef VEC2D_H
#define VEC2D_H

class Vec2D {
public:
    Vec2D() = default;
    Vec2D(double, double);
    Vec2D(const Vec2D& other) : x_(other.x_), y_(other.y_) {}
    Vec2D&operator=(const Vec2D& other) {
        if (this == &other)
            return *this;
        x_= other.x_;
        y_ = other.y_;

        return *this;
    };
    Vec2D&operator=(Vec2D&&) = default;
    Vec2D(Vec2D&&) = default;

    ~Vec2D() = default;

    void set(double, double);
    double x() const;
    double y() const;
    void operator*=(double);
    void operator*(int);
private:
    double x_;
    double y_;
};

#endif // VEC2D_H
