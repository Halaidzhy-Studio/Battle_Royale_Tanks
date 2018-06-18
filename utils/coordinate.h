#ifndef COORDINATE_H
#define COORDINATE_H

#include <utils/loggerinterface.h>
#include <memory>

class Coordinate
{
public:
    enum class CoordTypes{
        QT, SERVER, PHYSICSENGINE
    };

    Coordinate();
    Coordinate(const double& x, const double& y, const CoordTypes& type,
               const std::shared_ptr<Logger>& logger):
        x_(x), y_(y), type_(type), logger_(logger) {}

    Coordinate(const Coordinate&);
    Coordinate&operator=(const Coordinate&) = default;
    Coordinate(Coordinate&&) = default;
    Coordinate&operator=(Coordinate&&) = default;

    Coordinate& toQt();
    Coordinate& toServer();
    Coordinate& toPhysicsengine();

    double x();
    void setX(double x, const CoordTypes& type);

    double y();
    void setY(double y, const CoordTypes& type);

    static void setQtTophysicsTransformationValue(float value);

    static void setQtToserverTransformationValue(float value);

    static void setServerTophysicsTransformationValue(float value);

    static double qtConvertToPhysics(double);
    static double length(Coordinate&, Coordinate&);
private:
    double x_;
    double y_;

    CoordTypes type_;

    std::shared_ptr<Logger> logger_;

    // Обратное преобразование - это деление координаты на эти коэффициенты
    // Число на которое нужно уможить, чтобы получить из QT координаты координату в Physics формате
    static float qtTophysicsTransformationValue;

    // Число на которое нужно умножить, чтобы получить из QT координаты координату в Server формате
    static float qtToserverTransformationValue;

    // Число на которое нужно умножить, что получить из Server координаты координату в Physics формате
    static float serverTophysicsTransformationValue;

};

#endif // COORDINATE_H
