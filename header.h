#ifndef HEADER_H
#define HEADER_H

#include <QtGlobal>
#include <QDataStream>
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

QDataStream& operator<<(QDataStream& out, const Header& h) {
    out << h.gameId << h.roomId << h.userId
        << h.message << h.sequence << h.lastAck
        << h.prevAcks;

    return out;
}

QDataStream& operator>>(QDataStream& in, Header& h) {
    in >> h.gameId >> h.roomId >> h.userId
       >> h.message >> h.sequence >> h.lastAck
       >> h.prevAcks;

    return in;
}


#endif // HEADER_H
