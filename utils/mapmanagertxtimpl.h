#ifndef MAPMANAGERTXTIMPL_H
#define MAPMANAGERTXTIMPL_H


#include <utils/mapmanagerimpl.h>


// Легкая и быстрая имплементация парсера файла карты
class MapManagerTxtImpl : public MapManagerImpl
{
public:
    MapManagerTxtImpl() = default;
    MapManagerTxtImpl(const std::shared_ptr<Logger>&);
    ~MapManagerTxtImpl() = default;
    void upload(const std::string &) override;
    std::vector<GeometryRect> getWalls() override;
    int getSceneWidth() override;
    int getSceneHeight() override;
    Coordinate getPlayerPos() override;

private:
    std::shared_ptr<Logger> logger_;
    std::vector<GeometryRect> walls_;
    int sceneWidth_;
    int sceneHeight_;
    Coordinate playerPos_;

    bool isUploaded_;
    void uploadScene(std::stringstream &ss);
    void uploadWall(std::stringstream &ss);
    void uploadPlayerPos(std::stringstream &ss);
    Coordinate readCoord(std::stringstream &ss);
};

#endif // MAPMANAGERTXTIMPL_H
