#ifndef PACKAGES_H
#define PACKAGES_H

#include <QtGlobal>

// в таком виде данные хранятся в ClientData

const quint8 MAX_PLAYERS = 32;

struct Tank {
    quint16 centerX = 0;        // координата X центра танка
    quint16 centerY = 0;        // координата Y центра танка
    quint16 hp = 0;             // хп танка
    quint8 tankRotation = 0;    // угол поворота танка относительно горизонтали
    quint8 gunRotation = 0;     // угол поворота пушки относительно горизонтали
    quint8 type = 0;            // тип танка - индекс в массиве структур доп. информации о танке
    quint8 id = 0;              // идентификатор танка в комнате [0, 31]
    QString name;               // имя игрока
};


struct Bullet {
    quint8 tankId = 0;          // "автор" снаряда
    quint16 bulletX = 0;        // координата X снаряда
    quint16 bulletY = 0;        // координата Y снаряда
    quint8 bulletRotation = 0;  // угол между траекторией полета снаряда и горизонталью
};

struct Zone {
    quint16 leftTopX;           // координата X верхнего левого угла игровой области
    quint16 leftTopY;           // координата Y верхнего левого угла игровой области
    quint16 rightBottomX;       // координата X нижнего правого угла игровой области
    quint16 rightBottomY;       // координата Y нижнего правого угла игровой области
    quint16 zoneTimer;          // 2^16 миллисекунд должно хватить до конца боя
};




// вспомогательные структуры

struct TankFixedData {
    quint8 id = 0;              // id танка
    quint8 type = 0;            // тип танка
    quint8 nameSize = 0;
    const char * name;          // имя игрока
};


struct TankVolatileData {
    quint8 id = 0;              // координаты танка
    quint16 centerX = 0;        // координата X центра танка
    quint16 centerY = 0;        // координата Y центра танка
    quint16 hp = 0;             // хп танка
    quint8 tankRotation = 0;    // угол поворота танка относительно горизонтали
    quint8 gunRotation = 0;     // угол поворота пушки относительно горизонтали
};



// в таком виде данные ходят по сети


// Клиент отправляет message::INIT
struct ClientInitPackage {
    quint8 type = 0;            // тип танка
    quint8 nameSize = 0;
    const char * name;          // имя игрока
};


// Клиент отправляет message::GAME
struct ClientGamePackage {
    TankVolatileData data;
    quint8 bulletCount;         // количество снарядов игрока, активных на данный момент
    Bullet * bullets;
};


// Сервер отправляет message::INIT
struct ServerInitPackage {
    quint32 roomId;              // идентификатор комнаты
    quint8 userId;              // идентификатор игрока в пределах комнаты
    quint8 roomSize;            // текущее количество игроков в комнате
    TankFixedData * tanks;      // мета-информация о танках в комнате
};


// Сервер отправляет message::GAME
struct ServerGamePackage {
    TankVolatileData * tanks;   // информация о всех игроках, включая получателя
    Zone zone;                  // информация о зоне
    quint32 alives;             // битовый массив живых/мертвых игроков
    Bullet * bullets;           // снаряды всех игроков, активные на данный момент
};


// Сообщения от клиента и сервера типа message::CLOSE
// заканчивают сетевое взаимодействие игрока с комнатой
// поэтому разбирать его тело нет необходимости
// TO DO:
// в теле пакета от сервера возвращать результаты игры



#endif // PACKAGES_H
