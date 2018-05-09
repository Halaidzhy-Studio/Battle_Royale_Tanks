#ifndef ENGINEQT_H
#define ENGINEQT_H

#include <engine.h>
#include <QApplication>
#include <utils/loggerinterface.h>
#include <game.h>

class EngineQT : public Engine, public QApplication
{
public:
    EngineQT() = delete;
    EngineQT(const EngineQT&) = delete;
    EngineQT& operator=(const EngineQT&) = delete;
    EngineQT(int& argc, char **argv) : QApplication(argc, argv) {}

    ~EngineQT() = default;
    // Engine interface
    void setGameData(const std::shared_ptr<GameData> & gameData) override;
    void setLogger(const std::shared_ptr<LoggerInterface> & logger) override;
    int startGame() override;

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Game> game_;

};

#endif // ENGINEQT_H
