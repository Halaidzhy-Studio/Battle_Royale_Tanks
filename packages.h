/* Чтобы полностью абстрагировать тебя (Влад) от сети, я напишу класс PackageAnalyzer,
 * который распарсит данные, упакованные для передачи по сети в удобную структуру.
 * Тебе нужно будет "уметь" использовать эту структуру - это твой основной источник информации.
 * И запаковывать свои данные в эту же структуру.
 * По полям структуры сам пройдись взглядом, может я что-то упустил.
 * Обсудим.
 * P.S. Весь сетевой оверхед, типа id игры, id комнаты, номер пакета, timestamp и т.д.
 * ты здесь не увидишь, вся эта инфа остается только у меня. (c) Андрей
 * */


#ifndef PACKAGES_H
#define PACKAGES_H

#include <QObject>
#include <QBitArray>
#include <QTime>


enum VehicleType; // типы техники, это заглушка, сам ее переопределишь когда-нибудь

// этот пакет формируется в начале игры
struct InitialPackage
{
    struct TankDetails {
        QString playerName; // имя игрока
        VehicleType type; // тип техники
    };

    QTime time; // время боя
    TankDetails tanks[32]; // доп. информация о танках
};


// эти пакеты приходят регулярно
struct UsualPackage
{
    struct TankInformation {
        quint8 tankId = 0; // идентификатор танка в комнате [0, 31]
        quint8 tankRotation = 0; // угол поворота танка относительно горизонтали
        quint8 gunRotation = 0; // угол поворота пушки относительно горизонтали
        quint16 centerX = 0; // координата X центра танка
        quint16 centerY = 0; // координата Y центра танка
        quint16 hp = 0; // хп танка
    };

    struct BulletInformation {
        quint8 bulletRotation = 0; // угол между траекторией полета снаряда и горизонталью
        quint16 bulletX = 0; // координата X снаряда
        quint16 bulletY = 0; // координата Y снаряда
    };

    quint16 leftTopX; // координата X верхнего левого угла игровой области
    quint16 leftTopY; // координата Y верхнего левого угла игровой области
    quint16 rightBottomX; // координата X нижнего правого угла игровой области
    quint16 rightBottomY; // координата Y нижнего правого угла игровой области

    TankInformation tanks[32]; // информация о всех танках (32 - максимальное кол-во игроков)
    QBitArray alives; // 32 бита, установленных в 1, если танк живой
    QList<BulletInformation> bullets;
};







#endif // PACKAGES_H
