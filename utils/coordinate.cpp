#include "coordinate.h"
#include <utils/logger.h>
#include <cmath>

float Coordinate::qtTophysicsTransformationValue = 0.1;
float Coordinate::qtToserverTransformationValue;
float Coordinate::serverTophysicsTransformationValue;


Coordinate::Coordinate() : x_(0), y_(0), type_(CoordTypes::QT)
{
}

Coordinate::Coordinate(const Coordinate & other) : x_(other.x_), y_(other.y_),
    type_(other.type_)
{
}

Coordinate &Coordinate::toQt()
{

    switch (type_) {
    case CoordTypes::PHYSICSENGINE:

        x_ = x_ / qtTophysicsTransformationValue;
        y_ = y_ / qtTophysicsTransformationValue;

        break;
    case CoordTypes::SERVER:

        x_ = x_ / qtToserverTransformationValue;
        y_ = y_ / qtToserverTransformationValue;

        break;
    default:
        break;
    }

    type_ = CoordTypes::QT;
    return *this;
}

Coordinate &Coordinate::toServer()
{

    switch (type_) {
    case CoordTypes::PHYSICSENGINE:

        x_ = x_ / serverTophysicsTransformationValue;
        y_ = y_ / serverTophysicsTransformationValue;

        break;
    case CoordTypes::QT:

        x_ = x_ * qtToserverTransformationValue;
        y_ = y_ * qtToserverTransformationValue;

        break;
    default:
        break;
    }

    type_ = CoordTypes::SERVER;
    return *this;
}

Coordinate &Coordinate::toPhysicsengine()
{

    switch (type_) {
    case CoordTypes::SERVER:

        x_ = x_ * serverTophysicsTransformationValue;
        y_ = y_ * serverTophysicsTransformationValue;

        break;
    case CoordTypes::QT:

        x_ = x_ * qtTophysicsTransformationValue;
        y_ = y_ * qtTophysicsTransformationValue;

        break;
    default:
        break;
    }

    type_ = CoordTypes::PHYSICSENGINE;
    return *this;
}

double Coordinate::x()
{
    return x_;
}

void Coordinate::setX(double x, const Coordinate::CoordTypes &type)
{
    if (type == type_){
        x_ = x;
    }else {

        switch (type) {
        case CoordTypes::QT:
            if ( type_ == CoordTypes::SERVER){
                x_ = x * qtToserverTransformationValue;
            } else if ( type_ == CoordTypes::PHYSICSENGINE){
                x_ = x * qtTophysicsTransformationValue;
            }
            break;
        case CoordTypes::PHYSICSENGINE:
            if ( type_ == CoordTypes::QT ){
                x_ = x / qtTophysicsTransformationValue;
            } else if ( type == CoordTypes::SERVER ){
                x_ = x / serverTophysicsTransformationValue;
            }
            break;
        case CoordTypes::SERVER:
            if ( type_ == CoordTypes::QT){
                x_ = x / qtToserverTransformationValue;
            } else if ( type == CoordTypes::PHYSICSENGINE ){
                x_ = x * serverTophysicsTransformationValue;
            }
        default:
            logger_->printLog("Cannot convert 'x' coordinate " + std::string(__FUNCTION__), QtLogger::loggerGame);
            break;
        }
    }
}

double Coordinate::y()
{
    return y_;
}

void Coordinate::setY(double y, const Coordinate::CoordTypes &type)
{
    if (type == type_){
        y_ = y;
    }else {

        switch (type) {
        case CoordTypes::QT:
            if ( type_ == CoordTypes::SERVER){
                y_ = y * qtToserverTransformationValue;
            } else if ( type_ == CoordTypes::PHYSICSENGINE){
                y_ = y * qtTophysicsTransformationValue;
            }
            break;
        case CoordTypes::PHYSICSENGINE:
            if ( type_ == CoordTypes::QT ){
                y_ = y / qtTophysicsTransformationValue;
            } else if ( type == CoordTypes::SERVER ){
                y_ = y / serverTophysicsTransformationValue;
            }
            break;
        case CoordTypes::SERVER:
            if ( type_ == CoordTypes::QT){
                y_ = y / qtToserverTransformationValue;
            } else if ( type == CoordTypes::PHYSICSENGINE ){
                y_ = y * serverTophysicsTransformationValue;
            }
        default:
            logger_->printLog("Cannot convert 'y' coordinate " + std::string(__FUNCTION__), QtLogger::loggerGame);
            break;
        }
    }
}

void Coordinate::setQtTophysicsTransformationValue(float value)
{
    qtTophysicsTransformationValue = value;
}

void Coordinate::setQtToserverTransformationValue(float value)
{
    qtToserverTransformationValue = value;
}

void Coordinate::setServerTophysicsTransformationValue(float value)
{
    serverTophysicsTransformationValue = value;
}

double Coordinate::qtConvertToPhysics(double var)
{
    return var * qtTophysicsTransformationValue;
}

double Coordinate::length(Coordinate &a, Coordinate &b)
{
    double length = sqrt((a.x() - b.x() ) * (a.x() - b.x() ) + (a.y() - b.y() ) * (a.y() - b.y() ));
    return length;
}

