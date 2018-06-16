#ifndef WALL_H
#define WALL_H

#include <objects/igameobject.h>

class Wall : public GameObject
{
public:
    Wall() = default;
    ~Wall() = default;
    void update() override;
};

#endif // WALL_H
