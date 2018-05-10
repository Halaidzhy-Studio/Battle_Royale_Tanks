#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
public:
    enum class CoordTypes{
        QT, SERVER, PHYSICSENGINE
    }

    Coordinate();
    Coordinate(const int& x, const int& y, const CoordTypes& type):
        x_(x), y_(y), type_(type) {}

    Coordinate& toQt();
    Coordinate& toServer();
    Coordinate& toPhysicsengine();

    int x();
    void setX(int x, const CoordTypes& type);

    int y();
    void setY(int y, const CoordTypes& type);

    static void setQtTophysicsTransformationValue(float value);

    static void setQtToserverTransformationValue(float value);

    static void setServerTophysicsTransformationValue(float value);

private:
    int x_;
    int y_;

    CoordTypes type_;

    // Обратное преобразование - это деление координаты на эти коэффициенты
    // Число на которое нужно уможить, чтобы получить из QT координаты координату в Physics формате
    static float qtTophysicsTransformationValue;

    // Число на которое нужно умножить, чтобы получить из QT координаты координату в Server формате
    static float qtToserverTransformationValue;

    // Число на которое нужно умножить, что получить из Server координаты координату в Physics формате
    static float serverTophysicsTransformationValue;

};

#endif // COORDINATE_H
