#ifndef MESSAGES_H
#define MESSAGES_H

namespace message {
    enum message {
        INIT = 1,   // от клиента: "пакет инициализации игрока", от сервера: "пакет инициализации всех игроков"
        GAME,       // от клиента: "игровой пакет игрока", от сервера: "игровой пакет всей игры"
        CLOSE       // от клиента: "отключить клиента", от сервера: "клиент отключен"
    };
}

#endif // MESSAGES_H
