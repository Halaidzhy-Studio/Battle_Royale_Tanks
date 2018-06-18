#include "mapmanagertxtimpl.h"
#include <fstream>
#include <sstream>

MapManagerTxtImpl::MapManagerTxtImpl(const std::shared_ptr<Logger> &logger) :
    logger_(logger)
{
}

void MapManagerTxtImpl::upload(const std::string & file)
{
    std::ifstream in(file, std::ios_base::in);

    if (!in.is_open()){
        std::string total = "Can't open file: " + file;
        logger_->printLog(total , "[ERROR]");
        return;
    }

    std::string line;
    while (std::getline(in, line)){
        std::stringstream ss(line);
        char objectType;
        ss >> objectType;
        switch (objectType) {
        case 'S':
            uploadScene(ss);
            break;
        case 'W':
            uploadWall(ss);
            break;
        case 'P':
            uploadPlayerPos(ss);
            break;
        default:
            std::string total = "No such object type \'" + std::string(1, objectType) + "\'";
            logger_->printLog(total, "[MapManager]");
            break;
        }
    }

    isUploaded_ = true;
}

void MapManagerTxtImpl::uploadScene(std::stringstream & ss)
{
    char del; ss >> del;
    ss >> sceneWidth_;
    ss >> del;
    ss >> sceneHeight_;
}

void MapManagerTxtImpl::uploadWall(std::stringstream &ss)
{
    Coordinate a = readCoord(ss);
    Coordinate b = readCoord(ss);
    Coordinate c = readCoord(ss);
    Coordinate d = readCoord(ss);

    GeometryRect rect = {a, b, c, d};
    walls_.push_back(rect);
}

void MapManagerTxtImpl::uploadPlayerPos(std::stringstream &ss)
{
    playerPos_ = readCoord(ss);
}

Coordinate MapManagerTxtImpl::readCoord(std::stringstream &ss)
{
    int x = 0;
    int y = 0;

    char del;

    ss >> del;
    ss >> x;
    ss >> del;
    ss >> y;
    ss >> del;

    return Coordinate(x, y, Coordinate::CoordTypes::QT, logger_);
}

std::vector<GeometryRect> MapManagerTxtImpl::getWalls()
{
    return walls_;
}

int MapManagerTxtImpl::getSceneWidth()
{
    if (isUploaded_)
        return sceneWidth_;

    return 0;
}

int MapManagerTxtImpl::getSceneHeight()
{
    if (isUploaded_)
        return sceneHeight_;

    return 0;
}

Coordinate MapManagerTxtImpl::getPlayerPos()
{
    if (isUploaded_)
        return playerPos_;

    return Coordinate(0, 0, Coordinate::CoordTypes::QT, logger_);
}
