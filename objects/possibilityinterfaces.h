#ifndef POSSIBILITYINTERFACES_H
#define POSSIBILITYINTERFACES_H

class Moveable{
public:
    virtual void moveF() = 0;
    virtual void moveB() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual ~Moveable() = default;
};

class Turnable{
public:
    virtual void turnR() = 0;
    virtual void turnL() = 0;
    virtual void turnTo(int angle) = 0;
    virtual ~Turnable() = default;
};

class Shootable{
public:
    virtual void shoot() = 0;
};


class Controlable : public virtual Moveable, public virtual Turnable, public virtual Shootable{

};


#endif // POSSIBILITYINTERFACES_H
