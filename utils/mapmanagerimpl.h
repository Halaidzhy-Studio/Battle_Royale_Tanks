#ifndef MAPMANAGERIMPL_H
#define MAPMANAGERIMPL_H

#include <vector>
#include <Graphics/geometryrect.h>

class MapManagerImpl{
public:
    virtual ~MapManagerImpl() = default;
    virtual void upload(const std::string&) = 0;
    virtual std::vector<GeometryRect> getWalls() = 0;
    virtual int getSceneWidth() = 0;
    virtual int getSceneHeight() = 0;
    virtual Coordinate getPlayerPos() = 0;
};
#endif // MAPMANAGERIMPL_H
