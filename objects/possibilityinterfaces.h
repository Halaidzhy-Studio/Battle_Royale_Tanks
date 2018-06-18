#ifndef POSSIBILITYINTERFACES_H
#define POSSIBILITYINTERFACES_H

class Coordinate;
class Moveable{
public:
    virtual void moveF() = 0;
    virtual void moveB() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual void moveTo(const Coordinate& coord) {}
    virtual void stopMove() {}
    virtual ~Moveable() = default;
};

class Turnable{
public:
    virtual void turnR() = 0;
    virtual void turnL() = 0;
    virtual void turnTo(int angle) = 0;
    virtual void turnTo(double angle) = 0;
    virtual void stopTurn() {}
    virtual ~Turnable() = default;
};

class Shootable{
public:
    virtual void shoot() = 0;
};

class Modifiable{
public:
    virtual void decrease() = 0;
};

class Damageable{
public:
    virtual void hit(int) = 0;
};

#endif // POSSIBILITYINTERFACES_H
