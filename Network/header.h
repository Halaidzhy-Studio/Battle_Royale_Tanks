#ifndef HEADER_H
#define HEADER_H

#include <QtGlobal>
#include <QDebug>

struct Header {
    quint32 gameId;
    quint32 roomId;
    quint8 userId;
    quint8 message;
    quint16 sequence;
    quint16 lastAck;
    quint32 prevAcks;

    explicit Header() : gameId(0), roomId(0), userId(0),
                        message(0), sequence(0), lastAck(0),
                        prevAcks(0)
    {
        qDebug() << "Header()";
    }

};


#endif // HEADER_H
