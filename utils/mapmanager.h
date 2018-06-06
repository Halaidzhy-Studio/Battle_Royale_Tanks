#ifndef MAPMANAGER_H
#define MAPMANAGER_H

// Создает сцену
// Загружает карту из файла
// Добавляет загруженные объекты
//

#include <string>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/logger.h>
#include <objects/wall.h>
#include <builders/director.h>
#include <utils/data/wallinfostruct.h>
#include <sstream>
#include <Graphics/geometryrect.h>
#include <utils/mapmanagerimpl.h>
class MapManager
{
public:
    MapManager();
    MapManager(const std::shared_ptr<Graphics>&,
               const std::shared_ptr<Physics>&,
               const std::shared_ptr<Logger>&);

    void setMapManagerImpl(std::unique_ptr<MapManagerImpl>);
    void upload(const std::string&);
    void create();
private:
    std::string file_;
    std::unique_ptr<MapManagerImpl> impl_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<Logger> logger_;
    std::vector<std::shared_ptr<Wall>> walls_;
    std::vector<GeometryRect> wallsCoords_;

    WallInfo wallInfo_;
    int sceneWidth_;
    int sceneHeight_;
};

#endif // MAPMANAGER_H
