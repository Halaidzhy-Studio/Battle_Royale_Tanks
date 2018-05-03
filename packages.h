#ifndef PACKAGES_H
#define PACKAGES_H

#include <stdint.h>
#include "constants.h"

// вспомогательные структуры

struct TankFixedData {
    uint8_t id = 0;                     // id танка
    uint8_t type = 0;                   // тип танка
    uint8_t nameSize = 0;
    const char * name = nullptr;        // имя игрока
};


struct TankVolatileData {
    uint8_t id = 0;                     // координаты танка
    uint16_t centerX = 0;               // координата X центра танка
    uint16_t centerY = 0;               // координата Y центра танка
    uint16_t hp = 0;                    // хп танка
    uint8_t tankRotation = 0;           // угол поворота танка относительно горизонтали
    uint8_t gunRotation = 0;            // угол поворота пушки относительно горизонтали
};

// Клиент отправляет message::INIT
struct ClientInitPackage {
    uint8_t type = 0;                   // тип танка
    uint8_t nameSize = 0;
    const char * name = nullptr;        // имя игрока
};


// Клиент отправляет message::GAME
struct ClientGamePackage {
    TankVolatileData data = 0;
    uint8_t bulletCount = 0;            // количество снарядов игрока, активных на данный момент
    Bullet * bullets = 0;
};


// Сервер отправляет message::INIT
struct ServerInitPackage {
    uint32_t roomId = 0;                // идентификатор комнаты
    uint8_t userId = 0;                 // идентификатор игрока в пределах комнаты
    uint8_t roomSize = 0;               // текущее количество игроков в комнате
    TankFixedData * tanks = nullptr;    // мета-информация о танках в комнате
};


// Сервер отправляет message::GAME
struct ServerGamePackage {
    TankVolatileData * tanks = nullptr; // информация о всех игроках, включая получателя
    Zone zone = 0;                      // информация о зоне
    uint32_t alives = 0;                // битовый массив живых/мертвых игроков
    Bullet * bullets = 0;               // снаряды всех игроков, активные на данный момент
};



struct Tank {
    Tank() {}
    uint16_t centerX = 0;       // координата X центра танка
    uint16_t centerY = 0;       // координата Y центра танка
    uint16_t hp = 0;            // хп танка
    uint8_t tankRotation = 0;   // угол поворота танка относительно горизонтали
    uint8_t gunRotation = 0;    // угол поворота пушки относительно горизонтали
    uint8_t type = 0;           // тип танка - индекс в массиве структур доп. информации о танке
    uint8_t id = 0;             // идентификатор танка в комнате [0, 31]
    char name[MAX_NAME_SIZE];   // имя игрока
};



struct Bullet {
    Bullet() {}
    uint8_t tankId = 0;         // "автор" снаряда
    uint16_t bulletX = 0;       // координата X снаряда
    uint16_t bulletY = 0;       // координата Y снаряда
    uint8_t bulletRotation = 0; // угол между траекторией полета снаряда и горизонталью
};



struct Zone
{
    Zone() {}
    uint16_t leftTopX = 0;      // координата X верхнего левого угла игровой области
    uint16_t leftTopY = 0;      // координата Y верхнего левого угла игровой области
    uint16_t rightBottomX = 0;  // координата X нижнего правого угла игровой области
    uint16_t rightBottomY = 0;  // координата Y нижнего правого угла игровой области
    uint16_t zoneTimer = 0;     // 2^16 миллисекунд должно хватить до конца боя
};



#endif // PACKAGES_H
